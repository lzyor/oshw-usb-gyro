#include "lsm6ds3tr.h"

bool lsm6ds3tr_check() {
    CS_GY = 0;
    spi_swap(0x80 | L6R_WHO_AM_I);
    uint8_t who_am_i = spi_swap(0xff);
    CS_GY = 1;
    return (who_am_i == LSM6DS3TR_WHO_AM_I);
}

void lsm6ds3tr_start() {
    // set the gyroscope control register to work at 104 Hz, 2000 dps and in bypass mode
    lsm6ds3tr_reg_write(L6R_CTRL2_G, 0x4c);
    // set the Accelerometer control register to work at 104 Hz, 4 g,and in bypass mode and enable ODR/4
    lsm6ds3tr_reg_write(L6R_CTRL1_XL, 0x4A);
    // set gyroscope power mode to high performance and bandwidth to 16 MHz
    lsm6ds3tr_reg_write(L6R_CTRL7_G, 0x00);
    // Set the ODR config register to ODR/4
    lsm6ds3tr_reg_write(L6R_CTRL8_XL, 0x09);
}

void lsm6ds3tr_stop() {
    lsm6ds3tr_reg_write(L6R_CTRL2_G, 0x00);
    lsm6ds3tr_reg_write(L6R_CTRL1_XL, 0x00);
}

// a = accel * 4 / 32768
void lsm6ds3tr_accel_read(vec3_t *val) {
    uint8_t *buf = (uint8_t *)val;
    CS_GY = 0;
    spi_swap(0x80 | L6R_OUTX_L_XL);
    buf[0] = spi_swap(0xff); // x
    buf[1] = spi_swap(0xff);
    buf[2] = spi_swap(0xff); // y
    buf[3] = spi_swap(0xff);
    buf[4] = spi_swap(0xff); // z
    buf[5] = spi_swap(0xff);
    CS_GY = 1;
}

bool lsm6ds3tr_accel_available() {
    return lsm6ds3tr_reg_read(L6R_STATUS_REG) & 0x01;
}

// g = gyro * 2000 / 32768
void lsm6ds3tr_gyro_read(vec3_t *val) {
    uint8_t *buf = (uint8_t *)val;
    CS_GY = 0;
    spi_swap(0x80 | L6R_OUTX_L_G);
    buf[0] = spi_swap(0xff); // x
    buf[1] = spi_swap(0xff);
    buf[2] = spi_swap(0xff); // y
    buf[3] = spi_swap(0xff);
    buf[4] = spi_swap(0xff); // z
    buf[5] = spi_swap(0xff);
    CS_GY = 1;
}

bool lsm6ds3tr_gyro_available() {
    return lsm6ds3tr_reg_read(L6R_STATUS_REG) & 0x02;
}

// C = val / 256 + 25
void lsm6ds3tr_temp_read(uint16_t *val) {
    uint8_t *buf = (uint8_t *)val;
    CS_GY = 0;
    spi_swap(0x80 | L6R_OUT_TEMP_L);
    buf[0] = spi_swap(0xff);
    buf[1] = spi_swap(0xff);
    CS_GY = 1;
}

bool lsm6ds3tr_temp_available() {
    return lsm6ds3tr_reg_read(L6R_STATUS_REG) & 0x04;
}
