#!/bin/sh


FIRMWARE=.pioenvs/uno/firmware.hex

ESPLINK_HOME=/home/apechinsky/Arduino/esp8266/firmware/esp-link/esp-link-v3.0.14
ESP_IP=192.168.100.150

$ESPLINK_HOME/avrflash -v $ESP_IP $FIRMWARE

ARDUINO_HOME=/opt/arduino-1.8.8

# $ARDUINO_HOME/hardware/tools/avr/bin/avrdude \
#   -DV -patmega328p \
#   -Pnet:$ESP_IP:23 \
#   -carduino -b57600 \
#   -U flash:w:$FIRMWARE:i\
#   -C $ARDUINO_HOME/hardware/tools/avr/etc/avrdude.conf 

$ARDUINO_HOME/hardware/tools/avr/bin/avrdude \
  -DV -patmega328p \
  -Pnet:$ESP_IP:23 \
  -carduino -b57600 \
  -U flash:w:$FIRMWARE:i\
  -C $ARDUINO_HOME/hardware/tools/avr/etc/avrdude.conf 
