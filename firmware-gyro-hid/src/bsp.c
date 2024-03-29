
#include "bsp.h"

void init_gpio() {
    P0M1 = 0xff;
    P0M0 = 0x00;
    P1M1 = 0b00000100;
    P1M0 = 0b11000000; // RGB:P17 CS_GY:P16 SPI:P13,P14,P15 GY_INT:P10,P11
    P2M1 = 0xff;
    P2M0 = 0x00;
    P3M1 = 0b00000011;
    P3M0 = 0b00111000; // USB:P30,P31 SW_DL:P32 RGB:P33,P34 CS_SD:P35 UART1:P36,P37
    P4M1 = 0xff;
    P4M0 = 0x00;
    P5M1 = 0b11101111;
    P5M0 = 0b00000000; // SW_RST:P54

    // P1 = 0b11111111;
    // P3 = 0b11111100;

    P1 = 0xff;
    RGB_R = 1;
    RGB_G = 1;
    RGB_B = 1;
    CS_SD = 1;
    CS_GY = 1;
    GY_INT1 = 1;
    GY_INT2 = 1;

    // PortSwitch
    P_SW1 = 0b01000000; // UART1/USART1: RxD(P3.6), TxD(P3.7)
}

// 115200bps@24.000MHz
void init_uart() {
    SCON = 0x50;  // 8位数据,可变波特率
    AUXR |= 0x40; // 定时器时钟1T模式
    AUXR &= 0xFE; // 串口1选择定时器1为波特率发生器
    TMOD &= 0x0F; // 设置定时器模式
    TL1 = 0xCC;   // 设置定时初始值
    TH1 = 0xFF;   // 设置定时初始值
    ET1 = 0;      // 禁止定时器中断
    TR1 = 1;      // 定时器1开始计时
}

int putchar(int c) {
    SBUF = c;
    while (TI == 0)
        ;
    TI = 0;
    return c;
}

/////

void init_rgb() {
    RGB(1, 1, 1);
    PWMB_PS = 0b01010101; // PWM 8:P34 7:P33 5:P17
    // PWMB_ENO = 0b01010001; // EN 8 7 5

    PWMB_PSCRH = 648 >> 8;
    PWMB_PSCRL = 648 & 0xff;
    PWMB_ARRH = 0;
    PWMB_ARRL = 0xff;

    PWMB_CCER1 = 0;
    PWMB_CCER2 = 0;

    PWMB_CCR5H = 0;
    PWMB_CCR5L = 0;
    PWMB_CCR7H = 0;
    PWMB_CCR7L = 0;
    PWMB_CCR8H = 0;
    PWMB_CCR8L = 0;

    PWMB_CCER1 = 0x01;
    PWMB_CCER2 = 0x11;
    PWMB_CCMR1 = 0b01110000;
    PWMB_CCMR3 = 0b01110000;
    PWMB_CCMR4 = 0b01110000;

    PWMB_BKR = 0x80;
    PWMB_CR1 = 0b00010001;
}

void rgb_set(uint8_t r, uint8_t g, uint8_t b) {
    PWMB_CCR5L = r;
    PWMB_CCR8L = g;
    PWMB_CCR7L = b;
    if (r == 0 && g == 0 && b == 0) {
        RGB(0, 0, 0);
        rgb_stop();
    } else {
        rgb_start();
    }
}

void init_spi() {
    SPCTL = 0x50;
    SPSTAT = 0xc0;
}

//////

void delay_ms(uint16_t __data ms) {
    uint16_t i;
    do {
        i = CONFIG_FOSC / 9000; // 9T
        while (--i)
            ;
    } while (--ms);
}

// 5毫秒@24.000MHz
void init_tm4() {
    T4T3M &= 0xDF; // 定时器时钟12T模式
    T4L = 0xF0;    // 设置定时初始值
    T4H = 0xD8;    // 设置定时初始值
    T4T3M |= 0x80; // 定时器4开始计时
}

void init_sys() {
    P_SW2 |= 0x80; // 使能XFR
    init_gpio();
    init_spi();
    // usb_init();
    init_uart();
    // init_rgb();
    init_tm4();
    IP = 0b00000001;
    IPH = 0b00000001;
    IP2 = 0b00000000;
    IP2H = 0b10000000;
    IE2 |= 0b01000000; // 允许定时器4中断
    EX0 = 1;
    EA = 1;
}

void sys_reset() {
    rgb_stop();
    RGB(1, 1, 0);
    USBCON = 0x00;
    delay_ms(100);
    sys_reset_to_isp();
}

void isr_tm4() interrupt(TMR4_VECTOR) using(1) {
    static uint8_t rst_btn_cnt = 0;
    if (SW_DL == 0) {
        rst_btn_cnt += 1;
    } else {
        rst_btn_cnt = 0;
    }
    if (rst_btn_cnt > 10) {
        sys_reset();
        rst_btn_cnt = 0;
    }
}

void isr_int0() interrupt(INT0_VECTOR) using(1) {
    sys_reset();
}
