#ifndef __STC8H_H__
#define __STC8H_H__

/////////////////////////////////////////////////

//包含本头文件后,不用另外再包含"REG51.H"

__sfr       __at(0x80)      P0;
    __sbit  __at(0x80)      P00;
    __sbit  __at(0x81)      P01;
    __sbit  __at(0x82)      P02;
    __sbit  __at(0x83)      P03;
    __sbit  __at(0x84)      P04;
    __sbit  __at(0x85)      P05;
    __sbit  __at(0x86)      P06;
    __sbit  __at(0x87)      P07;

__sfr       __at(0x81)      SP;
__sfr       __at(0x82)      DPL;
__sfr       __at(0x83)      DPH;
__sfr       __at(0x84)      S4CON;
__sfr       __at(0x85)      S4BUF;
__sfr       __at(0x87)      PCON;

__sfr       __at(0x88)      TCON;
    __sbit  __at(0x8F)      TF1;
    __sbit  __at(0x8E)      TR1;
    __sbit  __at(0x8D)      TF0;
    __sbit  __at(0x8C)      TR0;
    __sbit  __at(0x8B)      IE1;
    __sbit  __at(0x8A)      IT1;
    __sbit  __at(0x89)      IE0;
    __sbit  __at(0x88)      IT0;

__sfr       __at(0x89)      TMOD;
__sfr       __at(0x8A)      TL0;
__sfr       __at(0x8B)      TL1;
__sfr       __at(0x8C)      TH0;
__sfr       __at(0x8D)      TH1;
__sfr       __at(0x8E)      AUXR;
__sfr       __at(0x8F)      INTCLKO;

__sfr       __at(0x90)      P1;
    __sbit  __at(0x90)      P10;
    __sbit  __at(0x91)      P11;
    __sbit  __at(0x92)      P12;
    __sbit  __at(0x93)      P13;
    __sbit  __at(0x94)      P14;
    __sbit  __at(0x95)      P15;
    __sbit  __at(0x96)      P16;
    __sbit  __at(0x97)      P17;

__sfr       __at(0x91)      P1M1;
__sfr       __at(0x92)      P1M0;
__sfr       __at(0x93)      P0M1;
__sfr       __at(0x94)      P0M0;
__sfr       __at(0x95)      P2M1;
__sfr       __at(0x96)      P2M0;

__sfr       __at(0x98)      SCON;
    __sbit  __at(0x9F)      SM0;
    __sbit  __at(0x9E)      SM1;
    __sbit  __at(0x9D)      SM2;
    __sbit  __at(0x9C)      REN;
    __sbit  __at(0x9B)      TB8;
    __sbit  __at(0x9A)      RB8;
    __sbit  __at(0x99)      TI;
    __sbit  __at(0x98)      RI;

__sfr       __at(0x99)      SBUF;
__sfr       __at(0x9A)      S2CON;
__sfr       __at(0x9B)      S2BUF;
__sfr       __at(0x9D)      IRCBAND;
__sfr       __at(0x9E)      LIRTRIM;
__sfr       __at(0x9F)      IRTRIM;

__sfr       __at(0xA0)      P2;
    __sbit  __at(0xA0)      P20;
    __sbit  __at(0xA1)      P21;
    __sbit  __at(0xA2)      P22;
    __sbit  __at(0xA3)      P23;
    __sbit  __at(0xA4)      P24;
    __sbit  __at(0xA5)      P25;
    __sbit  __at(0xA6)      P26;
    __sbit  __at(0xA7)      P27;

__sfr       __at(0xA2)      P_SW1;

__sfr       __at(0xA8)      IE;
    __sbit  __at(0xAF)      EA;
    __sbit  __at(0xAE)      ELVD;
    __sbit  __at(0xAD)      EADC;
    __sbit  __at(0xAC)      ES;
    __sbit  __at(0xAB)      ET1;
    __sbit  __at(0xAA)      EX1;
    __sbit  __at(0xA9)      ET0;
    __sbit  __at(0xA8)      EX0;

__sfr       __at(0xA9)      SADDR;
__sfr       __at(0xAA)      WKTCL;
__sfr       __at(0xAB)      WKTCH;
__sfr       __at(0xAC)      S3CON;
__sfr       __at(0xAD)      S3BUF;
__sfr       __at(0xAE)      TA;
__sfr       __at(0xAF)      IE2;

__sfr       __at(0xB0)      P3;
    __sbit  __at(0xB0)      P30;
    __sbit  __at(0xB1)      P31;
    __sbit  __at(0xB2)      P32;
    __sbit  __at(0xB3)      P33;
    __sbit  __at(0xB4)      P34;
    __sbit  __at(0xB5)      P35;
    __sbit  __at(0xB6)      P36;
    __sbit  __at(0xB7)      P37;

    __sbit  __at(0xB7)      RD;
    __sbit  __at(0xB6)      WR;
    __sbit  __at(0xB5)      T1;
    __sbit  __at(0xB4)      T0;
    __sbit  __at(0xB3)      INT1;
    __sbit  __at(0xB2)      INT0;
    __sbit  __at(0xB1)      TXD;
    __sbit  __at(0xB0)      RXD;

__sfr       __at(0xB1)      P3M1;
__sfr       __at(0xB2)      P3M0;
__sfr       __at(0xB3)      P4M1;
__sfr       __at(0xB4)      P4M0;
__sfr       __at(0xB5)      IP2;
__sfr       __at(0xB6)      IP2H;
__sfr       __at(0xB7)      IPH;

__sfr       __at(0xB8)      IP;
    __sbit  __at(0xBF)      PPCA;
    __sbit  __at(0xBE)      PLVD;
    __sbit  __at(0xBD)      PADC;
    __sbit  __at(0xBC)      PS;
    __sbit  __at(0xBB)      PT1;
    __sbit  __at(0xBA)      PX1;
    __sbit  __at(0xB9)      PT0;
    __sbit  __at(0xB8)      PX0;

__sfr       __at(0xB9)      SADEN;
__sfr       __at(0xBA)      P_SW2;
__sfr       __at(0xBC)      ADC_CONTR;
__sfr       __at(0xBD)      ADC_RES;
__sfr       __at(0xBE)      ADC_RESL;

__sfr       __at(0xC0)      P4;
    __sbit  __at(0xC0)      P40;
    __sbit  __at(0xC1)      P41;
    __sbit  __at(0xC2)      P42;
    __sbit  __at(0xC3)      P43;
    __sbit  __at(0xC4)      P44;
    __sbit  __at(0xC5)      P45;
    __sbit  __at(0xC6)      P46;
    __sbit  __at(0xC7)      P47;

__sfr       __at(0xC1)      WDT_CONTR;
__sfr       __at(0xC2)      IAP_DATA;
__sfr       __at(0xC3)      IAP_ADDRH;
__sfr       __at(0xC4)      IAP_ADDRL;
__sfr       __at(0xC5)      IAP_CMD;
__sfr       __at(0xC6)      IAP_TRIG;
__sfr       __at(0xC7)      IAP_CONTR;

__sfr       __at(0xC8)      P5;
    __sbit  __at(0xC8)      P50;
    __sbit  __at(0xC9)      P51;
    __sbit  __at(0xCA)      P52;
    __sbit  __at(0xCB)      P53;
    __sbit  __at(0xCC)      P54;
    __sbit  __at(0xCD)      P55;
    __sbit  __at(0xCE)      P56;
    __sbit  __at(0xCF)      P57;

__sfr       __at(0xC9)      P5M1;
__sfr       __at(0xCA)      P5M0;
__sfr       __at(0xCB)      P6M1;
__sfr       __at(0xCC)      P6M0;
__sfr       __at(0xCD)      SPSTAT;
__sfr       __at(0xCE)      SPCTL;
__sfr       __at(0xCF)      SPDAT;

__sfr       __at(0xD0)      PSW;
    __sbit  __at(0xD7)      CY;
    __sbit  __at(0xD6)      AC;
    __sbit  __at(0xD5)      F0;
    __sbit  __at(0xD4)      RS1;
    __sbit  __at(0xD3)      RS0;
    __sbit  __at(0xD2)      OV;
    __sbit  __at(0xD1)      F1;
    __sbit  __at(0xD0)      P;

__sfr       __at(0xD1)      T4T3M;
__sfr       __at(0xD2)      T4H;
__sfr       __at(0xD3)      T4L;
__sfr       __at(0xD4)      T3H;
__sfr       __at(0xD5)      T3L;
__sfr       __at(0xD6)      T2H;
__sfr       __at(0xD7)      T2L;

__sfr       __at(0xD1)      T3T4M;
__sfr       __at(0xD2)      TH4;
__sfr       __at(0xD3)      TL4;
__sfr       __at(0xD4)      TH3;
__sfr       __at(0xD5)      TL3;
__sfr       __at(0xD6)      TH2;
__sfr       __at(0xD7)      TL2;

