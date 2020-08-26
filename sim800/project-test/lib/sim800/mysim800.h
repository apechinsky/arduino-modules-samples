#ifndef _MYSIM800_H
#define _MYSIM800_H

#include "Arduino.h"
#include "CircularBuffer.h"

class MySim800 {

    public:
        const String OK = "OK";
        const String FAIL = "FAIL";
        const String ERROR = "ERROR";
        const String ALREADY_CONNECT = "ALREADY CONNECT";
        const String CRLF = "\r\n";
        const String CRLFCRLFOK = "\r\n\r\nOK";

        MySim800(Stream &stream, int resetPin) {
            this->stream = &stream;
            this->resetPin = resetPin;
        }

    private:
        
        Stream *stream;

        int resetPin;

}

#endif

