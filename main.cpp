
/* 

Main file should just create Car object, then run that Car object through the demo code.

No communication with external hardware needs to be coded here. 
*/


#include "Simulator.h"
#include "Motor.h"
#include "Car.h"

// int main()
// {
//     // Check if pigpio get's initialized. 

//     int choice = 0;
//     std::cin >> choice;

//     MecanumCar car;
// //    car.cameraOn();
//     runDemoPath(car);

//     return 0;
// }


bool validate(int speed) {
    return ((speed <= 255) && (speed >= 0));
} 

int main() {
    MecanumCar car;
    int sentinel = 1;
    int choice = 0, simChoice;
    int speed = 0;

    cout << "Demo: 1\nManual: 2";
    cin >> simChoice;
    
    if(simChoice){
        runDemoPath(car);
        return 0;
    }


    do {
        cout << "Choose an action.\n1. Move forward\n2. Move backward\n3. Turn left\n4. Turn right\n5. Move diagonally forward-left"
        "\n6.Move diagonally forward-right\n7. Move diagonally back-left\n8. Move diagonally back-right\n9. Stop\n10. Turn on Camera\n11. Turn off Camera.\n12. Exit.";
        cin >> choice;
        switch(choice) {
            case 1:
            cout << "What speed will you go forward? (0 to 255) ";
            cin >> speed;
            if (validate(speed)) {
                cout << "Moving forward at a speed of " << speed << endl;
                car.moveForward(speed);
            }
            else {
                cout << "Invalid speed.\n";
            }
            break;

            case 2:
            cout << "What speed will you go backward? (0 to 255) ";
            cin >> speed;
            if (validate(speed)) {
                cout << "Moving backward at a speed of " << speed << endl;
                car.moveBackward(speed);
            }
            else {
                cout << "Invalid speed.\n";
            }
            break;

            case 3:
            cout << "What speed will you turn left? (0 to 255) ";
            cin >> speed;
            if (validate(speed)) {
                cout << "Turning left at a speed of " << speed << endl;
                car.turnLeft(speed);
            }
            else {
                cout << "Invalid speed.\n";
            }
            break;

            case 4:
            cout << "What speed will you turn right? (0 to 255) ";
            cin >> speed;
            if (validate(speed)) {
                cout << "Turning right at a speed of " << speed << endl;
                car.turnRight(speed);
            }
            else {
                cout << "Invalid speed.\n";
            }
            break;

            case 5:
            cout << "What speed will you go forward-left? (0 to 255) ";
            cin >> speed;
            if (validate(speed)) {
                cout << "Moving forward-left at a speed of " << speed << endl;
                car.diagonalUpLeft(speed);
            }
            else {
                cout << "Invalid speed.\n";
            }
            break;

            case 6:
            cout << "What speed will you go forward-right? (0 to 255) ";
            cin >> speed;
            if (validate(speed)) {
                cout << "Moving forward-right at a speed of " << speed << endl;
                car.diagonalUpRight(speed);
            }
            else {
                cout << "Invalid speed.\n";
            }
            break;

            case 7:
            cout << "What speed will you go back-left? (0 to 255) ";
            cin >> speed;
            if (validate(speed)) {
                cout << "Moving back-left at a speed of " << speed << endl;
                car.diagonalDownLeft(speed);
            }
            else {
                cout << "Invalid speed.\n";
            }
            break;

            case 8:
            cout << "What speed will you go back-right? (0 to 255) ";
            cin >> speed;
            if (validate(speed)) {
                cout << "Moving back-right at a speed of " << speed << endl;
                car.diagonalDownRight(speed);
            }
            else {
                cout << "Invalid speed.\n";
            }
            break;

            case 9:
            cout << "Stopping all motors.\n";
            car.stop();
            break;

            case 10:
            cout << "Turning on camera.\n";
            car.startCamera();

            case 11:
            cout << "Turning off camera.\n";
            car.stopCamera();

            case 12:
            cout << "Exiting.\n";
            sentinel = 0;
            break;

            default:
            cout << "Invalid input.\n";
        }
    }
    while (sentinel = 1);

    return 0;
}