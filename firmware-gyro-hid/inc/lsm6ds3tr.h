#pragma once

#include "sdcc-short.h"
#include "stc8h.h"
#include <stdint.h>

#include "bsp.h"

#define LSM6DS3TR_WHO_AM_I 0x6A

#define L6R_FUNC_CFG_ACCESS 0x01
#define L6R_SENSOR_SYNC_TIME_FRAME 0x04
#define L6R_SENSOR_SYNC_RES_RATIO 0x05
#define L6R_FIFO_CTRL1 0x06
#define L6R_FIFO_CTRL2 0x07
#define L6R_FIFO_CTRL3 0x08
#define L6R_FIFO_CTRL4 0x09
#define L6R_FIFO_CTRL5 0x0A
#define L6R_DRDY_PULSE_CFG_G 0x0B
#define L6R_INT1_CTRL 0x0D
#define L6R_INT2_CTRL 0x0E
#define L6R_WHO_AM_I 0x0F
#define L6R_CTRL1_XL 0x10
#define L6R_CTRL2_G 0x11
#define L6R_CTRL3_C 0x12
#define L6R_CTRL4_C 0x13
#define L6R_CTRL5_C 0x14
#define L6R_CTRL6_C 0x15
#define L6R_CTRL7_G 0x16
#define L6R_CTRL8_XL 0x17
#define L6R_CTRL9_XL 0x18
#define L6R_CTRL10_C 0x19
#define L6R_MASTER_CONFIG 0x1A
#define L6R_WAKE_UP_SRC 0x1B
#define L6R_TAP_SRC 0x1C
#define L6R_D6D_SRC 0x1D
#define L6R_STATUS_REG 0x1E
#define L6R_OUT_TEMP_L 0x20
#define L6R_OUT_TEMP_H 0x21
#define L6R_OUTX_L_G 0x22
#define L6R_OUTX_H_G 0x23
#define L6R_OUTY_L_G 0x24
#define L6R_OUTY_H_G 0x25
#define L6R_OUTZ_L_G 0x26
#define L6R_OUTZ_H_G 0x27
#define L6R_OUTX_L_XL 0x28
#define L6R_OUTX_H_XL 0x29
#define L6R_OUTY_L_XL 0x2A
#define L6R_OUTY_H_XL 0x2B
#define L6R_OUTZ_L_XL 0x2C
#define L6R_OUTZ_H_XL 0x2D
#define L6R_SENSORHUB1_REG 0x2E
#define L6R_SENSORHUB2_REG 0x2F
#define L6R_SENSORHUB3_REG 0x30
#define L6R_SENSORHUB4_REG 0x31
#define L6R_SENSORHUB5_REG 0x32
#define L6R_SENSORHUB6_REG 0x33
#define L6R_SENSORHUB7_REG 0x34
#define L6R_SENSORHUB8_REG 0x35
#define L6R_SENSORHUB9_REG 0x36
#define L6R_SENSORHUB10_REG 0x37
#define L6R_SENSORHUB11_REG 0x38
#define L6R_SENSORHUB12_REG 0x39
#define L6R_FIFO_STATUS1 0x3A
#define L6R_FIFO_STATUS2 0x3B
#define L6R_FIFO_STATUS3 0x3C
#define L6R_FIFO_STATUS4 0x3D
#define L6R_FIFO_DATA_OUT_L 0x3E
#define L6R_FIFO_DATA_OUT_H 0x3F
#define L6R_TIMESTAMP0_REG 0x40
#define L6R_TIMESTAMP1_REG 0x41
#define L6R_TIMESTAMP2_REG 0x42
#define L6R_STEP_TIMESTAMP_L 0x49
#define L6R_STEP_TIMESTAMP_H 0x4A
#define L6R_STEP_COUNTER_L 0x4B
#define L6R_STEP_COUNTER_H 0x4C
#define L6R_SENSORHUB13_REG 0x4D
#define L6R_SENSORHUB14_REG 0x4E
#define L6R_SENSORHUB15_REG 0x4F
#define L6R_SENSORHUB16_REG 0x50
#define L6R_SENSORHUB17_REG 0x51
#define L6R_SENSORHUB18_REG 0x52
#define L6R_FUNC_SRC1 0x53
#define L6R_FUNC_SRC2 0x54
#define L6R_WRIST_TILT_IA 0x55
#define L6R_TAP_CFG 0x58
#define L6R_TAP_THS_6D 0x59
#define L6R_INT_DUR2 0x5A
#define L6R_WAKE_UP_THS 0x5B
#define L6R_WAKE_UP_DUR 0x5C
#define L6R_FREE_FALL 0x5D
#define L6R_MD1_CFG 0x5E
#define L6R_MD2_CFG 0x5F
#define L6R_MASTER_CMD_CODE 0x60
#define L6R_SENS_SYNC_SPI_ERROR_CODE 0x61
#define L6R_OUT_MAG_RAW_X_L 0x66
#define L6R_OUT_MAG_RAW_X_H 0x67
#define L6R_OUT_MAG_RAW_Y_L 0x68
#define L6R_OUT_MAG_RAW_Y_H 0x69
#define L6R_OUT_MAG_RAW_Z_L 0x6A
#define L6R_OUT_MAG_RAW_Z_H 0x6B
#define L6R_X_OFS_USR 0x73
#define L6R_Y_OFS_USR 0x74
#define L6R_Z_OFS_USR 0x75

inline void lsm6ds3tr_reg_write(uint8_t reg, uint8_t val) {
    CS_GY = 0;
    spi_swap(reg);
    spi_swap(val);
    CS_GY = 1;
}

inline uint8_t lsm6ds3tr_reg_read(uint8_t reg) {
    CS_GY = 0;
    spi_swap(0x80 | reg);
    uint8_t val = spi_swap(0xff);
    CS_GY = 1;
    return val;
}

typedef struct {
    uint16_t x;
    uint16_t y;
    uint16_t z;
} vec3_t;

bool lsm6ds3tr_check();
void lsm6ds3tr_start();
void lsm6ds3tr_stop();
void lsm6ds3tr_accel_read(vec3_t *val);
bool lsm6ds3tr_accel_available();
void lsm6ds3tr_gyro_read(vec3_t *val);
bool lsm6ds3tr_gyro_available();
void lsm6ds3tr_temp_read(uint16_t *val);
bool lsm6ds3tr_temp_available();
