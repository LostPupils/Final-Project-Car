/*
This is the DEMO instructions of our program. We will give the Car directions here. 

Should tell the car how fast it should go, what direction to go, and where to turn. 

*/

#include "Simulator.h"

void worldToMap(double x, double y, int& outRow, int& outCol)
{
    int centerRow = MAP_HEIGHT / 2;
    int centerCol = MAP_WIDTH / 2;

    outRow = centerRow - static_cast<int>(std::round(y));
    outCol = centerCol + static_cast<int>(std::round(x));
}


void runDemoPath(MecanumCar& car)
{
    using namespace std::chrono_literals;

    drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.moveForward(3.0);
    drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.strafeRight(4.0);
    drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.rotateLeft(90.0);
    drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.moveBackward(2.0);
    drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.strafeLeft(3.0);
    drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.rotateRight(45.0);
    drawMap(car);
    std::this_thread::sleep_for(800ms);

    car.stopAllMotors();
    drawMap(car);
    std::this_thread::sleep_for(800ms);
}

// void interactiveMode()
// {
//     MecanumCar car;
//     car.cameraOn();

//     char cmd = ' ';
//     double value = 0.0;

//     while (true) {
//         drawMap(car);
//         std::cout << "Commands:\n";
//         std::cout << "  w d  : move forward   by d units\n";
//         std::cout << "  s d  : move backward  by d units\n";
//         std::cout << "  a d  : strafe left    by d units\n";
//         std::cout << "  d d  : strafe right   by d units\n";
//         std::cout << "  q a  : rotate left    by a degrees\n";
//         std::cout << "  e a  : rotate right   by a degrees\n";
//         std::cout << "  c    : toggle camera on/off\n";
//         std::cout << "  x    : stop all motors\n";
//         std::cout << "  z    : quit\n\n";

//         std::cout << "Enter command: ";
//         std::cin >> cmd;

//         if (!std::cin) {
//             return;
//         }

//         if (cmd == 'z') {
//             break;
//         }

//         if (cmd == 'c') {
//             static bool cameraOnFlag = true;
//             if (cameraOnFlag) {
//                 car.cameraOff();
//                 cameraOnFlag = false;
//             } else {
//                 car.cameraOn();
//                 cameraOnFlag = true;
//             }
//             continue;
//         }

//         if (cmd == 'x') {
//             car.stopAllMotors();
//             continue;
//         }

//         std::cout << "Enter value: ";
//         std::cin >> value;
//         if (!std::cin) {
//             return;
//         }

//         switch (cmd) {
//         case 'w':
//             car.moveForward(value);
//             break;
//         case 's':
//             car.moveBackward(value);
//             break;
//         case 'a':
//             car.strafeLeft(value);
//             break;
//         case 'd':
//             car.strafeRight(value);
//             break;
//         case 'q':
//             car.rotateLeft(value);
//             break;
//         case 'e':
//             car.rotateRight(value);
//             break;
//         default:
//             std::cout << "Unknown command.\n";
//             break;
//         }
//     }
// }
