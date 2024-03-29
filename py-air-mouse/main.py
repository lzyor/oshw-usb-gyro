#!/usr/bin/env python3

import struct, hid
import pyautogui as ag

vid = 0x34BF  # Change it for your device
pid = 0xFF03  # Change it for your device

report_struct = struct.Struct("Hhhhhhhh")

is_print_log = True

with hid.Device(vid, pid) as h:
    print(f"Device manufacturer: {h.manufacturer}")
    print(f"Product: {h.product}")
    print(f"Serial Number: {h.serial}")

    h.write(b"\x00" + b"\x01\x01\x01\x00\x00\x00" + b"\x00" * 10)
    while True:
        b = h.read(16, 100)
        report = report_struct.unpack(b)
        timestamp = report[0]
        temperature = report[1] / 256.0 + 25.0
        accel = [
            report[2] * 4.0 / 32768.0,
            report[3] * 4.0 / 32768.0,
            report[4] * 4.0 / 32768.0,
        ]
        gyro = [
            report[5] * 2000.0 / 32768.0,
            report[6] * 2000.0 / 32768.0,
            report[7] * 2000.0 / 32768.0,
        ]
        if is_print_log:
            print(f"Timestamp: {timestamp}ms")
            print(f"Temperature: {temperature:.2f}C")
            print(f"Accelerometer: {accel[0]:.2f} {accel[1]:.2f} {accel[2]:.2f}")
            print(f"Gyroscope: {gyro[0]:.2f} {gyro[1]:.2f} {gyro[2]:.2f}")

        ag.move(-gyro[2] / 4, gyro[0] / 4, _pause=False)