__sfr       __at(0xDC)      USBCLK;
__sfr       __at(0xDC)      PLLCR;
__sfr       __at(0xDE)      ADCCFG;
__sfr       __at(0xDF)      IP3;
__sfr       __at(0xE0)      ACC;
__sfr       __at(0xE1)      P7M1;
__sfr       __at(0xE2)      P7M0;
__sfr       __at(0xE3)      DPS;
__sfr       __at(0xE4)      DPL1;
__sfr       __at(0xE5)      DPH1;
__sfr       __at(0xE6)      CMPCR1;
__sfr       __at(0xE7)      CMPCR2;

__sfr       __at(0xE8)      P6;
    __sbit  __at(0xE8)      P60;
    __sbit  __at(0xE9)      P61;
    __sbit  __at(0xEA)      P62;
    __sbit  __at(0xEB)      P63;
    __sbit  __at(0xEC)      P64;
    __sbit  __at(0xED)      P65;
    __sbit  __at(0xEE)      P66;
    __sbit  __at(0xEF)      P67;

__sfr       __at(0xEC)      USBDAT;
__sfr       __at(0xEE)      IP3H;
__sfr       __at(0xEF)      AUXINTIF;
__sfr       __at(0xF0)      B;
__sfr       __at(0xF4)      USBCON;
__sfr       __at(0xF5)      IAP_TPS;

__sfr       __at(0xF8)      P7;
    __sbit  __at(0xF8)      P70;
    __sbit  __at(0xF9)      P71;
    __sbit  __at(0xFA)      P72;
    __sbit  __at(0xFB)      P73;
    __sbit  __at(0xFC)      P74;
    __sbit  __at(0xFD)      P75;
    __sbit  __at(0xFE)      P76;
    __sbit  __at(0xFF)      P77;

__sfr       __at(0xFC)      USBADR;
__sfr       __at(0xFF)      RSTCFG;

//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写

/////////////////////////////////////////////////
//FF00H-FFFFH
/////////////////////////////////////////////////



/////////////////////////////////////////////////
//FE00H-FEFFH
/////////////////////////////////////////////////

__xdata volatile unsigned char  __at(0xFE00) CLKSEL;
__xdata volatile unsigned char  __at(0xFE01) CLKDIV;
__xdata volatile unsigned char  __at(0xFE02) HIRCCR;
__xdata volatile unsigned char  __at(0xFE03) XOSCCR;
__xdata volatile unsigned char  __at(0xFE04) IRC32KCR;
__xdata volatile unsigned char  __at(0xFE05) MCLKOCR;
__xdata volatile unsigned char  __at(0xFE06) IRCDB;
__xdata volatile unsigned char  __at(0xFE07) IRC48MCR;
__xdata volatile unsigned char  __at(0xFE08) X32KCR;
__xdata volatile unsigned char  __at(0xFE0B) HSCLKDIV;

__xdata volatile unsigned char  __at(0xFE10) P0PU;
__xdata volatile unsigned char  __at(0xFE11) P1PU;
__xdata volatile unsigned char  __at(0xFE12) P2PU;
__xdata volatile unsigned char  __at(0xFE13) P3PU;
__xdata volatile unsigned char  __at(0xFE14) P4PU;
__xdata volatile unsigned char  __at(0xFE15) P5PU;
__xdata volatile unsigned char  __at(0xFE16) P6PU;
__xdata volatile unsigned char  __at(0xFE17) P7PU;
__xdata volatile unsigned char  __at(0xFE18) P0NCS;
__xdata volatile unsigned char  __at(0xFE19) P1NCS;
__xdata volatile unsigned char  __at(0xFE1A) P2NCS;
__xdata volatile unsigned char  __at(0xFE1B) P3NCS;
__xdata volatile unsigned char  __at(0xFE1C) P4NCS;
__xdata volatile unsigned char  __at(0xFE1D) P5NCS;
__xdata volatile unsigned char  __at(0xFE1E) P6NCS;
__xdata volatile unsigned char  __at(0xFE1F) P7NCS;
__xdata volatile unsigned char  __at(0xFE20) P0SR;
__xdata volatile unsigned char  __at(0xFE21) P1SR;
__xdata volatile unsigned char  __at(0xFE22) P2SR;
__xdata volatile unsigned char  __at(0xFE23) P3SR;
__xdata volatile unsigned char  __at(0xFE24) P4SR;
__xdata volatile unsigned char  __at(0xFE25) P5SR;
__xdata volatile unsigned char  __at(0xFE26) P6SR;
__xdata volatile unsigned char  __at(0xFE27) P7SR;
__xdata volatile unsigned char  __at(0xFE28) P0DR;
__xdata volatile unsigned char  __at(0xFE29) P1DR;
__xdata volatile unsigned char  __at(0xFE2A) P2DR;
__xdata volatile unsigned char  __at(0xFE2B) P3DR;
__xdata volatile unsigned char  __at(0xFE2C) P4DR;
__xdata volatile unsigned char  __at(0xFE2D) P5DR;
__xdata volatile unsigned char  __at(0xFE2E) P6DR;
__xdata volatile unsigned char  __at(0xFE2F) P7DR;
__xdata volatile unsigned char  __at(0xFE30) P0IE;
__xdata volatile unsigned char  __at(0xFE31) P1IE;
__xdata volatile unsigned char  __at(0xFE32) P2IE;
__xdata volatile unsigned char  __at(0xFE33) P3IE;
__xdata volatile unsigned char  __at(0xFE34) P4IE;
__xdata volatile unsigned char  __at(0xFE35) P5IE;
__xdata volatile unsigned char  __at(0xFE36) P6IE;
__xdata volatile unsigned char  __at(0xFE37) P7IE;

__xdata volatile unsigned char  __at(0xFE50) LCMIFCFG;
__xdata volatile unsigned char  __at(0xFE51) LCMIFCFG2;
__xdata volatile unsigned char  __at(0xFE52) LCMIFCR;
__xdata volatile unsigned char  __at(0xFE53) LCMIFSTA;
__xdata volatile unsigned char  __at(0xFE54) LCMIFDATL;
__xdata volatile unsigned char  __at(0xFE55) LCMIFDATH;

__xdata volatile unsigned char  __at(0xFE60) RTCCR;
__xdata volatile unsigned char  __at(0xFE61) RTCCFG;
__xdata volatile unsigned char  __at(0xFE62) RTCIEN;
__xdata volatile unsigned char  __at(0xFE63) RTCIF;
__xdata volatile unsigned char  __at(0xFE64) ALAHOUR;
__xdata volatile unsigned char  __at(0xFE65) ALAMIN;
__xdata volatile unsigned char  __at(0xFE66) ALASEC;
__xdata volatile unsigned char  __at(0xFE67) ALASSEC;
__xdata volatile unsigned char  __at(0xFE68) INIYEAR;
__xdata volatile unsigned char  __at(0xFE69) INIMONTH;
__xdata volatile unsigned char  __at(0xFE6A) INIDAY;
__xdata volatile unsigned char  __at(0xFE6B) INIHOUR;
__xdata volatile unsigned char  __at(0xFE6C) INIMIN;
__xdata volatile unsigned char  __at(0xFE6D) INISEC;
__xdata volatile unsigned char  __at(0xFE6E) INISSEC;
__xdata volatile unsigned char  __at(0xFE70) YEAR;
__xdata volatile unsigned char  __at(0xFE71) MONTH;
__xdata volatile unsigned char  __at(0xFE72) DAY;
__xdata volatile unsigned char  __at(0xFE73) HOUR;
__xdata volatile unsigned char  __at(0xFE74) MIN;
__xdata volatile unsigned char  __at(0xFE75) SEC;
__xdata volatile unsigned char  __at(0xFE76) SSEC;

__xdata volatile unsigned char  __at(0xFE78) T11CR;
__xdata volatile unsigned char  __at(0xFE79) T11PS;
__xdata volatile unsigned char  __at(0xFE7A) T11H;
__xdata volatile unsigned char  __at(0xFE7B) T11L;

__xdata volatile unsigned char  __at(0xFE80) I2CCFG;
__xdata volatile unsigned char  __at(0xFE81) I2CMSCR;
__xdata volatile unsigned char  __at(0xFE82) I2CMSST;
__xdata volatile unsigned char  __at(0xFE83) I2CSLCR;
__xdata volatile unsigned char  __at(0xFE84) I2CSLST;
__xdata volatile unsigned char  __at(0xFE85) I2CSLADR;
__xdata volatile unsigned char  __at(0xFE86) I2CTXD;
__xdata volatile unsigned char  __at(0xFE87) I2CRXD;
__xdata volatile unsigned char  __at(0xFE88) I2CMSAUX;

__xdata volatile unsigned char  __at(0xFE98) SPFUNC;
__xdata volatile unsigned char  __at(0xFE99) RSTFLAG;

