#ifndef GPIO_CONTROLLER_H
#define GPIO_CONTROLLER_H

#include <pigpio.h>

class GPIOController {
public:
    GPIOController();
    ~GPIOController();
    void setupPin(int pinNumber, int mode);
    void writePin(int pinNumber, int value);
    int readPin(int pinNumber);
};

#endif // GPIO_CONTROLLER_H
