#include "sdcc-short.h"

#include "usb-config.h"
#include "usb-hid.h"
#include "usb.h"
#include <stdint.h>

void usb_class_in();
void usb_class_out();

char code DEVICEDESC[18] = {
    0x12,       // bLength(18);
    0x01,       // bDescriptorType(Device);
    0x00, 0x02, // bcdUSB(2.00);
    0x00,       // bDeviceClass(0);
    0x00,       // bDeviceSubClass0);
    0x00,       // bDeviceProtocol(0);
    0x40,       // bMaxPacketSize0(64);
    0xbf, 0x34, // idVendor(34bf);
    0x03, 0xff, // idProduct(ff03);
    0x00, 0x01, // bcdDevice(1.00);
    0x01,       // iManufacturer(1);
    0x02,       // iProduct(2);
    0x00,       // iSerialNumber(0);
    0x01,       // bNumConfigurations(1);
};

char code CONFIGDESC[41] = {
    0x09,       // bLength(9);
    0x02,       // bDescriptorType(Configuration);
    0x29, 0x00, // wTotalLength(41);
    0x01,       // bNumInterfaces(1);
    0x01,       // bConfigurationValue(1);
    0x00,       // iConfiguration(0);
    0x80,       // bmAttributes(BUSPower);
    0x32,       // MaxPower(100mA);

    0x09, // bLength(9);
    0x04, // bDescriptorType(Interface);
    0x00, // bInterfaceNumber(0);
    0x00, // bAlternateSetting(0);
    0x02, // bNumEndpoints(2);
    0x03, // bInterfaceClass(HID);
    0x00, // bInterfaceSubClass(0);
    0x00, // bInterfaceProtocol(0);
    0x00, // iInterface(0);

    0x09,       // bLength(9);
    0x21,       // bDescriptorType(HID);
    0x01, 0x01, // bcdHID(1.01);
    0x00,       // bCountryCode(0);
    0x01,       // bNumDescriptors(1);
    0x22,       // bDescriptorType(HID Report);
    0x19, 0x00, // wDescriptorLength(25);

    0x07,       // bLength(7);
    0x05,       // bDescriptorType(Endpoint);
    0x81,       // bEndpointAddress(EndPoint1 as IN);
    0x03,       // bmAttributes(Interrupt);
    0x10, 0x00, // wMaxPacketSize(16);
    0x0a,       // bInterval(10ms);

    0x07,       // bLength(7);
    0x05,       // bDescriptorType(Endpoint);
    0x01,       // bEndpointAddress(EndPoint1 as OUT);
    0x03,       // bmAttributes(Interrupt);
    0x10, 0x00, // wMaxPacketSize(16);
    0x0a,       // bInterval(10ms);
};

/*
Input Report:
16  data
Output Report:
1   LEDs (D0:RGB_R D1:RGB_G D2:RGB_B)
*/
char code HIDREPORTDESC[25] = {
    0x06, 0x00, 0xFF, // Usage Page (Vendor Defined 0xFF00)
    0x09, 0x01,       // Usage (Undefined)
    0xA1, 0x01,       // Collection (Application)
    0x15, 0x00,       //   Logical Minimum (0)
    0x26, 0xFF, 0x00, //   Logical Maximum (255)
    0x75, 0x08,       //   Report Size (8)
    0x95, 0x10,       //   Report Count (16)
    0x09, 0x01,       //   Usage (Undefined)
    0x81, 0x02,       //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x09, 0x01,       //   Usage (Undefined)
    0x91, 0x02,       //   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0xC0              // End Collection
};

char code LANGIDDESC[4] = {
    0x04,
    0x03,
    0x09,
    0x04,
};

char code MANUFACTDESC[8] = {
    0x08,
    0x03,
    'S',
    0,
    'T',
    0,
    'C',
    0,
};

char code PRODUCTDESC[34] = {
    0x22,
    0x03,
    'S',
    0,
    'T',
    0,
    'C',
    0,
    ' ',
    0,
    'U',
    0,
    'S',
    0,
    'B',
    0,
    ' ',
    0,
    'K',
    0,
    'e',
    0,
    'y',
    0,
    'b',
    0,
    'o',
    0,
    'a',
    0,
    'r',
    0,
    'd',
    0,
};

char code SERIALDESC[18] = {
    0x12,
    0x03,
    '8',
    0,
    '2',
    0,
    '9',
    0,
    '4',
    0,
    '1',
    0,
    '0',
    0,
    '8',
    0,
    '5',
    0,
};

