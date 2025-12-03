
/* 

Main file should just create Car object, then run that Car object through the demo code.

No communication with external hardware needs to be coded here. 
*/


#include "Simulator.h"
#include "Motor.h"
#include "Car.h"

int main()
{
    // Check if pigpio get's initialized. 

    int choice = 0;
    std::cin >> choice;

    MecanumCar car;
//    car.cameraOn();
    runDemoPath(car);

    return 0;
}


