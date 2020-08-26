#!/bin/sh

#
# Flash esp-link (https://github.com/jeelabs/esp-link) firmware to ESP8266
#
# esp8266 wifi-serial bridge, outbound TCP, and arduino/AVR/LPC/NXP programmer.
#
# Scope: ESP-01 8Bit, 1Mb
# 

version=3.0.14
version=3.2.47

# Download firmware
# curl -L http://s3.voneicken.com/esp-link/esp-link-v3.0.14-g963ffbb.tgz | tar xzf -

cd esp-link-v${version}

# For 8Mbit / 1MByte modules the addresses are 0xFC000 and 0xFE000
# ESP-01
# esptool.py --port /dev/ttyUSB0 --baud 460800 --chip auto \
#     write_flash \
#     0x00000 boot_v1.6.bin \
#     0x01000 user1.bin \
#     0xFC000 esp_init_data_default.bin \
#     0xFE000 blank.bin

esptool.py --port /dev/ttyUSB0 --baud 460800 --chip auto \
    write_flash \
    0x00000 boot_v1.7.bin \
    0x01000 user1.bin \
    0xFC000 esp_init_data_default.bin \
    0xFE000 blank.bin
