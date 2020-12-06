#include <MHZ19.h>

MHZ19 mhz19;

void setup() {
    // Option 1. Pass RX, TX pins and baud speed
    mhz19.begin(A0, A1, 9600);

    // Option 2. Existing serial object reference (hardware or software)
//    mhz19a.begin(&Serial);
}
 
void loop() {
    int ppm = mhz19.readCO2();

    Serial.println(ppm);

    delay(5000);
}

