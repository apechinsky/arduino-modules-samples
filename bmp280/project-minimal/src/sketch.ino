#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

void setup() {
    Serial.begin(9600);
    Serial.println(F("BME280 test"));

    bool status;
    
    // Default address: 0x76
    // Alternate address: 0x77
    // (you can also pass in a Wire library object like &Wire2)
    status = bme.begin(0x76);  
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }
    
    Serial.println();
}


void loop() { 
    printValues();
    delay(1000);
}


void printValues() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    float pressure = bme.readPressure();
    Serial.print("Pressure = ");
    Serial.print(pressure * 0.0075F);
    Serial.println(" Hg");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
}
