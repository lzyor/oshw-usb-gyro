#pragma once

#include "usb-config.h"

#include "sdcc-short.h"
#include "stc8h.h"
#include <stdbool.h>
#include <stdint.h>

#define GET_REPORT 0x01
#define GET_IDLE 0x02
#define GET_PROTOCOL 0x03
#define SET_REPORT 0x09
#define SET_IDLE 0x0A
#define SET_PROTOCOL 0x0B

#define DESC_HIDREPORT 0x22

void usb_req_class();

void usb_class_in();
void usb_class_out();

void usb_get_report();
void usb_set_report();
void usb_get_idle();
void usb_set_idle();
void usb_get_protocol();
void usb_set_protocol();

extern uint8_t bHidIdle;
extern uint8_t hidbuf[64];
