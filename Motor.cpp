
#include "Motor.h"


Motor::Motor() : name("unnamed"), speedPercent(0), enabled(false), pinNum1(0), pinNum2(0)
{
}

Motor::Motor(const std::string& motorName, const int pin1, const int pin2, const int enPin)
    : name(motorName), speedPercent(0), enabled(false), pinNum1(pin1), pinNum2(pin2), EN(enPin)
{
    gpioSetMode(pinNum1, PI_OUTPUT);
    gpioSetMode(pinNum2, PI_OUTPUT);
    gpioSetMode(EN, PI_OUTPUT);
}

void Motor::setSpeed(int newSpeedPercent){
    if(newSpeedPercent > 100){
        speedPercent = 100;
    } else if(newSpeedPercent < -100){
        speedPercent = -100;
    } else{
        speedPercent = newSpeedPercent;
    }

    if(newSpeedPercent < 0){
        gpioWrite(pinNum1, 1);
        gpioWrite(pinNum2, 0);
    }
    else if(newSpeedPercent > 0){
        gpioWrite(pinNum1, 0);
        gpioWrite(pinNum2, 1);
    } else{
        gpioWrite(pinNum1, 0);
        gpioWrite(pinNum2, 0);
    }
    
    gpioPWM(EN, abs(speedPercent) * 255 / 100);
}

int Motor::getSpeed() const
{
    return speedPercent;
}

void Motor::enable()
{
    enabled = true;
}

void Motor::disable()
{
    enabled = false;
    speedPercent = 0;
}

bool Motor::isEnabled() const
{
    return enabled;
}

std::string Motor::getName() const
{
    return name;
}

// PiCamera::PiCamera()
//     : streaming(false)
// {
// }

// void PiCamera::startStream()
// {
//     streaming = true;
// }

// void PiCamera::stopStream()
// {
//     streaming = false;
// }

// bool PiCamera::isStreaming() const
// {
//     return streaming;
// }