__xdata volatile unsigned char  __at(0xFEA2) TM2PS;
__xdata volatile unsigned char  __at(0xFEA3) TM3PS;
__xdata volatile unsigned char  __at(0xFEA4) TM4PS;
__xdata volatile unsigned char  __at(0xFEA8) ADCTIM;
__xdata volatile unsigned char  __at(0xFEAC) T3T4PIN;
__xdata volatile unsigned char  __at(0xFEAD) ADCEXCFG;
__xdata volatile unsigned char  __at(0xFEAE) CMPEXCFG;

__xdata volatile unsigned char  __at(0xFEB0) PWM1_ETRPS;
__xdata volatile unsigned char  __at(0xFEB1) PWM1_ENO;
__xdata volatile unsigned char  __at(0xFEB2) PWM1_PS;
__xdata volatile unsigned char  __at(0xFEB3) PWM1_IOAUX;
__xdata volatile unsigned char  __at(0xFEB4) PWM2_ETRPS;
__xdata volatile unsigned char  __at(0xFEB5) PWM2_ENO;
__xdata volatile unsigned char  __at(0xFEB6) PWM2_PS;
__xdata volatile unsigned char  __at(0xFEB7) PWM2_IOAUX;
__xdata volatile unsigned char  __at(0xFEC0) PWM1_CR1;
__xdata volatile unsigned char  __at(0xFEC1) PWM1_CR2;
__xdata volatile unsigned char  __at(0xFEC2) PWM1_SMCR;
__xdata volatile unsigned char  __at(0xFEC3) PWM1_ETR;
__xdata volatile unsigned char  __at(0xFEC4) PWM1_IER;
__xdata volatile unsigned char  __at(0xFEC5) PWM1_SR1;
__xdata volatile unsigned char  __at(0xFEC6) PWM1_SR2;
__xdata volatile unsigned char  __at(0xFEC7) PWM1_EGR;
__xdata volatile unsigned char  __at(0xFEC8) PWM1_CCMR1;
__xdata volatile unsigned char  __at(0xFEC9) PWM1_CCMR2;
__xdata volatile unsigned char  __at(0xFECA) PWM1_CCMR3;
__xdata volatile unsigned char  __at(0xFECB) PWM1_CCMR4;
__xdata volatile unsigned char  __at(0xFECC) PWM1_CCER1;
__xdata volatile unsigned char  __at(0xFECD) PWM1_CCER2;
__xdata volatile unsigned short __at(0xFECE) PWM1_CNTR;
__xdata volatile unsigned char  __at(0xFECE) PWM1_CNTRH;
__xdata volatile unsigned char  __at(0xFECF) PWM1_CNTRL;
__xdata volatile unsigned short __at(0xFED0) PWM1_PSCR;
__xdata volatile unsigned char  __at(0xFED0) PWM1_PSCRH;
__xdata volatile unsigned char  __at(0xFED1) PWM1_PSCRL;
__xdata volatile unsigned short __at(0xFED2) PWM1_ARR;
__xdata volatile unsigned char  __at(0xFED2) PWM1_ARRH;
__xdata volatile unsigned char  __at(0xFED3) PWM1_ARRL;
__xdata volatile unsigned char  __at(0xFED4) PWM1_RCR;
__xdata volatile unsigned short __at(0xFED5) PWM1_CCR1;
__xdata volatile unsigned char  __at(0xFED5) PWM1_CCR1H;
__xdata volatile unsigned char  __at(0xFED6) PWM1_CCR1L;
__xdata volatile unsigned short __at(0xFED7) PWM1_CCR2;
__xdata volatile unsigned char  __at(0xFED7) PWM1_CCR2H;
__xdata volatile unsigned char  __at(0xFED8) PWM1_CCR2L;
__xdata volatile unsigned short __at(0xFED9) PWM1_CCR3;
__xdata volatile unsigned char  __at(0xFED9) PWM1_CCR3H;
__xdata volatile unsigned char  __at(0xFEDA) PWM1_CCR3L;
__xdata volatile unsigned short __at(0xFEDB) PWM1_CCR4;
__xdata volatile unsigned char  __at(0xFEDB) PWM1_CCR4H;
__xdata volatile unsigned char  __at(0xFEDC) PWM1_CCR4L;
__xdata volatile unsigned char  __at(0xFEDD) PWM1_BKR;
__xdata volatile unsigned char  __at(0xFEDE) PWM1_DTR;
__xdata volatile unsigned char  __at(0xFEDF) PWM1_OISR;
__xdata volatile unsigned char  __at(0xFEE0) PWM2_CR1;
__xdata volatile unsigned char  __at(0xFEE1) PWM2_CR2;
__xdata volatile unsigned char  __at(0xFEE2) PWM2_SMCR;
__xdata volatile unsigned char  __at(0xFEE3) PWM2_ETR;
__xdata volatile unsigned char  __at(0xFEE4) PWM2_IER;
__xdata volatile unsigned char  __at(0xFEE5) PWM2_SR1;
__xdata volatile unsigned char  __at(0xFEE6) PWM2_SR2;
__xdata volatile unsigned char  __at(0xFEE7) PWM2_EGR;
__xdata volatile unsigned char  __at(0xFEE8) PWM2_CCMR1;
__xdata volatile unsigned char  __at(0xFEE9) PWM2_CCMR2;
__xdata volatile unsigned char  __at(0xFEEA) PWM2_CCMR3;
__xdata volatile unsigned char  __at(0xFEEB) PWM2_CCMR4;
__xdata volatile unsigned char  __at(0xFEEC) PWM2_CCER1;
__xdata volatile unsigned char  __at(0xFEED) PWM2_CCER2;
__xdata volatile unsigned short __at(0xFEEE) PWM2_CNTR;
__xdata volatile unsigned char  __at(0xFEEE) PWM2_CNTRH;
__xdata volatile unsigned char  __at(0xFEEF) PWM2_CNTRL;
__xdata volatile unsigned short __at(0xFEF0) PWM2_PSCR;
__xdata volatile unsigned char  __at(0xFEF0) PWM2_PSCRH;
__xdata volatile unsigned char  __at(0xFEF1) PWM2_PSCRL;
__xdata volatile unsigned short __at(0xFEF2) PWM2_ARR;
__xdata volatile unsigned char  __at(0xFEF2) PWM2_ARRH;
__xdata volatile unsigned char  __at(0xFEF3) PWM2_ARRL;
__xdata volatile unsigned char  __at(0xFEF4) PWM2_RCR;
__xdata volatile unsigned short __at(0xFEF5) PWM2_CCR1;
__xdata volatile unsigned char  __at(0xFEF5) PWM2_CCR1H;
__xdata volatile unsigned char  __at(0xFEF6) PWM2_CCR1L;
__xdata volatile unsigned short __at(0xFEF7) PWM2_CCR2;
__xdata volatile unsigned char  __at(0xFEF7) PWM2_CCR2H;
__xdata volatile unsigned char  __at(0xFEF8) PWM2_CCR2L;
__xdata volatile unsigned short __at(0xFEF9) PWM2_CCR3;
__xdata volatile unsigned char  __at(0xFEF9) PWM2_CCR3H;
__xdata volatile unsigned char  __at(0xFEFA) PWM2_CCR3L;
__xdata volatile unsigned short __at(0xFEFB) PWM2_CCR4;
__xdata volatile unsigned char  __at(0xFEFB) PWM2_CCR4H;
__xdata volatile unsigned char  __at(0xFEFC) PWM2_CCR4L;
__xdata volatile unsigned char  __at(0xFEFD) PWM2_BKR;
__xdata volatile unsigned char  __at(0xFEFE) PWM2_DTR;
__xdata volatile unsigned char  __at(0xFEFF) PWM2_OISR;

