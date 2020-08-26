#ifndef ThingSpeak_h
#define ThingSpeak_h

#include "Network.h"

#define host "api.thingspeak.com"
#define port 80
// int port = 80;

class ThingSpeak {

public:

    ThingSpeak(String apiKey, Network &network);

    bool send(int* values, int count);

private:
    String apiKey;

    Network* network;
    
};

#endif
