/**
 * @file GPIOController.h
 * @author Joseph Joel
 * @brief The file declares all the headers and functions to actuate the motors on the gloves.
 * @version 0.1
 * @date 2023-08-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

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
