#include "ESP8266Network.h"
#include <Arduino.h>

ESP8266Network::ESP8266Network(SoftwareSerial& stream, String ssid, String password) {

    this->ssid = ssid;
    this->password = password;

    wifi = new ESP8266(stream, 115200);
}

bool ESP8266Network::send(String host, int port, String data) { 
    if (!wifiConnected) {
        Serial.print(F("Connect WiFi. "));
        wifiConnected = connectWifi();

        Serial.println(wifiConnected ? F("Ok") : F("Failed"));

        if (!wifiConnected) {
            processFailure();
            return false;
        }
    }

    Serial.print(F("Connect "));
    Serial.print(host);

    bool hostConnected = wifi->createTCP(host, port);

    Serial.println(hostConnected ? F(" Ok") : F(" Failed"));

    if (!hostConnected) {
        processFailure();
        return false;
    }

    Serial.print(F("Send: "));
    Serial.println(data);
    bool successful = wifi->send(data);

    // wifi->releaseTCP();
    
    if (successful) {
        failures = 0;
    }

    return successful;
}

void ESP8266Network::processFailure() {
    failures++;

    if (failures > 5) {
        failures = 0;
        wifiConnected = false;
        wifi->restart();
    }
}

bool ESP8266Network::connectWifi() {
    wifi->setOprToStation();

    bool successful = wifi->joinAP(ssid, password);

    if (successful) {
        wifi->disableMUX();
    } 


    return successful;
}
