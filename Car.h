
/*

Car files will manage all 4-motors. 
Will synchronize motors to move car forward, backward, left, or right.
EX: If moving forward the left motors will run Clockwise, and right will move coutner-clockwise.
(not sure if example is acurate, but you get the point)


This file will be used by Simulation.cpp. The simulation will give the car instructions,
and the Car files will give the Motor files instructions. 
*/


#include "Simulator.h"


class Car {
private:
    Motor frontLeft;
    Motor frontRight;
    Motor rearLeft;
    Motor rearRight;
    SimulateCar simulation;
    // PiCamera camera;

public:
    Car();
    SimulateCar* getSim(void);
    void moveForward(int speed);
    void moveBackward(int speed);
    void turnLeft();
    void turnRight();
    void diagonalUpLeft(int speed);
    void diagonalUpRight(int speed);
    void diagonalDownLeft(int speed);
    void diagonalDownRight(int speed);
    void stop();
    // void cameraOn();
    // void cameraOff();

};
