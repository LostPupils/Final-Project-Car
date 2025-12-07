/*
This will be where the actual software to hardware communication happens.
Will use pigpio.h to communicate with Raspberry-Pi pins. These pins will connect to L298N motor driver.

If connecting with Raspberry-Pi, uncomment the pigpio libary and its functions. You may need to change pin
values depending on how the Raspberry Pi is connected. 

*/

#ifndef CAR_MODEL_H
#define CAR_MODEL_H
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cmath>
#include <string>
// #include <pigpio.h>
#include <cmath>

using namespace std;

// Array of pins that are usable in Pi.
const int motPins[] = {4, 5, 6, 7, 8, 9, 10};
const int enPins[] = {8, 9};

class Motor {
private:
    std::string name;
    int speedPercent, pinNum1, pinNum2, EN;
    bool enabled;

public:
    Motor();
    Motor(const std::string& motorName, const int pin1, const int pin2, const int enPin);

    void setSpeed(int newSpeedPercent);
    int getSpeed() const;
    void setValues(string motorName, int pinIn1, int pinIn2, int enIn);
    void enable();
    void disable();

};

class PiCamera {
private:
    bool streaming;

public:
    PiCamera();

    void startStream();
    void stopStream();
    bool isStreaming() const;
};



#endif