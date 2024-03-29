use hidapi::{HidApi, HidDevice};

// struct from device
#[derive(Debug, Clone, Copy, Default)]
#[repr(C, packed)]
struct HidReport {
    pub tempstamp: u16,
    pub temperature: i16,
    pub accel: [i16; 3],
    pub gyro: [i16; 3],
}

// map and filter data
#[derive(Debug, Clone, Copy, Default)]
pub struct FilterHidReport {
    pub tempstamp: u32,
    pub temperature: f32,
    pub accel: [f32; 3],
    pub gyro: [f32; 3],
    pub angles: [f32; 3],
}

// handle the device
#[derive(Debug)]
pub struct Gyro {
    device: HidDevice,
    report: HidReport,
    angles: [f32; 3],
    alpha: f32,
    dt: f32,
}

impl Gyro {
    pub fn new() -> Self {
        let api = HidApi::new().unwrap();
        let device = api.open(0x34bf, 0xff03).unwrap();
        device.set_blocking_mode(false).unwrap();
        let mut report = HidReport::default();
        let report_buf = unsafe {
            std::slice::from_raw_parts_mut(
                &mut report as *mut HidReport as *mut u8,
                std::mem::size_of::<HidReport>(),
            )
        };

        // set up device, send power on command
        println!("{:?}", device.get_product_string().unwrap());
        report_buf[0] = 0x01; // enable setting
        report_buf[1] = 0x01; // power on
        device.write(&report_buf).unwrap();
        Self {
            device,
            report,
            angles: [0.0; 3],
            alpha: 0.998,
            dt: 0.001,
        }
    }

    pub fn read(&mut self) -> FilterHidReport {
        let pi = std::f32::consts::PI;
        let mut report = unsafe {
            std::slice::from_raw_parts_mut(
                &mut self.report as *mut HidReport as *mut u8,
                std::mem::size_of::<HidReport>(),
            )
        };
        self.device.read(&mut report).unwrap();
        let report = unsafe { &*report.as_ptr().cast::<HidReport>() };

        // map values, defined by frimware
        let accel = [
            report.accel[0] as f32 * 4.0 / 32768.0,
            report.accel[1] as f32 * 4.0 / 32768.0,
            report.accel[2] as f32 * 4.0 / 32768.0,
        ];
        let gyro = [
            report.gyro[0] as f32 * 2000.0 / 32768.0,
            report.gyro[1] as f32 * 2000.0 / 32768.0,
            report.gyro[2] as f32 * 2000.0 / 32768.0,
        ];
        let roll = f32::atan2(accel[1], accel[2]);
        let pitch = f32::atan2(
            -accel[0],
            f32::sqrt(accel[1] * accel[1] + accel[2] * accel[2]),
        );
        self.angles[0] =
            (self.angles[0] + gyro[0] * self.dt) * self.alpha + roll * (1.0 - self.alpha);
        self.angles[1] =
            (self.angles[1] + gyro[1] * self.dt) * self.alpha + pitch * (1.0 - self.alpha);
        self.angles[2] = (self.angles[2] + gyro[2] * self.dt + 2.0 * pi) % (2.0 * pi);
        FilterHidReport {
            tempstamp: report.tempstamp as u32,
            temperature: report.temperature as f32 / 256.0 + 25.0,
            accel,
            gyro,
            angles: self.angles,
        }
    }
}
