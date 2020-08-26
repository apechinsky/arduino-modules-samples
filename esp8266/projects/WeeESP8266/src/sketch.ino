#include "ESP8266.h"
#include <SoftwareSerial.h>

#define SSID        "ZOPO"
#define PASSWORD    "113355779900"
#define HOST_NAME   "api.thingspeak.com"
#define HOST_PORT   (80)


// RX | TX
SoftwareSerial esp = SoftwareSerial(A5, A4); 

ESP8266 wifi(esp, 115200);

void setup(void)
{
    Serial.begin(9600);

    Serial.println(wifi.getVersion().c_str());

    pinMode(A1, OUTPUT);
    digitalWrite(A1, HIGH);

    bool successful = joinAp();
    log("Join AP:", successful);
    
}
 
void loop(void) {

    bool successful = wifi.createTCP(HOST_NAME, HOST_PORT);
    log("create tcp: ", successful);

    if (!successful) {
        successful = joinAp();

        log("Join AP:", successful);

        if (!successful) {
            return;
        }
    }
    
    postThingspeak();
    /* getGoogle(); */
    
    successful = wifi.releaseTCP();
    log("release tcp: ", successful);
    
    delay(1000);
    
}

//
// AT+CIPSTART="TCP","api.thingspeak.com",80
// AT+CIPSEND=155
// GET /update?api_key=HAV79ZEO2CYDBOB8&field1=0&field2=0&field3=-127&field4=-127&field5=28&field6=-127&field7=0&field8=0 HTTP/1.1
// Host: api.thingspeak.com
//
void postThingspeak() {
    char *request = "GET /update?api_key=HAV79ZEO2CYDBOB8&field1=0&field2=0&field3=-127&field4=-127&field5=28&field6=-127&field7=0&field8=0 HTTP/1.1"
        "Host: api.thingspeak.com";

    wifi.send((const uint8_t*)request, strlen(request));

    uint8_t buffer[1024] = {0};

    uint32_t len = wifi.recv(buffer, sizeof(buffer), 10000);

    if (len > 0) {
        Serial.print("Received:[");
        for(uint32_t i = 0; i < len; i++) {
            Serial.print((char)buffer[i]);
        }
        Serial.print("]\r\n");
    }

}

void getGoogle() {
    char *hello = "GET / HTTP/1.1\r\nHost: google.com\r\nConnection: close\r\n\r\n";

    uint8_t buffer[1024] = {0};

    uint32_t len = wifi.recv(buffer, sizeof(buffer), 10000);

    if (len > 0) {
        Serial.print("Received:[");
        for(uint32_t i = 0; i < len; i++) {
            Serial.print((char)buffer[i]);
        }
        Serial.print("]\r\n");
    }
}

bool joinAp() {
    bool successful = wifi.joinAP(SSID, PASSWORD);

    if (successful) {
        Serial.print("IP: ");
        Serial.println( wifi.getLocalIP().c_str());       
    }

    return successful;
}

void log(String label, bool result) {
    Serial.print(label);
    Serial.println(result ? "ok" : "fail");
}