__xdata volatile unsigned char  __at(0xFEB0) PWMA_ETRPS;
__xdata volatile unsigned char  __at(0xFEB1) PWMA_ENO;
__xdata volatile unsigned char  __at(0xFEB2) PWMA_PS;
__xdata volatile unsigned char  __at(0xFEB3) PWMA_IOAUX;
__xdata volatile unsigned char  __at(0xFEB4) PWMB_ETRPS;
__xdata volatile unsigned char  __at(0xFEB5) PWMB_ENO;
__xdata volatile unsigned char  __at(0xFEB6) PWMB_PS;
__xdata volatile unsigned char  __at(0xFEB7) PWMB_IOAUX;
__xdata volatile unsigned char  __at(0xFEC0) PWMA_CR1;
__xdata volatile unsigned char  __at(0xFEC1) PWMA_CR2;
__xdata volatile unsigned char  __at(0xFEC2) PWMA_SMCR;
__xdata volatile unsigned char  __at(0xFEC3) PWMA_ETR;
__xdata volatile unsigned char  __at(0xFEC4) PWMA_IER;
__xdata volatile unsigned char  __at(0xFEC5) PWMA_SR1;
__xdata volatile unsigned char  __at(0xFEC6) PWMA_SR2;
__xdata volatile unsigned char  __at(0xFEC7) PWMA_EGR;
__xdata volatile unsigned char  __at(0xFEC8) PWMA_CCMR1;
__xdata volatile unsigned char  __at(0xFEC9) PWMA_CCMR2;
__xdata volatile unsigned char  __at(0xFECA) PWMA_CCMR3;
__xdata volatile unsigned char  __at(0xFECB) PWMA_CCMR4;
__xdata volatile unsigned char  __at(0xFECC) PWMA_CCER1;
__xdata volatile unsigned char  __at(0xFECD) PWMA_CCER2;
__xdata volatile unsigned short __at(0xFECE) PWMA_CNTR;
__xdata volatile unsigned char  __at(0xFECE) PWMA_CNTRH;
__xdata volatile unsigned char  __at(0xFECF) PWMA_CNTRL;
__xdata volatile unsigned short __at(0xFED0) PWMA_PSCR;
__xdata volatile unsigned char  __at(0xFED0) PWMA_PSCRH;
__xdata volatile unsigned char  __at(0xFED1) PWMA_PSCRL;
__xdata volatile unsigned short __at(0xFED2) PWMA_ARR;
__xdata volatile unsigned char  __at(0xFED2) PWMA_ARRH;
__xdata volatile unsigned char  __at(0xFED3) PWMA_ARRL;
__xdata volatile unsigned char  __at(0xFED4) PWMA_RCR;
__xdata volatile unsigned short __at(0xFED5) PWMA_CCR1;
__xdata volatile unsigned char  __at(0xFED5) PWMA_CCR1H;
__xdata volatile unsigned char  __at(0xFED6) PWMA_CCR1L;
__xdata volatile unsigned short __at(0xFED7) PWMA_CCR2;
__xdata volatile unsigned char  __at(0xFED7) PWMA_CCR2H;
__xdata volatile unsigned char  __at(0xFED8) PWMA_CCR2L;
__xdata volatile unsigned short __at(0xFED9) PWMA_CCR3;
__xdata volatile unsigned char  __at(0xFED9) PWMA_CCR3H;
__xdata volatile unsigned char  __at(0xFEDA) PWMA_CCR3L;
__xdata volatile unsigned short __at(0xFEDB) PWMA_CCR4;
__xdata volatile unsigned char  __at(0xFEDB) PWMA_CCR4H;
__xdata volatile unsigned char  __at(0xFEDC) PWMA_CCR4L;
__xdata volatile unsigned char  __at(0xFEDD) PWMA_BKR;
__xdata volatile unsigned char  __at(0xFEDE) PWMA_DTR;
__xdata volatile unsigned char  __at(0xFEDF) PWMA_OISR;
__xdata volatile unsigned char  __at(0xFEE0) PWMB_CR1;
__xdata volatile unsigned char  __at(0xFEE1) PWMB_CR2;
__xdata volatile unsigned char  __at(0xFEE2) PWMB_SMCR;
__xdata volatile unsigned char  __at(0xFEE3) PWMB_ETR;
__xdata volatile unsigned char  __at(0xFEE4) PWMB_IER;
__xdata volatile unsigned char  __at(0xFEE5) PWMB_SR1;
__xdata volatile unsigned char  __at(0xFEE6) PWMB_SR2;
__xdata volatile unsigned char  __at(0xFEE7) PWMB_EGR;
__xdata volatile unsigned char  __at(0xFEE8) PWMB_CCMR1;
__xdata volatile unsigned char  __at(0xFEE9) PWMB_CCMR2;
__xdata volatile unsigned char  __at(0xFEEA) PWMB_CCMR3;
__xdata volatile unsigned char  __at(0xFEEB) PWMB_CCMR4;
__xdata volatile unsigned char  __at(0xFEEC) PWMB_CCER1;
__xdata volatile unsigned char  __at(0xFEED) PWMB_CCER2;
__xdata volatile unsigned short __at(0xFEEE) PWMB_CNTR;
__xdata volatile unsigned char  __at(0xFEEE) PWMB_CNTRH;
__xdata volatile unsigned char  __at(0xFEEF) PWMB_CNTRL;
__xdata volatile unsigned short __at(0xFEF0) PWMB_PSCR;
__xdata volatile unsigned char  __at(0xFEF0) PWMB_PSCRH;
__xdata volatile unsigned char  __at(0xFEF1) PWMB_PSCRL;
__xdata volatile unsigned short __at(0xFEF2) PWMB_ARR;
__xdata volatile unsigned char  __at(0xFEF2) PWMB_ARRH;
__xdata volatile unsigned char  __at(0xFEF3) PWMB_ARRL;
__xdata volatile unsigned char  __at(0xFEF4) PWMB_RCR;
__xdata volatile unsigned short __at(0xFEF5) PWMB_CCR5;
__xdata volatile unsigned char  __at(0xFEF5) PWMB_CCR5H;
__xdata volatile unsigned char  __at(0xFEF6) PWMB_CCR5L;
__xdata volatile unsigned short __at(0xFEF7) PWMB_CCR6;
__xdata volatile unsigned char  __at(0xFEF7) PWMB_CCR6H;
__xdata volatile unsigned char  __at(0xFEF8) PWMB_CCR6L;
__xdata volatile unsigned short __at(0xFEF9) PWMB_CCR7;
__xdata volatile unsigned char  __at(0xFEF9) PWMB_CCR7H;
__xdata volatile unsigned char  __at(0xFEFA) PWMB_CCR7L;
__xdata volatile unsigned short __at(0xFEFB) PWMB_CCR8;
__xdata volatile unsigned char  __at(0xFEFB) PWMB_CCR8H;
__xdata volatile unsigned char  __at(0xFEFC) PWMB_CCR8L;
__xdata volatile unsigned char  __at(0xFEFD) PWMB_BKR;
__xdata volatile unsigned char  __at(0xFEFE) PWMB_DTR;
__xdata volatile unsigned char  __at(0xFEFF) PWMB_OISR;

/////////////////////////////////////////////////
//FD00H-FDFFH
/////////////////////////////////////////////////

__xdata volatile unsigned char  __at(0xFD00) P0INTE;
__xdata volatile unsigned char  __at(0xFD01) P1INTE;
__xdata volatile unsigned char  __at(0xFD02) P2INTE;
__xdata volatile unsigned char  __at(0xFD03) P3INTE;
__xdata volatile unsigned char  __at(0xFD04) P4INTE;
__xdata volatile unsigned char  __at(0xFD05) P5INTE;
__xdata volatile unsigned char  __at(0xFD06) P6INTE;
__xdata volatile unsigned char  __at(0xFD07) P7INTE;
__xdata volatile unsigned char  __at(0xFD10) P0INTF;
__xdata volatile unsigned char  __at(0xFD11) P1INTF;
__xdata volatile unsigned char  __at(0xFD12) P2INTF;
__xdata volatile unsigned char  __at(0xFD13) P3INTF;
__xdata volatile unsigned char  __at(0xFD14) P4INTF;
__xdata volatile unsigned char  __at(0xFD15) P5INTF;
__xdata volatile unsigned char  __at(0xFD16) P6INTF;
__xdata volatile unsigned char  __at(0xFD17) P7INTF;
__xdata volatile unsigned char  __at(0xFD20) P0IM0;
__xdata volatile unsigned char  __at(0xFD21) P1IM0;
__xdata volatile unsigned char  __at(0xFD22) P2IM0;
__xdata volatile unsigned char  __at(0xFD23) P3IM0;
__xdata volatile unsigned char  __at(0xFD24) P4IM0;
__xdata volatile unsigned char  __at(0xFD25) P5IM0;
__xdata volatile unsigned char  __at(0xFD26) P6IM0;
__xdata volatile unsigned char  __at(0xFD27) P7IM0;
__xdata volatile unsigned char  __at(0xFD30) P0IM1;
__xdata volatile unsigned char  __at(0xFD31) P1IM1;
__xdata volatile unsigned char  __at(0xFD32) P2IM1;
__xdata volatile unsigned char  __at(0xFD33) P3IM1;
__xdata volatile unsigned char  __at(0xFD34) P4IM1;
__xdata volatile unsigned char  __at(0xFD35) P5IM1;
__xdata volatile unsigned char  __at(0xFD36) P6IM1;
__xdata volatile unsigned char  __at(0xFD37) P7IM1;
__xdata volatile unsigned char  __at(0xFD40) P0WKUE;
__xdata volatile unsigned char  __at(0xFD41) P1WKUE;
__xdata volatile unsigned char  __at(0xFD42) P2WKUE;
__xdata volatile unsigned char  __at(0xFD43) P3WKUE;
__xdata volatile unsigned char  __at(0xFD44) P4WKUE;
__xdata volatile unsigned char  __at(0xFD45) P5WKUE;
__xdata volatile unsigned char  __at(0xFD46) P6WKUE;
__xdata volatile unsigned char  __at(0xFD47) P7WKUE;

