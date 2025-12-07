
#include "Motor.h"


Motor::Motor()
    : name("unnamed"),
      speedPercent(0),
      pinNum1(0),
      pinNum2(0),
      EN(0),
      enabled(false)
{
}

Motor::Motor(const std::string& motorName, const int pin1, const int pin2, const int enPin)
    : name(motorName),
      speedPercent(0),
      pinNum1(pin1),
      pinNum2(pin2),
      EN(enPin),
      enabled(false)
{
    // gpioSetMode(pinNum1, PI_OUTPUT);
    // gpioSetMode(pinNum2, PI_OUTPUT);
    // gpioSetMode(EN, PI_OUTPUT);
}
void Motor::setSpeed(int newSpeedPercent){
    if(newSpeedPercent > 100){
        speedPercent = 100;
        
    } else if(newSpeedPercent < -100){
        speedPercent = -100;
    } else{
        speedPercent = newSpeedPercent;
    }
    
    cout << "\n\nRASPBERRY PI PIN CONTROL:" << endl;
    if(newSpeedPercent < 0){

        cout << "Pin1 = 1\nPin2 = 2" << endl;
        // gpioWrite(pinNum1, 1);
        // gpioWrite(pinNum2, 0);
    }
    else if(newSpeedPercent > 0){
        cout << "Pin1 = 1\nPin2 = 2" << endl;
        // gpioWrite(pinNum1, 0);
        // gpioWrite(pinNum2, 1);
    } else{
        cout << "Pin1 = 1\nPin2 = 2" << endl;
        // gpioWrite(pinNum1, 0);
        // gpioWrite(pinNum2, 0);
    }
    
    int newSpeed = (speedPercent) * 255/100;

    cout << "Speed set to " << newSpeed << "\n" << endl;
    // gpioPWM(EN, abs(speedPercent) * 255 / 100);
}

void Motor::setValues(string motorName, int pinIn1, int pinIn2, int enIn){
    name = motorName;
    pinNum1 = pinIn1;
    pinNum2 = pinIn2;
    EN = enIn;
}

// int Motor::getSpeed() const
// {
//     return speedPercent;
// }

void Motor::enable()
{
    enabled = true;
}

void Motor::disable()
{
    enabled = false;
    speedPercent = 0;
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
