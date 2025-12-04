/*
This is the DEMO instructions of our program. We will give the Car directions here. 

Should tell the car how fast it should go, what direction to go, and where to turn. 

*/

#include "Simulator.h"

// void worldToMap(double x, double y, int& outRow, int& outCol)
// {
//     int centerRow = MAP_HEIGHT / 2;
//     int centerCol = MAP_WIDTH / 2;

//     outRow = centerRow - static_cast<int>(std::round(y));
//     outCol = centerCol + static_cast<int>(std::round(x));
// }


void runDemoPath(MecanumCar& car)
{
    using namespace std::chrono_literals;

    // drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.moveForward(3.0);

    cout << "Moving Forward at speed of 3.0" << endl;
    // drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.strafeRight(4.0);
    cout << "Strafing Right at speeed of 4.0" << endl;
    // drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.rotateLeft(90.0);
    cout << "Rotating Left 90 degrees." << endl;
    // drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.moveBackward(2.0);
    cout << "Moving Backwards at speed of 2." << endl;
    // drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.strafeLeft(3.0);
    cout << "Strafing Left at speeed of 3.0" << endl;
    // drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.rotateRight(45.0);
    cout << "Rotating Left 45 degrees." << endl;
    // drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.stopAllMotors();
    cout << "Stopping all motors."
    // drawMap(car);
    std::this_thread::sleep_for(800ms);
}
