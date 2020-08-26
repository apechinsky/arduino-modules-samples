#ifndef Network_h
#define Network_h

#include <WString.h>

class Network {

public:

    virtual bool send(String host, int port, String data);

};

#endif
