#include <Wire.h>
 
//
// Scans I2C wire to find devices and their addresses.
//

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("I2C Scanner");
}
 
 
void loop() {

    Serial.println("\nScanning...");

    int count = 0;

    for(byte address = 1; address < 127; address++ ) {
        // The i2c_scanner uses the return value of
        // the Write.endTransmisstion to see if
        // a device did acknowledge to the address.
        Wire.beginTransmission(address);

        int error = Wire.endTransmission();

        if (error == 0) {
            count++;

            Serial.print("I2C device found at address 0x");
            printHex(address);
            Serial.println(" !");
        }
        else if (error == 4) {
            Serial.print("Unknown error at address 0x");
            printHex(address);
            Serial.println(" !");
        }    
    }

    Serial.print("Devices found: ");
    Serial.print(count);
    Serial.println();

    delay(2000);
}

void printHex(byte value) {
    if (value < 16) {
        Serial.print("0");
    }
    Serial.print(value, HEX);
}