__xdata volatile unsigned char  __at(0xFD60) PINIPL;
__xdata volatile unsigned char  __at(0xFD61) PINIPH;
__xdata volatile unsigned char  __at(0xFD69) P_SWX1;

__xdata volatile unsigned char  __at(0xFDA8) CRECR;
__xdata volatile unsigned char  __at(0xFDA9) CRECNTH;
__xdata volatile unsigned char  __at(0xFDAA) CRECNTL;
__xdata volatile unsigned char  __at(0xFDAB) CRERES;

#define     CHIPID                  ( (unsigned char volatile xdata *)0xfde0)

__xdata volatile unsigned char  __at(0xFDE0) CHIPID0;
__xdata volatile unsigned char  __at(0xFDE1) CHIPID1;
__xdata volatile unsigned char  __at(0xFDE2) CHIPID2;
__xdata volatile unsigned char  __at(0xFDE3) CHIPID3;
__xdata volatile unsigned char  __at(0xFDE4) CHIPID4;
__xdata volatile unsigned char  __at(0xFDE5) CHIPID5;
__xdata volatile unsigned char  __at(0xFDE6) CHIPID6;
__xdata volatile unsigned char  __at(0xFDE7) CHIPID7;
__xdata volatile unsigned char  __at(0xFDE8) CHIPID8;
__xdata volatile unsigned char  __at(0xFDE9) CHIPID9;
__xdata volatile unsigned char  __at(0xFDEA) CHIPID10;
__xdata volatile unsigned char  __at(0xFDEB) CHIPID11;
__xdata volatile unsigned char  __at(0xFDEC) CHIPID12;
__xdata volatile unsigned char  __at(0xFDED) CHIPID13;
__xdata volatile unsigned char  __at(0xFDEE) CHIPID14;
__xdata volatile unsigned char  __at(0xFDEF) CHIPID15;
__xdata volatile unsigned char  __at(0xFDF0) CHIPID16;
__xdata volatile unsigned char  __at(0xFDF1) CHIPID17;
__xdata volatile unsigned char  __at(0xFDF2) CHIPID18;
__xdata volatile unsigned char  __at(0xFDF3) CHIPID19;
__xdata volatile unsigned char  __at(0xFDF4) CHIPID20;
__xdata volatile unsigned char  __at(0xFDF5) CHIPID21;
__xdata volatile unsigned char  __at(0xFDF6) CHIPID22;
__xdata volatile unsigned char  __at(0xFDF7) CHIPID23;
__xdata volatile unsigned char  __at(0xFDF8) CHIPID24;
__xdata volatile unsigned char  __at(0xFDF9) CHIPID25;
__xdata volatile unsigned char  __at(0xFDFA) CHIPID26;
__xdata volatile unsigned char  __at(0xFDFB) CHIPID27;
__xdata volatile unsigned char  __at(0xFDFC) CHIPID28;
__xdata volatile unsigned char  __at(0xFDFD) CHIPID29;
__xdata volatile unsigned char  __at(0xFDFE) CHIPID30;
__xdata volatile unsigned char  __at(0xFDFF) CHIPID31;

/////////////////////////////////////////////////
//FC00H-FCFFH
/////////////////////////////////////////////////

__xdata volatile unsigned char  __at(0xFCF0) MD3;
__xdata volatile unsigned char  __at(0xFCF1) MD2;
__xdata volatile unsigned char  __at(0xFCF2) MD1;
__xdata volatile unsigned char  __at(0xFCF3) MD0;
__xdata volatile unsigned char  __at(0xFCF4) MD5;
__xdata volatile unsigned char  __at(0xFCF5) MD4;
__xdata volatile unsigned char  __at(0xFCF6) ARCON;
__xdata volatile unsigned char  __at(0xFCF7) OPCON;

/////////////////////////////////////////////////
//FB00H-FBFFH
/////////////////////////////////////////////////

__xdata volatile unsigned char  __at(0xFB00) COMEN;
__xdata volatile unsigned char  __at(0xFB01) SEGENL;
__xdata volatile unsigned char  __at(0xFB02) SEGENH;
__xdata volatile unsigned char  __at(0xFB03) LEDCTRL;
__xdata volatile unsigned char  __at(0xFB04) LEDCKS;
__xdata volatile unsigned char  __at(0xFB10) COM0_DA_L;
__xdata volatile unsigned char  __at(0xFB11) COM1_DA_L;
__xdata volatile unsigned char  __at(0xFB12) COM2_DA_L;
__xdata volatile unsigned char  __at(0xFB13) COM3_DA_L;
__xdata volatile unsigned char  __at(0xFB14) COM4_DA_L;
__xdata volatile unsigned char  __at(0xFB15) COM5_DA_L;
__xdata volatile unsigned char  __at(0xFB16) COM6_DA_L;
__xdata volatile unsigned char  __at(0xFB17) COM7_DA_L;
__xdata volatile unsigned char  __at(0xFB18) COM0_DA_H;
__xdata volatile unsigned char  __at(0xFB19) COM1_DA_H;
__xdata volatile unsigned char  __at(0xFB1A) COM2_DA_H;
__xdata volatile unsigned char  __at(0xFB1B) COM3_DA_H;
__xdata volatile unsigned char  __at(0xFB1C) COM4_DA_H;
__xdata volatile unsigned char  __at(0xFB1D) COM5_DA_H;
__xdata volatile unsigned char  __at(0xFB1E) COM6_DA_H;
__xdata volatile unsigned char  __at(0xFB1F) COM7_DA_H;
__xdata volatile unsigned char  __at(0xFB20) COM0_DC_L;
__xdata volatile unsigned char  __at(0xFB21) COM1_DC_L;
__xdata volatile unsigned char  __at(0xFB22) COM2_DC_L;
__xdata volatile unsigned char  __at(0xFB23) COM3_DC_L;
__xdata volatile unsigned char  __at(0xFB24) COM4_DC_L;
__xdata volatile unsigned char  __at(0xFB25) COM5_DC_L;
__xdata volatile unsigned char  __at(0xFB26) COM6_DC_L;
__xdata volatile unsigned char  __at(0xFB27) COM7_DC_L;
__xdata volatile unsigned char  __at(0xFB28) COM0_DC_H;
__xdata volatile unsigned char  __at(0xFB29) COM1_DC_H;
__xdata volatile unsigned char  __at(0xFB2A) COM2_DC_H;
__xdata volatile unsigned char  __at(0xFB2B) COM3_DC_H;
__xdata volatile unsigned char  __at(0xFB2C) COM4_DC_H;
__xdata volatile unsigned char  __at(0xFB2D) COM5_DC_H;
__xdata volatile unsigned char  __at(0xFB2E) COM6_DC_H;
__xdata volatile unsigned char  __at(0xFB2F) COM7_DC_H;

