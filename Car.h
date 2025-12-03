
/*

Car files will manage all 4-motors. 
Will synchronize motors to move car forward, backward, left, or right.
EX: If moving forward the left motors will run Clockwise, and right will move coutner-clockwise.
(not sure if example is acurate, but you get the point)


This file will be used by Simulation.cpp. The simulation will give the car instructions,
and the Car files will give the Motor files instructions. 
*/


#include "Motor.h"

class MecanumCar {
private:
    Motor frontLeft;
    Motor frontRight;
    Motor rearLeft;
    Motor rearRight;
//   PiCamera camera;

    double x;
    double y;
    double headingDeg;
    
    void updatePose(double dx, double dy, double dThetaDeg);

public:
    MecanumCar();

    void moveForward(double distance);
    void moveBackward(double distance);
    void strafeLeft(double distance);
    void strafeRight(double distance);
    void rotateLeft(double angleDeg);
    void rotateRight(double angleDeg);

    void stopAllMotors();

    void cameraOn();
    void cameraOff();

    double getX() const;
    double getY() const;
    double getHeadingDeg() const;

    Motor getFrontLeftMotor() const;
    Motor getFrontRightMotor() const;
    Motor getRearLeftMotor() const;
    Motor getRearRightMotor() const;

    void applyCommand(MovementCommand cmd, double value);
    CarSnapshot getSnapshot() const;
};

void updatePose