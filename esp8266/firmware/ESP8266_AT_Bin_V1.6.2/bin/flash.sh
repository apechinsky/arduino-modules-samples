#!/bin/sh

# esptool.py write_flash \
#     0x00000 boot_v1.7.bin \
#     0x01000 at/1024+1024/user1.2048.new.5.bin \
#     0x7C000 esp_init_data_default_v08.bin \
#     0x7E000 blank.bin

# Works
esptool.py write_flash \
    0x00000 boot_v1.7.bin \
    0x01000 at/512+512/user1.1024.new.2.bin \
    0xFC000 esp_init_data_default_v08.bin \
    0x7E000 blank.bin \
    0xFE000 blank.bin
