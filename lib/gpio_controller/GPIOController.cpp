#include "GPIOController.h"

GPIOController::GPIOController() {
    // Initialize pigpio
    if (gpioInitialise() < 0) {
        std::cerr << "Failed to initialize pigpio" << std::endl;
        exit(EXIT_FAILURE);
    }
}

GPIOController::~GPIOController() {
    // Cleanup pigpio
    gpioTerminate();
}

void GPIOController::setupPin(int pinNumber, int mode) {
    gpioSetMode(pinNumber, mode);
}

void GPIOController::writePin(int pinNumber, int value) {
    gpioWrite(pinNumber, value);
}

int GPIOController::readPin(int pinNumber) {
    return gpioRead(pinNumber);
}
