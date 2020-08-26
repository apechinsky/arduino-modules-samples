#include "ESP8266Network.h"
#include "Network.h"
#include "ThingSpeak.h"


#define SEND_DATA_RATE  10000L

// first parameter  -  RX arduino ( TX - ESP)
// second parameter -  TX arduino ( RX - ESP)
SoftwareSerial esp = SoftwareSerial(A5, A4); 

ESP8266Network network = ESP8266Network(esp, "ZOPO", "113355779900");

ThingSpeak thingSpeak = ThingSpeak("HAV79ZEO2CYDBOB8", network);

void setup() {
    Serial.begin(9600);

    Serial.println(F("Initializing"));
}
 
void loop() {
    
    sendToThingSpeak();

    delay(1000);

}

bool sendToThingSpeak() {
    Serial.println(F("Sending data to ThingSpeak"));

    int values[] = {
        10, 
        12, 
        13, 
        14, 
        15, 
        17, 
        18,
        0,
    };

    bool successful = thingSpeak.send(values, sizeof(values) / sizeof(int));

    // success is always false despite real send status. This is why 'successful' flag is ignored.
    Serial.println(successful ? "Send OK" : "Send Failed");

    return successful;
}


