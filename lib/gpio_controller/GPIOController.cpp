/**
 * @file GPIOController.cpp
 * @author Joseph Joel
 * @brief Contains all the function needed to actuate the motors on the gloves.
 * @version 0.1
 * @date 2023-08-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "GPIOController.h"

/**
 * @brief Construct a new GPIOController::GPIOController object
 * 
 */
GPIOController::GPIOController() {
    // Initialize pigpio
    if (gpioInitialise() < 0) {
        std::cerr << "Failed to initialize pigpio" << std::endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Destroy the GPIOController::GPIOController object
 * 
 */
GPIOController::~GPIOController() {
    // Cleanup pigpio
    gpioTerminate();
}

/**
 * @brief The functions sets the pins mode.
 * 
 * @param pinNumber 
 * @param mode 
 */
void GPIOController::setupPin(int pinNumber, int mode) {
    gpioSetMode(pinNumber, mode);
}

/**
 * @brief This functions sets the pin to HIGH or LOW.
 * 
 * @param pinNumber 
 * @param value 
 */
void GPIOController::writePin(int pinNumber, int value) {
    gpioWrite(pinNumber, value);
}

/**
 * @brief This function reads the pin's state.
 * 
 * @param pinNumber 
 * @return int 
 */
int GPIOController::readPin(int pinNumber) {
    return gpioRead(pinNumber);
}
