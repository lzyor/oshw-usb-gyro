#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "sdcc-short.h"
#include "stc8h.h"

#define CONFIG_FOSC 24000000

#define RGB_R P33
#define RGB_G P34
#define RGB_B P17
#define SW_DL P32
#define SW_RST P54
#define CS_SD P35
#define CS_GY P16
#define GY_INT1 P10
#define GY_INT2 P11

#define RGB(r, g, b) \
    RGB_R = r;       \
    RGB_G = g;       \
    RGB_B = b

// GPIO

void init_gpio();

// UART

void init_uart();
int putchar(int c);

inline uint8_t uart_read() {
    uint8_t c;
    while (!RI)
        ;
    c = SBUF;
    RI = 0;
    return c;
}

inline void uart_write(uint8_t c) {
    SBUF = c;
    while (TI == 0)
        ;
    TI = 0;
}

// RGB

void init_rgb();
void rgb_set(uint8_t r, uint8_t g, uint8_t b);

inline void rgb_stop() {
    PWMA_ENO = 0;
}

inline void rgb_start() {
    PWMA_ENO = 0b01010001;
}

// SPI

void init_spi();

inline uint8_t spi_swap(uint8_t c) {
    SPDAT = c;
    while (!(SPSTAT & 0x80))
        ;
    SPSTAT = 0xc0;
    return SPDAT;
}

// SYS

void init_sys();
void init_tm4();
void sys_reset();

void delay_ms(uint16_t __data ms);

void isr_tm4() interrupt(TMR4_VECTOR) using(1);
void isr_int0() interrupt(INT0_VECTOR) using(1);

inline void sys_reset_to_isp() {
    IAP_CONTR = 0x40;
    IAP_CONTR = 0x60;
}