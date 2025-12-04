/*
This will be where the actual software to hardware communication happens.
Will use pigpio.h to communicate with Raspberry-Pi pins. These pins will connect to L298N motor driver.

*/

#ifndef CAR_MODEL_H
#define CAR_MODEL_H

#include <iostream.
#include <string>
#include <pigpio.h>
#include <cmath>

const int motPins[] = {4, 5, 6, 7, 8, 9, 10};
const int enPins[] = {8, 9};

double speedMotor1 = 0, speedMotor2 = 0;

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

    void enable();
    void disable();
    bool isEnabled() const;

    std::string getName() const;
};

// class PiCamera {
// private:
//     bool streaming;

// public:
//     PiCamera();

//     void startStream();
//     void stopStream();
//     bool isStreaming() const;
// };

enum class MovementCommand {
    MoveForward,
    MoveBackward,
    StrafeLeft,
    StrafeRight,
    RotateLeft,
    RotateRight,
    Stop
};

struct MotorSnapshot {
    std::string name;
    int speedPercent;
    bool enabled;
};

struct CarSnapshot {
    double x;
    double y;
    double headingDeg;
    bool cameraStreaming;

    MotorSnapshot frontLeft;
    MotorSnapshot frontRight;
    MotorSnapshot rearLeft;
    MotorSnapshot rearRight;
};
