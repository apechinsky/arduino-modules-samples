#include "TestData.h"

#include "Arduino.h"

TestData::TestData(int* data, int length) {
    this->data = data;
    this->length = length;
    this->index = 0;
}


int TestData::next() {
    int result = data[index];
    index = ++index % length;
    return result;
}
