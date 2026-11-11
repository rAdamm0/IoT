#ifndef __LED__
#define __LED__

#include "Light.h"

class Led:public Light
{
private:
    int pin;
    bool isOn();
public:
    Led(int pin);
};
#endif