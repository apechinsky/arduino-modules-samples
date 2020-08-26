#include <SoftwareSerial.h>
 
// RX, TX
SoftwareSerial sim800 = SoftwareSerial(3, 4);
 
void setup() {
  Serial.begin(9600);
  sim800.begin(9600);
}
 
void loop() {
  if(sim800.available()){
    Serial.write(sim800.read());
  }

  if(Serial.available()){    
    sim800.write(Serial.read());
  }
}