__xdata volatile unsigned char  __at(0xFB40) TSCHEN1;
__xdata volatile unsigned char  __at(0xFB41) TSCHEN2;
__xdata volatile unsigned char  __at(0xFB42) TSCFG1;
__xdata volatile unsigned char  __at(0xFB43) TSCFG2;
__xdata volatile unsigned char  __at(0xFB44) TSWUTC;
__xdata volatile unsigned char  __at(0xFB45) TSCTRL;
__xdata volatile unsigned char  __at(0xFB46) TSSTA1;
__xdata volatile unsigned char  __at(0xFB47) TSSTA2;
__xdata volatile unsigned char  __at(0xFB48) TSRT;
__xdata volatile unsigned short __at(0xFB49) TSDAT;
__xdata volatile unsigned char  __at(0xFB49) TSDATH;
__xdata volatile unsigned char  __at(0xFB4A) TSDATL;
__xdata volatile unsigned short __at(0xFB50) TSTH00;
__xdata volatile unsigned char  __at(0xFB50) TSTH00H;
__xdata volatile unsigned char  __at(0xFB51) TSTH00L;
__xdata volatile unsigned short __at(0xFB52) TSTH01;
__xdata volatile unsigned char  __at(0xFB52) TSTH01H;
__xdata volatile unsigned char  __at(0xFB53) TSTH01L;
__xdata volatile unsigned short __at(0xFB54) TSTH02;
__xdata volatile unsigned char  __at(0xFB54) TSTH02H;
__xdata volatile unsigned char  __at(0xFB55) TSTH02L;
__xdata volatile unsigned short __at(0xFB56) TSTH03;
__xdata volatile unsigned char  __at(0xFB56) TSTH03H;
__xdata volatile unsigned char  __at(0xFB57) TSTH03L;
__xdata volatile unsigned short __at(0xFB58) TSTH04;
__xdata volatile unsigned char  __at(0xFB58) TSTH04H;
__xdata volatile unsigned char  __at(0xFB59) TSTH04L;
__xdata volatile unsigned short __at(0xFB5A) TSTH05;
__xdata volatile unsigned char  __at(0xFB5A) TSTH05H;
__xdata volatile unsigned char  __at(0xFB5B) TSTH05L;
__xdata volatile unsigned short __at(0xFB5C) TSTH06;
__xdata volatile unsigned char  __at(0xFB5C) TSTH06H;
__xdata volatile unsigned char  __at(0xFB5D) TSTH06L;
__xdata volatile unsigned short __at(0xFB5E) TSTH07;
__xdata volatile unsigned char  __at(0xFB5E) TSTH07H;
__xdata volatile unsigned char  __at(0xFB5F) TSTH07L;
__xdata volatile unsigned short __at(0xFB60) TSTH08;
__xdata volatile unsigned char  __at(0xFB60) TSTH08H;
__xdata volatile unsigned char  __at(0xFB61) TSTH08L;
__xdata volatile unsigned short __at(0xFB62) TSTH09;
__xdata volatile unsigned char  __at(0xFB62) TSTH09H;
__xdata volatile unsigned char  __at(0xFB63) TSTH09L;
__xdata volatile unsigned short __at(0xFB64) TSTH10;
__xdata volatile unsigned char  __at(0xFB64) TSTH10H;
__xdata volatile unsigned char  __at(0xFB65) TSTH10L;
__xdata volatile unsigned short __at(0xFB66) TSTH11;
__xdata volatile unsigned char  __at(0xFB66) TSTH11H;
__xdata volatile unsigned char  __at(0xFB67) TSTH11L;
__xdata volatile unsigned short __at(0xFB68) TSTH12;
__xdata volatile unsigned char  __at(0xFB68) TSTH12H;
__xdata volatile unsigned char  __at(0xFB69) TSTH12L;
__xdata volatile unsigned short __at(0xFB6A) TSTH13;
__xdata volatile unsigned char  __at(0xFB6A) TSTH13H;
__xdata volatile unsigned char  __at(0xFB6B) TSTH13L;
__xdata volatile unsigned short __at(0xFB6C) TSTH14;
__xdata volatile unsigned char  __at(0xFB6C) TSTH14H;
__xdata volatile unsigned char  __at(0xFB6D) TSTH14L;
__xdata volatile unsigned short __at(0xFB6E) TSTH15;
__xdata volatile unsigned char  __at(0xFB6E) TSTH15H;
__xdata volatile unsigned char  __at(0xFB6F) TSTH15L;

__xdata volatile unsigned char  __at(0xFB80) LCDCFG;
__xdata volatile unsigned char  __at(0xFB81) LCDCFG2;
__xdata volatile unsigned char  __at(0xFB82) DBLEN;
__xdata volatile unsigned char  __at(0xFB83) COMLENL;
__xdata volatile unsigned char  __at(0xFB84) COMLENM;
__xdata volatile unsigned char  __at(0xFB85) COMLENH;
__xdata volatile unsigned char  __at(0xFB86) BLINKRATE;
__xdata volatile unsigned char  __at(0xFB87) LCDCR;
__xdata volatile unsigned char  __at(0xFB88) COMON;
__xdata volatile unsigned char  __at(0xFB8A) SEGON1;
__xdata volatile unsigned char  __at(0xFB8B) SEGON2;
__xdata volatile unsigned char  __at(0xFB8C) SEGON3;
__xdata volatile unsigned char  __at(0xFB8D) SEGON4;
__xdata volatile unsigned char  __at(0xFB8E) SEGON5;
__xdata volatile unsigned char  __at(0xFB90) C0SEGV0;
__xdata volatile unsigned char  __at(0xFB91) C0SEGV1;
__xdata volatile unsigned char  __at(0xFB92) C0SEGV2;
__xdata volatile unsigned char  __at(0xFB93) C0SEGV3;
__xdata volatile unsigned char  __at(0xFB94) C0SEGV4;
__xdata volatile unsigned char  __at(0xFB98) C1SEGV0;
__xdata volatile unsigned char  __at(0xFB99) C1SEGV1;
__xdata volatile unsigned char  __at(0xFB9A) C1SEGV2;
__xdata volatile unsigned char  __at(0xFB9B) C1SEGV3;
__xdata volatile unsigned char  __at(0xFB9C) C1SEGV4;
__xdata volatile unsigned char  __at(0xFBA0) C2SEGV0;
__xdata volatile unsigned char  __at(0xFBA1) C2SEGV1;
__xdata volatile unsigned char  __at(0xFBA2) C2SEGV2;
__xdata volatile unsigned char  __at(0xFBA3) C2SEGV3;
__xdata volatile unsigned char  __at(0xFBA4) C2SEGV4;
__xdata volatile unsigned char  __at(0xFBA8) C3SEGV0;
__xdata volatile unsigned char  __at(0xFBA9) C3SEGV1;
__xdata volatile unsigned char  __at(0xFBAA) C3SEGV2;
__xdata volatile unsigned char  __at(0xFBAB) C3SEGV3;
__xdata volatile unsigned char  __at(0xFBAC) C3SEGV4;

__xdata volatile unsigned char  __at(0xFBF0) HSPWMA_CFG;
__xdata volatile unsigned char  __at(0xFBF1) HSPWMA_ADR;
__xdata volatile unsigned char  __at(0xFBF2) HSPWMA_DAT;

__xdata volatile unsigned char  __at(0xFBF4) HSPWMB_CFG;
__xdata volatile unsigned char  __at(0xFBF5) HSPWMB_ADR;
__xdata volatile unsigned char  __at(0xFBF6) HSPWMB_DAT;

/////////////////////////////////////////////////
//FA00H-FAFFH
/////////////////////////////////////////////////

__xdata volatile unsigned char  __at(0xFA00) DMA_M2M_CFG;
__xdata volatile unsigned char  __at(0xFA01) DMA_M2M_CR;
__xdata volatile unsigned char  __at(0xFA02) DMA_M2M_STA;
__xdata volatile unsigned char  __at(0xFA03) DMA_M2M_AMT;
__xdata volatile unsigned char  __at(0xFA04) DMA_M2M_DONE;
__xdata volatile unsigned char  __at(0xFA05) DMA_M2M_TXAH;
__xdata volatile unsigned char  __at(0xFA06) DMA_M2M_TXAL;
__xdata volatile unsigned char  __at(0xFA07) DMA_M2M_RXAH;
__xdata volatile unsigned char  __at(0xFA08) DMA_M2M_RXAL;

__xdata volatile unsigned char  __at(0xFA10) DMA_ADC_CFG;
__xdata volatile unsigned char  __at(0xFA11) DMA_ADC_CR;
__xdata volatile unsigned char  __at(0xFA12) DMA_ADC_STA;
__xdata volatile unsigned short __at(0xFA17) DMA_ADC_RXA;
__xdata volatile unsigned char  __at(0xFA17) DMA_ADC_RXAH;
__xdata volatile unsigned char  __at(0xFA18) DMA_ADC_RXAL;
__xdata volatile unsigned char  __at(0xFA19) DMA_ADC_CFG2;
__xdata volatile unsigned char  __at(0xFA1A) DMA_ADC_CHSW0;
__xdata volatile unsigned char  __at(0xFA1B) DMA_ADC_CHSW1;

__xdata volatile unsigned char  __at(0xFA20) DMA_SPI_CFG;
__xdata volatile unsigned char  __at(0xFA21) DMA_SPI_CR;
__xdata volatile unsigned char  __at(0xFA22) DMA_SPI_STA;
__xdata volatile unsigned char  __at(0xFA23) DMA_SPI_AMT;
__xdata volatile unsigned char  __at(0xFA24) DMA_SPI_DONE;
__xdata volatile unsigned short __at(0xFA25) DMA_SPI_TXA;
__xdata volatile unsigned char  __at(0xFA25) DMA_SPI_TXAH;
__xdata volatile unsigned char  __at(0xFA26) DMA_SPI_TXAL;
__xdata volatile unsigned short __at(0xFA27) DMA_SPI_RXA;
__xdata volatile unsigned char  __at(0xFA27) DMA_SPI_RXAH;
__xdata volatile unsigned char  __at(0xFA28) DMA_SPI_RXAL;
__xdata volatile unsigned char  __at(0xFA29) DMA_SPI_CFG2;