char code PACKET0[2] = {
    0,
    0,
};

char code PACKET1[2] = {
    1,
    0,
};

#ifdef EN_EP1IN
void usb_in_ep1() {
    uint8_t csr;

    usb_write_reg(INDEX, 1);
    csr = usb_read_reg(INCSR1);
    if (csr & INSTSTL) {
        usb_write_reg(INCSR1, INCLRDT);
    }
    if (csr & INUNDRUN) {
        usb_write_reg(INCSR1, 0);
    }
}
#endif

#ifdef EN_EP2IN
void usb_in_ep2() {
    uint8_t csr;

    usb_write_reg(INDEX, 2);
    csr = usb_read_reg(INCSR1);
    if (csr & INSTSTL) {
        usb_write_reg(INCSR1, INCLRDT);
    }
    if (csr & INUNDRUN) {
        usb_write_reg(INCSR1, 0);
    }
}
#endif

#ifdef EN_EP3IN
void usb_in_ep3() {
    uint8_t csr;

    usb_write_reg(INDEX, 3);
    csr = usb_read_reg(INCSR1);
    if (csr & INSTSTL) {
        usb_write_reg(INCSR1, INCLRDT);
    }
    if (csr & INUNDRUN) {
        usb_write_reg(INCSR1, 0);
    }
}
#endif

#ifdef EN_EP4IN
void usb_in_ep4() {
    uint8_t csr;

    usb_write_reg(INDEX, 4);
    csr = usb_read_reg(INCSR1);
    if (csr & INSTSTL) {
        usb_write_reg(INCSR1, INCLRDT);
    }
    if (csr & INUNDRUN) {
        usb_write_reg(INCSR1, 0);
    }
}
#endif

#ifdef EN_EP5IN
void usb_in_ep5() {
    uint8_t csr;

    usb_write_reg(INDEX, 5);
    csr = usb_read_reg(INCSR1);
    if (csr & INSTSTL) {
        usb_write_reg(INCSR1, INCLRDT);
    }
    if (csr & INUNDRUN) {
        usb_write_reg(INCSR1, 0);
    }
}
#endif

#ifdef EN_EP1OUT
void usb_out_ep1() {
    uint8_t csr;

    usb_write_reg(INDEX, 1);
    csr = usb_read_reg(OUTCSR1);
    if (csr & OUTSTSTL) {
        usb_write_reg(OUTCSR1, OUTCLRDT);
    }
    if (csr & OUTOPRDY) {
        usb_class_out();
    }
}
#endif

#ifdef EN_EP2OUT
void usb_out_ep2() {
    uint8_t csr;

    usb_write_reg(INDEX, 2);
    csr = usb_read_reg(OUTCSR1);
    if (csr & OUTSTSTL) {
        usb_write_reg(OUTCSR1, OUTCLRDT);
    }
    if (csr & OUTOPRDY) {
        usb_bulk_intr_out(Ep2OutBuffer, 2);
    }
}
#endif

#ifdef EN_EP3OUT
void usb_out_ep3() {
    uint8_t csr;

    usb_write_reg(INDEX, 2);
    csr = usb_read_reg(OUTCSR1);
    if (csr & OUTSTSTL) {
        usb_write_reg(OUTCSR1, OUTCLRDT);
    }
    if (csr & OUTOPRDY) {
        usb_bulk_intr_out(Ep2OutBuffer, 2);
    }
}
#endif

#ifdef EN_EP4OUT
void usb_out_ep4() {
    uint8_t csr;

    usb_write_reg(INDEX, 4);
    csr = usb_read_reg(OUTCSR1);
    if (csr & OUTSTSTL) {
        usb_write_reg(OUTCSR1, OUTCLRDT);
    }
    if (csr & OUTOPRDY) {
        usb_bulk_intr_out(Ep4OutBuffer, 4);
    }
}
#endif

#ifdef EN_EP5OUT
void usb_out_ep5() {
    uint8_t csr;

    usb_write_reg(INDEX, 5);
    csr = usb_read_reg(OUTCSR1);
    if (csr & OUTSTSTL) {
        usb_write_reg(OUTCSR1, OUTCLRDT);
    }
    if (csr & OUTOPRDY) {
        usb_bulk_intr_out(Ep5OutBuffer, 5);
    }
}
#endif

void usb_req_vendor() {
    usb_setup_stall();
}