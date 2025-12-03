#include "Car.h"

MecanumCar::MecanumCar() : frontLeft("front-left"), frontRight("front-right"), rearLeft("rear-left"), rearRight("rear-right"), camera(), x(0.0), y(0.0), headingDeg(0.0)
{
}


void MecanumCar::updatePose(double dx, double dy, double dThetaDeg)
{
    x += dx;
    y += dy;
    headingDeg += dThetaDeg;

    while(headingDeg >= 360.0) headingDeg -= 360;
    while(headingDeg < 0.0) headingDeg += 360;
}

void MecanumCar::moveForward(double distance)
{
    updatePose(0, distance, 0);
    rearLeft.setSpeed(50);
    rearRight.setSpeed(50);
    frontLeft.setSpeed(50);
    frontRight.setSpeed(50);
}

void MecanumCar::moveBackward(double distance)
{
    updatePose(0, -distance, 0);
    rearLeft.setSpeed(-50);
    rearRight.setSpeed(-50);
    frontLeft.setSpeed(-50);
    frontRight.setSpeed(-50);
}

void MecanumCar::strafeLeft(double distance)
{
    updatePose(-distance, 0, 0);
    rearLeft.setSpeed(50);
    rearRight.setSpeed(-50);
    frontLeft.setSpeed(-50);
    frontRight.setSpeed(50);
}

void MecanumCar::strafeRight(double distance)
{
    updatePose(distance, 0, 0);
    rearLeft.setSpeed(-50);
    rearRight.setSpeed(50);
    frontLeft.setSpeed(50);
    frontRight.setSpeed(-50);
}

void MecanumCar::rotateLeft(double angleDeg)
{
    updatePose(0, 0, angleDeg);
}

void MecanumCar::rotateRight(double angleDeg)
{
    updatePose(0, 0, -angleDeg);
}

void MecanumCar::stopAllMotors()
{
    rearLeft.setSpeed(0);
    rearRight.setSpeed(0);
    frontLeft.setSpeed(0);
    frontRight.setSpeed(0);
    frontLeft.disable();

    rearLeft.disable();
    rearRight.disable();
    frontLeft.disable();
    frontRight.disable();
}

void MecanumCar::cameraOn()
{
    camera.startStream();
}

void MecanumCar::cameraOff()
{
    camera.stopStream();
}

double MecanumCar::getX() const
{
    return x;
}

double MecanumCar::getY() const
{
    return y;
}

double MecanumCar::getHeadingDeg() const
{
    return headingDeg;
}

Motor MecanumCar::getFrontLeftMotor() const
{
    return frontLeft;
}

Motor MecanumCar::getFrontRightMotor() const
{
    return frontRight;
}

Motor MecanumCar::getRearLeftMotor() const
{
    return rearLeft;
}

Motor MecanumCar::getRearRightMotor() const
{
    return rearRight;
}

CarSnapshot MecanumCar::getSnapshot() const
{
    CarSnapshot snap;
    
    snap.x = getX();
    snap.y = getY();
    snap.headingDeg = getHeadingDeg();

    //snap.cameraStreaming = camera.isStreaming();
    
    snap.frontLeft.name = frontLeft.getName();
    snap.frontLeft.speedPercent = frontLeft.getSpeed();
    snap.frontLeft.enabled = frontLeft.isEnabled();

    snap.frontRight.name = frontRight.getName();
    snap.frontRight.speedPercent = frontRight.getSpeed();
    snap.frontRight.enabled = frontRight.isEnabled();

    snap.backLeft.name = backLeft.getName();
    snap.backLeft.speedPercent = backLeft.getSpeed();
    snap.backLeft.enabled = backLeft.isEnabled();

    snap.backRight.name = backRight.getName();
    snap.backRight.speedPercent = backRight.getSpeed();
    snap.backRight.enabled = backRight.isEnabled();

    return snap;
}


void MecanumCar::applyCommand(MovementCommand cmd, double value)
{

    switch(cmd){
        case MovementCommand::MoveForward:
            moveForward(value);
            break;
        case MovementCommand::MoveBackward:
            moveBackward(value);
            break;
        case MovementCommand::StrafeLeft:
            strafeLeft(value);
            break;
        case MovementCommand::StrafeRight:
            strafeRight(value);
            break;
        case MovementCommand::RotateLeft:
            rotateLeft(value);
            break;
        case MovementCommand::RotateRight:
            rotateRight(value);
            break;
        case MovementCommand::Stop:
            stopAllMotors();
            break;
    }

}