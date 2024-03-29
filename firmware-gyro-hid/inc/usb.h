#ifndef __USB_H__
#define __USB_H__

#include "sdcc-short.h"
#include "stc8h.h"
#include <stdbool.h>
#include <stdint.h>

#define DESC_DEVICE 0x01
#define DESC_CONFIGURATION 0x02
#define DESC_STRING 0x03
#define DESC_HIDREPORT 0x22

#define IN_DIRECT 0x80  // device to host
#define OUT_DIRECT 0x00 // host to device
#define DIRECT_MASK 0x80

#define STANDARD_REQUEST 0x00
#define CLASS_REQUEST 0x20
#define VENDOR_REQUEST 0x40
#define REQUEST_MASK 0x60

#define DEVICE_RECIPIENT 0x00
#define INTERFACE_RECIPIENT 0x01
#define ENDPOINT_RECIPIENT 0x02
#define RECIPIENT_MASK 0x0f

#define DEVICE_REMOTE_WAKEUP 0x01
#define ENDPOINT_HALT 0x00

#define EP1_IN 0x81
#define EP1_OUT 0x01
#define EP2_IN 0x82
#define EP2_OUT 0x02
#define EP3_IN 0x83
#define EP3_OUT 0x03
#define EP4_IN 0x84
#define EP4_OUT 0x04
#define EP5_IN 0x85
#define EP5_OUT 0x05

#define DEVSTATE_ATTACHED 0
#define DEVSTATE_POWERED 1
#define DEVSTATE_DEFAULT 2
#define DEVSTATE_ADDRESS 3
#define DEVSTATE_CONFIGURED 4
#define DEVSTATE_SUSPENDED 5

#define EPSTATE_IDLE 0
#define EPSTATE_HALT 1
#define EPSTATE_STATUS 2
#define EPSTATE_DATAIN 3
#define EPSTATE_DATAOUT 4
#define EPSTATE_STALL 5

typedef struct
{
    uint8_t bmRequestType;
    uint8_t bRequest;
    uint8_t wValueL;
    uint8_t wValueH;
    uint8_t wIndexL;
    uint8_t wIndexH;
    uint16_t wLength;
} setup_t;

typedef struct
{
    uint8_t bState;
    uint16_t wSize;
    uint8_t *pData;
} epstate_t;

void usb_isr() interrupt(USB_VECTOR);

void usb_init();
uint8_t usb_read_fifo(uint8_t fifo, uint8_t *pdat);
void usb_write_fifo(uint8_t fifo, uint8_t *pdat, uint8_t cnt);

void usb_setup_stall();
void usb_setup_in();
void usb_setup_out();
void usb_setup_status();

void usb_ctrl_in();
void usb_ctrl_out();
void usb_bulk_intr_in(uint8_t *pData, uint8_t bSize, uint8_t ep);
uint8_t usb_bulk_intr_out(uint8_t *pData, uint8_t ep);
bool usb_bulk_intr_in_busy();
bool usb_bulk_intr_out_ready();

void usb_resume();
void usb_reset();
void usb_suspend();
void usb_setup();

inline uint8_t usb_read_reg(uint8_t addr) {
    uint8_t dat;

    while (USBADR & 0x80)
        ;
    USBADR = addr | 0x80;
    while (USBADR & 0x80)
        ;
    dat = USBDAT;

    return dat;
}

inline void usb_write_reg(uint8_t addr, uint8_t dat) {
    while (USBADR & 0x80)
        ;
    USBADR = addr & 0x7f;
    USBDAT = dat;
}

extern uint8_t data DeviceState;
extern setup_t data Setup;
extern epstate_t data Ep0State;
extern uint8_t data InEpState;
extern uint8_t data OutEpState;

extern uint8_t xdata UsbBuffer[256];

#endif
