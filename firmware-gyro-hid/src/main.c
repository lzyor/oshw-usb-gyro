
#include "bsp.h"
#include "usb.h"

#include "lsm6ds3tr.h"
#include "usb-config.h"
#include "usb-hid.h"

uint16_t sys_count = 0;
bool sys_enable = false;

// 1毫秒@24.000MHz
void init_tm3() {
    T4T3M &= 0xFD; // 定时器时钟12T模式
    T3L = 0x30;    // 设置定时初始值
    T3H = 0xF8;    // 设置定时初始值
    T4T3M |= 0x08; // 定时器3开始计时

    IE2 |= 0x20; // 允许定时器3中断
}

void isr_tm3() interrupt(TMR3_VECTOR) using(3) {
    sys_count += 1;
}

void usb_class_out() {
    if (usb_bulk_intr_out(hidbuf, 1) == 16) {
        if (hidbuf[0] & 0x01) {
            if (hidbuf[1] & 0x01) {
                if (!sys_enable) {
                    sys_enable = true;
                    lsm6ds3tr_start();
                }
            } else {
                if (sys_enable) {
                    sys_enable = false;
                    lsm6ds3tr_stop();
                }
            }
        }
        if (hidbuf[2] & 0x01) {
            RGB_R = !(hidbuf[3] & 0x01);
            RGB_G = !(hidbuf[4] & 0x01);
            RGB_B = !(hidbuf[5] & 0x01);
        }
    }
}

struct hid_report {
    uint16_t tempstamp;
    uint16_t temperature;
    vec3_t accel;
    vec3_t gyro;
} hid_report;

void usb_class_in() {
    if (DeviceState != DEVSTATE_CONFIGURED) return;

    struct hid_report *r = (struct hid_report *)hidbuf;
    r->tempstamp = sys_count;
    lsm6ds3tr_temp_read(&(r->temperature));
    lsm6ds3tr_accel_read(&(r->accel));
    lsm6ds3tr_gyro_read(&(r->gyro));

    IE2 &= ~0x80; // EUSB = 0;
    usb_write_reg(INDEX, 1);
    for (uint8_t i = 0; i < 16; i++) {
        usb_write_reg(FIFO1, hidbuf[i]);
    }
    usb_write_reg(INCSR1, INIPRDY);
    IE2 |= 0x80; // EUSB = 1;
}

void main() {
    init_sys();
    usb_init();

    init_tm3();
    sys_count = 0;

    if (lsm6ds3tr_check()) {
        RGB(1, 0, 1);
        delay_ms(1000);
        RGB(1, 1, 1);
    } else {
        RGB(0, 1, 1);
    }

    uint16_t last_count = 0;
    while (1) {
        if (sys_enable &&
            (last_count != sys_count) &&
            (sys_count % 10 == 0)) {
            last_count = sys_count;
            usb_class_in();
        }
    }
}
