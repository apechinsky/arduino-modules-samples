#include "ThingSpeak.h"

ThingSpeak::ThingSpeak(String apiKey, Network &network) : network(&network) {
    this->apiKey = apiKey;
}

bool ThingSpeak::send(int* values, int count) {

    String fields = String(""); 

    for (int i = 0; i < count; i++) {
        int fieldIndex = i + 1;
        fields = fields + "&field" + fieldIndex + "=" + values[i];
    } 

    String request = String("GET /update?api_key=") + apiKey + fields + " HTTP/1.1\r\n" + "Host: " + host + "\r\n\r\n";

    return network->send(host, port, request);
}

