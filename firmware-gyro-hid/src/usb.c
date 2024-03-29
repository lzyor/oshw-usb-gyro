#include "sdcc-short.h"
#include "stc8h.h"
#include <stdbool.h>
#include <stdint.h>

#include "usb-config.h"
#include "usb-req-std.h"
#include "usb.h"

uint8_t data DeviceState;
setup_t data Setup;
epstate_t data Ep0State;
uint8_t data InEpState;
uint8_t data OutEpState;

void usb_init() {
    P3M0 &= ~0x03;
    P3M1 |= 0x03;

    IRC48MCR = 0x80;
    while (!(IRC48MCR & 0x01))
        ;

    USBCLK = 0x00;
    USBCON = 0x90;

    usb_write_reg(FADDR, 0x00);
    usb_write_reg(POWER, 0x81);
    usb_write_reg(INTRIN1E, 0x3f);
    usb_write_reg(INTROUT1E, 0x3f);
    usb_write_reg(INTRUSBE, 0x07);
    usb_write_reg(POWER, 0x01);

    DeviceState = DEVSTATE_DEFAULT;
    Ep0State.bState = EPSTATE_IDLE;
    InEpState = 0x00;
    OutEpState = 0x00;

    IE2 |= 0x80; // EUSB = 1;
}

uint8_t usb_read_fifo(uint8_t fifo, uint8_t *pdat) {
    uint8_t cnt;
    uint8_t ret;

    uint8_t *t = pdat;
    ret = cnt = usb_read_reg(COUNT0);
    while (cnt--) {
        *t = usb_read_reg(fifo);
        t++;
    }

    return ret;
}

void usb_write_fifo(uint8_t fifo, uint8_t *pdat, uint8_t cnt) {
    uint8_t *t = pdat;
    while (cnt--) {
        usb_write_reg(fifo, *t);
        t++;
    }
}

void usb_isr() interrupt(USB_VECTOR) using(1) {
    CONFIG_HANDLE_USB_ISR_START();
    uint8_t intrusb;
    uint8_t intrin;
    uint8_t introut;

    intrusb = usb_read_reg(INTRUSB);
    intrin = usb_read_reg(INTRIN1);
    introut = usb_read_reg(INTROUT1);

    if (intrusb & RSUIF) usb_resume();
    if (intrusb & RSTIF) usb_reset();

    if (intrin & EP0IF) usb_setup();

#ifdef EN_EP1IN
    if (intrin & EP1INIF) usb_in_ep1();
#endif
#ifdef EN_EP2IN
    if (intrin & EP2INIF) usb_in_ep2();
#endif
#ifdef EN_EP3IN
    if (intrin & EP3INIF) usb_in_ep3();
#endif
#ifdef EN_EP4IN
    if (intrin & EP4INIF) usb_in_ep4();
#endif
#ifdef EN_EP5IN
    if (intrin & EP5INIF) usb_in_ep5();
#endif

#ifdef EN_EP1OUT
    if (introut & EP1OUTIF) usb_out_ep1();
#endif
#ifdef EN_EP2OUT
    if (introut & EP2OUTIF) usb_out_ep2();
#endif
#ifdef EN_EP3OUT
    if (introut & EP3OUTIF) usb_out_ep3();
#endif
#ifdef EN_EP4OUT
    if (introut & EP4OUTIF) usb_out_ep4();
#endif
#ifdef EN_EP5OUT
    if (introut & EP5OUTIF) usb_out_ep5();
#endif

    if (intrusb & SUSIF) usb_suspend();
    CONFIG_HANDLE_USB_ISR_END();
}

void usb_resume() {}

void usb_reset() {
    usb_write_reg(FADDR, 0x00);
    DeviceState = DEVSTATE_DEFAULT;
    Ep0State.bState = EPSTATE_IDLE;

#ifdef EN_EP1IN
    usb_write_reg(INDEX, 1);
    usb_write_reg(INCSR1, INCLRDT | INFLUSH);
#endif
#ifdef EN_EP2IN
    usb_write_reg(INDEX, 2);
    usb_write_reg(INCSR1, INCLRDT | INFLUSH);
#endif
#ifdef EN_EP3IN
    usb_write_reg(INDEX, 3);
    usb_write_reg(INCSR1, INCLRDT | INFLUSH);
#endif
#ifdef EN_EP4IN
    usb_write_reg(INDEX, 4);
    usb_write_reg(INCSR1, INCLRDT | INFLUSH);
#endif
#ifdef EN_EP5IN
    usb_write_reg(INDEX, 5);
    usb_write_reg(INCSR1, INCLRDT | INFLUSH);
#endif
#ifdef EN_EP1OUT
    usb_write_reg(INDEX, 1);
    usb_write_reg(OUTCSR1, OUTCLRDT | OUTFLUSH);
#endif
#ifdef EN_EP2OUT
    usb_write_reg(INDEX, 2);
    usb_write_reg(OUTCSR1, OUTCLRDT | OUTFLUSH);
#endif
#ifdef EN_EP3OUT
    usb_write_reg(INDEX, 3);
    usb_write_reg(OUTCSR1, OUTCLRDT | OUTFLUSH);
#endif
#ifdef EN_EP4OUT
    usb_write_reg(INDEX, 4);
    usb_write_reg(OUTCSR1, OUTCLRDT | OUTFLUSH);
#endif
#ifdef EN_EP5OUT
    usb_write_reg(INDEX, 5);
    usb_write_reg(OUTCSR1, OUTCLRDT | OUTFLUSH);
#endif
    usb_write_reg(INDEX, 0);
}

