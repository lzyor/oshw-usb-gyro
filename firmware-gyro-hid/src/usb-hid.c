#include "usb-hid.h"
#include "usb.h"

uint8_t bHidIdle;
uint8_t hidbuf[64];

void usb_req_class() {
    switch (Setup.bRequest) {
    case GET_REPORT:
        usb_get_report();
        break;
    case SET_REPORT:
        usb_set_report();
        break;
    case GET_IDLE:
        usb_get_idle();
        break;
    case SET_IDLE:
        usb_set_idle();
        break;
    case GET_PROTOCOL:
        usb_get_protocol();
        break;
    case SET_PROTOCOL:
        usb_set_protocol();
        break;
    default:
        usb_setup_stall();
        return;
    }
}

void usb_get_report() {
    if ((DeviceState != DEVSTATE_CONFIGURED) ||
        (Setup.bmRequestType != (IN_DIRECT | CLASS_REQUEST | INTERFACE_RECIPIENT))) {
        usb_setup_stall();
        return;
    }

    Ep0State.pData = hidbuf;
    Ep0State.wSize = Setup.wLength;

    usb_setup_in();
}

void usb_set_report() {
    if ((DeviceState != DEVSTATE_CONFIGURED) ||
        (Setup.bmRequestType != (OUT_DIRECT | CLASS_REQUEST | INTERFACE_RECIPIENT))) {
        usb_setup_stall();
        return;
    }

    Ep0State.pData = hidbuf;
    Ep0State.wSize = Setup.wLength;

    usb_setup_out();
}

void usb_get_idle() {
    if ((DeviceState != DEVSTATE_CONFIGURED) ||
        (Setup.bmRequestType != (IN_DIRECT | CLASS_REQUEST | INTERFACE_RECIPIENT))) {
        usb_setup_stall();
        return;
    }

    Ep0State.pData = &bHidIdle;
    Ep0State.wSize = 1;

    usb_setup_in();
}

void usb_set_idle() {
    if ((DeviceState != DEVSTATE_CONFIGURED) ||
        (Setup.bmRequestType != (OUT_DIRECT | CLASS_REQUEST | INTERFACE_RECIPIENT))) {
        usb_setup_stall();
        return;
    }

    bHidIdle = Setup.wValueH;

    usb_setup_status();
}

void usb_get_protocol() {
    usb_setup_stall();
}

void usb_set_protocol() {
    usb_setup_stall();
}
