#include "Car.h"

Car::Car()
    // camera(), x(0.0), y(0.0), headingDeg(0.0)
{
    frontLeft.setValues("front-left", motPins[0], motPins[1], enPins[2]);
    frontRight.setValues("front-right", motPins[3], motPins[4], enPins[5]);
    rearLeft.setValues("rear-left", motPins[6], motPins[7], enPins[8]); 
    rearRight.setValues("rear-right", motPins[9], motPins[10], enPins[11]); 
}

void Car::moveForward(int speed) {
    frontLeft.setSpeed(speed);
    frontRight.setSpeed(speed);
    rearLeft.setSpeed(speed);
    rearRight.setSpeed(speed);
    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void Car::moveBackward(int speed) {
    frontLeft.setSpeed(-speed);
    frontRight.setSpeed(-speed);
    rearLeft.setSpeed(-speed);
    rearRight.setSpeed(-speed);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void Car::turnLeft() {
    frontLeft.setSpeed(-5);
    frontRight.setSpeed(5);
    rearLeft.setSpeed(-5);
    rearRight.setSpeed(5);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void Car::turnRight() {
    frontLeft.setSpeed(5);
    frontRight.setSpeed(-5);
    rearLeft.setSpeed(5);
    rearRight.setSpeed(-5);


    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void Car::diagonalUpLeft(int speed) {
    frontRight.setSpeed(speed);
    rearLeft.setSpeed(speed);

    frontRight.enable();
    rearLeft.enable();
}

void Car::diagonalUpRight(int speed) {
    frontLeft.setSpeed(speed);
    rearRight.setSpeed(speed);

    frontLeft.enable();
    rearRight.enable();
}

void Car::diagonalDownLeft(int speed) {
    frontLeft.setSpeed(-speed);
    rearRight.setSpeed(-speed);

    frontLeft.enable();
    rearRight.enable();
}

void Car::diagonalDownRight(int speed) {
    frontRight.setSpeed(-speed);
    rearLeft.setSpeed(-speed);

    frontRight.enable();
    rearLeft.enable();
}

void Car::stop() {
    frontLeft.disable();
    frontRight.disable();
    rearLeft.disable();
    rearRight.disable();
}

// void Car::cameraOn()
// {
//     camera.startStream();
// }

// void Car::cameraOff()
// {
//     camera.stopStream();
// }


SimulateCar* Car::getSim(void){
    return &simulation;
}