void usb_suspend() {}

void usb_setup() {
    uint8_t csr;

    usb_write_reg(INDEX, 0);
    csr = usb_read_reg(CSR0);

    if (csr & STSTL) {
        usb_write_reg(CSR0, csr & ~STSTL);
        Ep0State.bState = EPSTATE_IDLE;
    }
    if (csr & SUEND) {
        usb_write_reg(CSR0, csr | SSUEND);
    }

    switch (Ep0State.bState) {
    case EPSTATE_IDLE:
        if (csr & OPRDY) {
            usb_read_fifo(FIFO0, (uint8_t *)&Setup);
            Setup.wLength = Setup.wLength;
            // Setup.wLength = reverse2(Setup.wLength);
            switch (Setup.bmRequestType & REQUEST_MASK) {
            case STANDARD_REQUEST:
                usb_req_std();
                break;
            case CLASS_REQUEST:
                usb_req_class();
                break;
            case VENDOR_REQUEST:
                usb_req_vendor();
                break;
            default:
                usb_setup_stall();
                return;
            }
        }
        break;
    case EPSTATE_DATAIN:
        usb_ctrl_in();
        break;
    case EPSTATE_DATAOUT:
        usb_ctrl_out();
        break;
    }
}

void usb_setup_stall() {
    Ep0State.bState = EPSTATE_STALL;
    usb_write_reg(CSR0, SOPRDY | SDSTL);
}

void usb_setup_in() {
    Ep0State.bState = EPSTATE_DATAIN;
    usb_write_reg(CSR0, SOPRDY);
    usb_ctrl_in();
}

void usb_setup_out() {
    Ep0State.bState = EPSTATE_DATAOUT;
    usb_write_reg(CSR0, SOPRDY);
}

void usb_setup_status() {
    Ep0State.bState = EPSTATE_IDLE;
    usb_write_reg(CSR0, SOPRDY | DATEND);
}

void usb_ctrl_in() {
    uint8_t csr;
    uint8_t cnt;

    usb_write_reg(INDEX, 0);
    csr = usb_read_reg(CSR0);
    if (csr & IPRDY) return;

    cnt = Ep0State.wSize > EP0_SIZE ? EP0_SIZE : Ep0State.wSize;
    usb_write_fifo(FIFO0, Ep0State.pData, cnt);
    Ep0State.wSize -= cnt;
    Ep0State.pData += cnt;
    if (Ep0State.wSize == 0) {
        usb_write_reg(CSR0, IPRDY | DATEND);
        Ep0State.bState = EPSTATE_IDLE;
    } else {
        usb_write_reg(CSR0, IPRDY);
    }
}

void usb_ctrl_out() {
    uint8_t csr;
    uint8_t cnt;

    usb_write_reg(INDEX, 0);
    csr = usb_read_reg(CSR0);
    if (!(csr & OPRDY)) return;

    cnt = usb_read_fifo(FIFO0, Ep0State.pData);
    Ep0State.wSize -= cnt;
    Ep0State.pData += cnt;
    if (Ep0State.wSize == 0) {
        usb_write_reg(CSR0, SOPRDY | DATEND);
        Ep0State.bState = EPSTATE_IDLE;
    } else {
        usb_write_reg(CSR0, SOPRDY);
    }
}

void usb_bulk_intr_in(uint8_t *pData, uint8_t bSize, uint8_t ep) {
    usb_write_fifo((uint8_t)(FIFO0 + ep), pData, bSize);
    usb_write_reg(INCSR1, INIPRDY);
}

uint8_t usb_bulk_intr_out(uint8_t *pData, uint8_t ep) {
    uint8_t cnt;

    cnt = usb_read_fifo((uint8_t)(FIFO0 + ep), pData);
    usb_write_reg(OUTCSR1, 0);

    return cnt;
}

bool usb_bulk_intr_in_busy() {
    return (usb_read_reg(INCSR1) & INIPRDY);
}

bool usb_bulk_intr_out_ready() {
    return (usb_read_reg(OUTCSR1) & OUTOPRDY);
}
