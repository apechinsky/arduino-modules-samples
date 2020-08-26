#include "DHT.h"

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
#define DHTPIN 2     

DHT dht(DHTPIN, DHTTYPE);

unsigned long time = 0;
unsigned long count = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  count++;
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (getTimeSince(time) > 1000) {
      Serial.print(count);
      Serial.print(" \t");
      Serial.print("Humidity: ");
      Serial.print(h);
      Serial.print(" %\t");
      Serial.print("Temperature: ");
      Serial.print(t);
      Serial.println(" *C ");

      time = millis();
  }
}

unsigned long getTimeSince(unsigned long start) {
    return (unsigned long)(millis() - start);
}
