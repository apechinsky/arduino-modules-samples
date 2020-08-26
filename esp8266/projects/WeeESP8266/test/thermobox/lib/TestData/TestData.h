#ifndef TestData_h
#define TestData_h

#include <WString.h>

class TestData {

public:

    TestData(int* data, int length);

    int next();

private:

    int* data;

    int length;

    int index;

};
#endif