__xdata volatile unsigned char  __at(0xFA30) DMA_UR1T_CFG;
__xdata volatile unsigned char  __at(0xFA31) DMA_UR1T_CR;
__xdata volatile unsigned char  __at(0xFA32) DMA_UR1T_STA;
__xdata volatile unsigned char  __at(0xFA33) DMA_UR1T_AMT;
__xdata volatile unsigned char  __at(0xFA34) DMA_UR1T_DONE;
__xdata volatile unsigned short __at(0xFA35) DMA_UR1T_TXA;
__xdata volatile unsigned char  __at(0xFA35) DMA_UR1T_TXAH;
__xdata volatile unsigned char  __at(0xFA36) DMA_UR1T_TXAL;
__xdata volatile unsigned char  __at(0xFA38) DMA_UR1R_CFG;
__xdata volatile unsigned char  __at(0xFA39) DMA_UR1R_CR;
__xdata volatile unsigned char  __at(0xFA3A) DMA_UR1R_STA;
__xdata volatile unsigned char  __at(0xFA3B) DMA_UR1R_AMT;
__xdata volatile unsigned char  __at(0xFA3C) DMA_UR1R_DONE;
__xdata volatile unsigned short __at(0xFA3D) DMA_UR1R_RXA;
__xdata volatile unsigned char  __at(0xFA3D) DMA_UR1R_RXAH;
__xdata volatile unsigned char  __at(0xFA3E) DMA_UR1R_RXAL;

__xdata volatile unsigned char  __at(0xFA40) DMA_UR2T_CFG;
__xdata volatile unsigned char  __at(0xFA41) DMA_UR2T_CR;
__xdata volatile unsigned char  __at(0xFA42) DMA_UR2T_STA;
__xdata volatile unsigned char  __at(0xFA43) DMA_UR2T_AMT;
__xdata volatile unsigned char  __at(0xFA44) DMA_UR2T_DONE;
__xdata volatile unsigned short __at(0xFA45) DMA_UR2T_TXA;
__xdata volatile unsigned char  __at(0xFA45) DMA_UR2T_TXAH;
__xdata volatile unsigned char  __at(0xFA46) DMA_UR2T_TXAL;
__xdata volatile unsigned char  __at(0xFA48) DMA_UR2R_CFG;
__xdata volatile unsigned char  __at(0xFA49) DMA_UR2R_CR;
__xdata volatile unsigned char  __at(0xFA4A) DMA_UR2R_STA;
__xdata volatile unsigned char  __at(0xFA4B) DMA_UR2R_AMT;
__xdata volatile unsigned char  __at(0xFA4C) DMA_UR2R_DONE;
__xdata volatile unsigned short __at(0xFA4D) DMA_UR2R_RXA;
__xdata volatile unsigned char  __at(0xFA4D) DMA_UR2R_RXAH;
__xdata volatile unsigned char  __at(0xFA4E) DMA_UR2R_RXAL;

__xdata volatile unsigned char  __at(0xFA50) DMA_UR3T_CFG;
__xdata volatile unsigned char  __at(0xFA51) DMA_UR3T_CR;
__xdata volatile unsigned char  __at(0xFA52) DMA_UR3T_STA;
__xdata volatile unsigned char  __at(0xFA53) DMA_UR3T_AMT;
__xdata volatile unsigned char  __at(0xFA54) DMA_UR3T_DONE;
__xdata volatile unsigned short __at(0xFA55) DMA_UR3T_TXA;
__xdata volatile unsigned char  __at(0xFA55) DMA_UR3T_TXAH;
__xdata volatile unsigned char  __at(0xFA56) DMA_UR3T_TXAL;
__xdata volatile unsigned char  __at(0xFA58) DMA_UR3R_CFG;
__xdata volatile unsigned char  __at(0xFA59) DMA_UR3R_CR;
__xdata volatile unsigned char  __at(0xFA5A) DMA_UR3R_STA;
__xdata volatile unsigned char  __at(0xFA5B) DMA_UR3R_AMT;
__xdata volatile unsigned char  __at(0xFA5C) DMA_UR3R_DONE;
__xdata volatile unsigned short __at(0xFA5D) DMA_UR3R_RXA;
__xdata volatile unsigned char  __at(0xFA5D) DMA_UR3R_RXAH;
__xdata volatile unsigned char  __at(0xFA5E) DMA_UR3R_RXAL;

__xdata volatile unsigned char  __at(0xFA60) DMA_UR4T_CFG;
__xdata volatile unsigned char  __at(0xFA61) DMA_UR4T_CR;
__xdata volatile unsigned char  __at(0xFA62) DMA_UR4T_STA;
__xdata volatile unsigned char  __at(0xFA63) DMA_UR4T_AMT;
__xdata volatile unsigned char  __at(0xFA64) DMA_UR4T_DONE;
__xdata volatile unsigned short __at(0xFA65) DMA_UR4T_TXA;
__xdata volatile unsigned char  __at(0xFA65) DMA_UR4T_TXAH;
__xdata volatile unsigned char  __at(0xFA66) DMA_UR4T_TXAL;
__xdata volatile unsigned char  __at(0xFA68) DMA_UR4R_CFG;
__xdata volatile unsigned char  __at(0xFA69) DMA_UR4R_CR;
__xdata volatile unsigned char  __at(0xFA6A) DMA_UR4R_STA;
__xdata volatile unsigned char  __at(0xFA6B) DMA_UR4R_AMT;
__xdata volatile unsigned char  __at(0xFA6C) DMA_UR4R_DONE;
__xdata volatile unsigned short __at(0xFA6D) DMA_UR4R_RXA;
__xdata volatile unsigned char  __at(0xFA6D) DMA_UR4R_RXAH;
__xdata volatile unsigned char  __at(0xFA6E) DMA_UR4R_RXAL;

__xdata volatile unsigned char  __at(0xFA70) DMA_LCM_CFG;
__xdata volatile unsigned char  __at(0xFA71) DMA_LCM_CR;
__xdata volatile unsigned char  __at(0xFA72) DMA_LCM_STA;
__xdata volatile unsigned char  __at(0xFA73) DMA_LCM_AMT;
__xdata volatile unsigned char  __at(0xFA74) DMA_LCM_DONE;
__xdata volatile unsigned short __at(0xFA75) DMA_LCM_TXA;
__xdata volatile unsigned char  __at(0xFA75) DMA_LCM_TXAH;
__xdata volatile unsigned char  __at(0xFA76) DMA_LCM_TXAL;
__xdata volatile unsigned short __at(0xFA77) DMA_LCM_RXA;
__xdata volatile unsigned char  __at(0xFA77) DMA_LCM_RXAH;
__xdata volatile unsigned char  __at(0xFA78) DMA_LCM_RXAL;

/////////////////////////////////////////////////
//F900H-F9FFH
/////////////////////////////////////////////////

__xdata volatile unsigned char  __at(0xf930) PWMA_ENO2        ;
__xdata volatile unsigned char  __at(0xf931) PWMA_IOAUX2      ;
__xdata volatile unsigned char  __at(0xf932) PWMA_CR3         ;
__xdata volatile unsigned char  __at(0xf933) PWMA_SR3         ;
__xdata volatile unsigned char  __at(0xf934) PWMA_CCER3       ;
__xdata volatile unsigned char  __at(0xf938) PWMA_CCMR1X      ;
__xdata volatile unsigned char  __at(0xf939) PWMA_CCMR2X      ;
__xdata volatile unsigned char  __at(0xf93a) PWMA_CCMR3X      ;
__xdata volatile unsigned char  __at(0xf93b) PWMA_CCMR4X      ;
__xdata volatile unsigned char  __at(0xf93c) PWMA_CCMR5       ;
__xdata volatile unsigned char  __at(0xf93d) PWMA_CCMR5X      ;
__xdata volatile unsigned char  __at(0xf93e) PWMA_CCMR6       ;
__xdata volatile unsigned char  __at(0xf93f) PWMA_CCMR6X      ;
__xdata volatile unsigned char  __at(0xf940) PWMA_CCR5H       ;
__xdata volatile unsigned char  __at(0xf941) PWMA_CCR5L       ;
__xdata volatile unsigned char  __at(0xf942) PWMA_CCR5X       ;
__xdata volatile unsigned char  __at(0xf943) PWMA_CCR6H       ;
__xdata volatile unsigned char  __at(0xf944) PWMA_CCR6L       ;

/////////////////////////////////////////////////
//USB Control Regiter
/////////////////////////////////////////////////

//sfr       USBCLK      =           0xdc;
//sfr       USBDAT      =           0xec;
//sfr       USBCON      =           0xf4;
//sfr       USBADR      =           0xfc;

//使用方法:
//      char dat;
//
//      READ_USB(CSR0, dat);        //读USB寄存器
//      WRITE_USB(FADDR, 0x00);     //写USB寄存器

#define     READ_USB(reg, dat)          \
            {                           \
                while (USBADR & 0x80);  \
                USBADR = (reg) | 0x80;  \
                while (USBADR & 0x80);  \
                (dat) = USBDAT;         \
            }

#define     WRITE_USB(reg, dat)         \
            {                           \
                while (USBADR & 0x80);  \
                USBADR = (reg) & 0x7f;  \
                USBDAT = (dat);         \
            }

