#include <wiringPi.h>
#include <iostream>
#include <thread>
#include <chrono>

void motor_on(int pin) {
    digitalWrite(pin, HIGH);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    digitalWrite(pin, LOW);
}

int main()
{
    if(wiringPiSetup() == -1){
        std::cout << "Error initializing WiringPi" << std::endl;
        return 0;
    }
    
    int pin = 0;
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);

	for(pin=0;pin<64;pin++){
		std::thread t(motor_on, pin%4);
		t.join();
	}
    
    return 0;
}
