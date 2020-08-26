#ifndef ESP8266Network_h
#define ESP8266Network_h

#include "Network.h"
#include "ESP8266.h"
#include <SoftwareSerial.h>

class ESP8266Network : public Network {

public:

    ESP8266Network(SoftwareSerial& stream, String ssid, String password);

    virtual bool send(String host, int port, String data);

private:

    String ssid;

    String password;

    ESP8266* wifi;

    SoftwareSerial* serial;

    bool wifiConnected = false;
    
    bool connectWifi();

    int failures = 0;

    void processFailure();
};

#endif
