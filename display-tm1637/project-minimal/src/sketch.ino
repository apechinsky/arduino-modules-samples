#include <Arduino.h>

#include <TM1637Display.h>

#define CLK_PIN 4
#define DIO_PIN 5

// Celsius symbol
const uint8_t CELSIUS[] = { 0, 0, 0, SEG_A | SEG_B | SEG_F | SEG_G };

// h (humidity) symbol
const uint8_t HUMIDITY[] = { 0, 0, 0, SEG_C | SEG_E | SEG_F | SEG_G };

TM1637Display display(CLK_PIN, DIO_PIN);

int brightness = 0x0a;
void setup() {
    Serial.begin(9600);
    display.clear();
    display.setBrightness(brightness);
    display.setSegments(CELSIUS);
    display.showNumberDec(brightness, false, 3);

}

void loop() {
    brightness = (brightness + 1) % 4;
    display.setBrightness(brightness);
    display.showNumberDec(brightness, false, 3);
    /* Serial.println(brightness); */
    /* display.setBrightness(brightness); */
    /* display.setSegments(CELSIUS); */
    /* display.showNumberDec(23, false, 3); */
    Serial.println(brightness);
    delay(500);
}