#define     USBBASE                 0
#define     FADDR                   (USBBASE + 0)
#define     UPDATE                  0x80
#define     POWER                   (USBBASE + 1)
#define     ISOUD                   0x80
#define     USBRST                  0x08
#define     USBRSU                  0x04
#define     USBSUS                  0x02
#define     ENSUS                   0x01
#define     INTRIN1                 (USBBASE + 2)
#define     EP5INIF                 0x20
#define     EP4INIF                 0x10
#define     EP3INIF                 0x08
#define     EP2INIF                 0x04
#define     EP1INIF                 0x02
#define     EP0IF                   0x01
#define     INTROUT1                (USBBASE + 4)
#define     EP5OUTIF                0x20
#define     EP4OUTIF                0x10
#define     EP3OUTIF                0x08
#define     EP2OUTIF                0x04
#define     EP1OUTIF                0x02
#define     INTRUSB                 (USBBASE + 6)
#define     SOFIF                   0x08
#define     RSTIF                   0x04
#define     RSUIF                   0x02
#define     SUSIF                   0x01
#define     INTRIN1E                (USBBASE + 7)
#define     EP5INIE                 0x20
#define     EP4INIE                 0x10
#define     EP3INIE                 0x08
#define     EP2INIE                 0x04
#define     EP1INIE                 0x02
#define     EP0IE                   0x01
#define     INTROUT1E               (USBBASE + 9)
#define     EP5OUTIE                0x20
#define     EP4OUTIE                0x10
#define     EP3OUTIE                0x08
#define     EP2OUTIE                0x04
#define     EP1OUTIE                0x02
#define     INTRUSBE                (USBBASE + 11)
#define     SOFIE                   0x08
#define     RSTIE                   0x04
#define     RSUIE                   0x02
#define     SUSIE                   0x01
#define     FRAME1                  (USBBASE + 12)
#define     FRAME2                  (USBBASE + 13)
#define     INDEX                   (USBBASE + 14)
#define     INMAXP                  (USBBASE + 16)
#define     CSR0                    (USBBASE + 17)
#define     SSUEND                  0x80
#define     SOPRDY                  0x40
#define     SDSTL                   0x20
#define     SUEND                   0x10
#define     DATEND                  0x08
#define     STSTL                   0x04
#define     IPRDY                   0x02
#define     OPRDY                   0x01
#define     INCSR1                  (USBBASE + 17)
#define     INCLRDT                 0x40
#define     INSTSTL                 0x20
#define     INSDSTL                 0x10
#define     INFLUSH                 0x08
#define     INUNDRUN                0x04
#define     INFIFONE                0x02
#define     INIPRDY                 0x01
#define     INCSR2                  (USBBASE + 18)
#define     INAUTOSET               0x80
#define     INISO                   0x40
#define     INMODEIN                0x20
#define     INMODEOUT               0x00
#define     INENDMA                 0x10
#define     INFCDT                  0x08
#define     OUTMAXP                 (USBBASE + 19)
#define     OUTCSR1                 (USBBASE + 20)
#define     OUTCLRDT                0x80
#define     OUTSTSTL                0x40
#define     OUTSDSTL                0x20
#define     OUTFLUSH                0x10
#define     OUTDATERR               0x08
#define     OUTOVRRUN               0x04
#define     OUTFIFOFUL              0x02
#define     OUTOPRDY                0x01
#define     OUTCSR2                 (USBBASE + 21)
#define     OUTAUTOCLR              0x80
#define     OUTISO                  0x40
#define     OUTENDMA                0x20
#define     OUTDMAMD                0x10
#define     COUNT0                  (USBBASE + 22)
#define     OUTCOUNT1               (USBBASE + 22)
#define     OUTCOUNT2               (USBBASE + 23)
#define     FIFO0                   (USBBASE + 32)
#define     FIFO1                   (USBBASE + 33)
#define     FIFO2                   (USBBASE + 34)
#define     FIFO3                   (USBBASE + 35)
#define     FIFO4                   (USBBASE + 36)
#define     FIFO5                   (USBBASE + 37)
#define     UTRKCTL                 (USBBASE + 48)
#define     UTRKSTS                 (USBBASE + 49)

/////////////////////////////////////////////////
//Interrupt Vector
/////////////////////////////////////////////////

#define     INT0_VECTOR             0       //0003H
#define     TMR0_VECTOR             1       //000BH
#define     INT1_VECTOR             2       //0013H
#define     TMR1_VECTOR             3       //001BH
#define     UART1_VECTOR            4       //0023H
#define     ADC_VECTOR              5       //002BH
#define     LVD_VECTOR              6       //0033H
#define     UART2_VECTOR            8       //0043H
#define     SPI_VECTOR              9       //004BH
#define     INT2_VECTOR             10      //0053H
#define     INT3_VECTOR             11      //005BH
#define     TMR2_VECTOR             12      //0063H
#define     USER_VECTOR             13      //006BH
#define     INT4_VECTOR             16      //0083H
#define     UART3_VECTOR            17      //008BH
#define     UART4_VECTOR            18      //0093H
#define     TMR3_VECTOR             19      //009BH
#define     TMR4_VECTOR             20      //00A3H
#define     CMP_VECTOR              21      //00ABH
#define     I2C_VECTOR              24      //00C3H
#define     USB_VECTOR              25      //00CBH
#define     PWMA_VECTOR             26      //00D3H
#define     PWMB_VECTOR             27      //00DBH

#define     TKSU_VECTOR             35      //011BH
#define     RTC_VECTOR              36      //0123H
#define     P0INT_VECTOR            37      //012BH
#define     P1INT_VECTOR            38      //0133H
#define     P2INT_VECTOR            39      //013BH
#define     P3INT_VECTOR            40      //0143H
#define     P4INT_VECTOR            41      //014BH
#define     P5INT_VECTOR            42      //0153H
#define     P6INT_VECTOR            43      //015BH
#define     P7INT_VECTOR            44      //0163H
#define     DMA_M2M_VECTOR          47      //017BH
#define     DMA_ADC_VECTOR          48      //0183H
#define     DMA_SPI_VECTOR          49      //018BH
#define     DMA_UR1T_VECTOR         50      //0193H
#define     DMA_UR1R_VECTOR         51      //019BH
#define     DMA_UR2T_VECTOR         52      //01A3H
#define     DMA_UR2R_VECTOR         53      //01ABH
#define     DMA_UR3T_VECTOR         54      //01B3H
#define     DMA_UR3R_VECTOR         55      //01BBH
#define     DMA_UR4T_VECTOR         56      //01C3H
#define     DMA_UR4R_VECTOR         57      //01CBH
#define     DMA_LCM_VECTOR          58      //01D3H
#define     LCM_VECTOR              59      //01DBH

/////////////////////////////////////////////////

#define	EAXSFR()		P_SW2 |= 0x80		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
#define	EAXRAM()		P_SW2 &= ~0x80		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */

/////////////////////////////////////////////////
#define NOP1()  _nop_()
#define NOP2()  NOP1(),NOP1()
#define NOP3()  NOP2(),NOP1()
#define NOP4()  NOP3(),NOP1()
#define NOP5()  NOP4(),NOP1()
#define NOP6()  NOP5(),NOP1()
#define NOP7()  NOP6(),NOP1()
#define NOP8()  NOP7(),NOP1()
#define NOP9()  NOP8(),NOP1()
#define NOP10() NOP9(),NOP1()
#define NOP11() NOP10(),NOP1()
#define NOP12() NOP11(),NOP1()
#define NOP13() NOP12(),NOP1()
#define NOP14() NOP13(),NOP1()
#define NOP15() NOP14(),NOP1()
#define NOP16() NOP15(),NOP1()
#define NOP17() NOP16(),NOP1()
#define NOP18() NOP17(),NOP1()
#define NOP19() NOP18(),NOP1()
#define NOP20() NOP19(),NOP1()
#define NOP21() NOP20(),NOP1()
#define NOP22() NOP21(),NOP1()
#define NOP23() NOP22(),NOP1()
#define NOP24() NOP23(),NOP1()
#define NOP25() NOP24(),NOP1()
#define NOP26() NOP25(),NOP1()
#define NOP27() NOP26(),NOP1()
#define NOP28() NOP27(),NOP1()
#define NOP29() NOP28(),NOP1()
#define NOP30() NOP29(),NOP1()
#define NOP31() NOP30(),NOP1()
#define NOP32() NOP31(),NOP1()
#define NOP33() NOP32(),NOP1()
#define NOP34() NOP33(),NOP1()
#define NOP35() NOP34(),NOP1()
#define NOP36() NOP35(),NOP1()
#define NOP37() NOP36(),NOP1()
#define NOP38() NOP37(),NOP1()
#define NOP39() NOP38(),NOP1()
#define NOP40() NOP39(),NOP1()
#define NOP(N)  NOP##N()


/////////////////////////////////////////////////

#endif
