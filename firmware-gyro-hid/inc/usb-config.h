#pragma once

#include "sdcc-short.h"

#define EP0_SIZE 64
#define EP1IN_SIZE 64
#define EP1OUT_SIZE 64

#define EN_EP1IN
#define EN_EP1OUT

#define CONFIG_HID 1
#define CONFIG_HANDLE_USB_ISR_START()
#define CONFIG_HANDLE_USB_ISR_END()

extern char code DEVICEDESC[18];
extern char code CONFIGDESC[41];
extern char code LANGIDDESC[4];
extern char code MANUFACTDESC[8];
extern char code PRODUCTDESC[34];
extern char code SERIALDESC[18];

extern char code HIDREPORTDESC[25];
extern char code PACKET0[2];
extern char code PACKET1[2];

void usb_req_class();
void usb_req_vendor();

void usb_in_ep1();
void usb_in_ep2();
void usb_in_ep3();
void usb_in_ep4();
void usb_in_ep5();
void usb_out_ep1();
void usb_out_ep2();
void usb_out_ep3();
void usb_out_ep4();
void usb_out_ep5();
