
/*
Here, we're assuming we have a max speed of 5 meters per second. That's 5 steps in the simulation each second.
At 100% speed, that will be 5 steps. At 80%, this will be 4 steps. 60%, 6 steps, ... 20% 1 step. 

For turning, we calculated that a 180 degree turn for a 161mm wide car has a circumference of 0.506 meters.

TURN_CIRCUMFERENCE = 2 * PI * (CAR_WIDTH/2) = 0.506 meters

For turn speed, since both motors are spinning in opposite directions, we get double the turn speed from the
motors. Because of this, and due to short turn distance, we should limit speeds at 0.25m/s. Thus giving a
turn speed of 0.5m/s. Because max speed is 5 m/s, this equates to 5% of max motor speeds.


The direction the car faces will be set to degrees, between 0 to 360 degrees counter-clockwise. Based on the 
turn speed calculated, every second we make around 0.99 complete turns, which we approximate to 1 turn.
We use this as a basis in our direction calculation. 

TIME_TURNING = (1000ms) * DEGREE_TURNED / 360

*/

#include "Car.h"

void runDemoPath(Car& car);
bool validate(int speed);


int main() {

    using namespace std::chrono_literals;
    using std::cout;
    using std::cin;

    Car car;
    int sentinel = 1;
    int choice = 0, demoChoice;
    int speed = 0;
    int time = 0;
    float distance = 0.0;
    float dir;

    cout << "\nDemo = 1 | Manual = 2\nEnter a Menu Choice: ";
    cin >> demoChoice;

    if(demoChoice == 9){
        return 0;
    }

    if(demoChoice == 1){
        runDemoPath(car);
        return 0;
    }
    else if(demoChoice == 2){
        do {
            car.getSim()->drawMap();

            cout << "Choose an action.\n1. Move forward\n2. Move backward\n3. Turn left\n4. Turn right\n5. Move diagonally forward-left"
            "\n6.Move diagonally forward-right\n7. Move diagonally back-left\n8. Move diagonally back-right\n9. Stop\n10. Turn on Camera\n11. Turn off Camera.\n12. Exit.\n" 
            << "MENU CHOICE: ";
            
            cin >> choice;

            switch(choice) {
                case 1:
                cout << "What speed will you go forward? (0 to 100): ";
                cin >> speed;

                cout << "For how long in seconds would you like to drive? (Decimal value only): ";
                cin >> time;
                if (validate(speed)) {
                     
                    cout << "Moving forwards at a speed of " << speed << " for " << time << "seconds" << endl;
                    car.moveForward(speed);
                    distance = 5 * (speed/100) * time;
                    car.getSim()->updateVal(0, -distance, 0);
                    
                    std::this_thread::sleep_for(time*1000ms);
                }
                else {
                    cout << "Invalid speed.\n";
                }
                break;

                case 2:
                cout << "What speed will you go backward? (0 to 100) ";
                cin >> speed;
                cout << "For how long in seconds would you like to drive? (Decimal value only): ";
                cin >> time;

                if (validate(speed)) {
                    cout << "Moving backwards at a speed of " << speed << " for " << time << "seconds" << endl;
                    car.moveBackward(speed);
                    distance = 5 * (speed/100) * time;
                    car.getSim()->updateVal(0, distance, 0);
                    std::this_thread::sleep_for(time*1000ms);
                }
                else {
                    cout << "Invalid speed.\n";
                }
                break;

                case 3:
                cout << "How many degrees will you turn left?";
                cin >> dir;

                while(dir > 360){
                    dir -= 360;
                }
                while(dir < 0){
                    dir += 360;
                }
            
                cout << "Turning " << dir << " degrees left." << endl;
                car.turnLeft();
                car.getSim()->updateVal(0, 0, -dir);
                std::this_thread::sleep_for(1000ms * dir / 360);
                break;

                case 4:
                cout << "How many degrees will you turn right?";
                cin >> dir;

                while(dir > 360){
                    dir -= 360;
                }
                while(dir < 0){
                    dir += 360;
                }

                cout << "Turning " << dir << " degrees left." << endl;
                car.turnLeft();
                car.getSim()->updateVal(0, 0, dir);
                std::this_thread::sleep_for(1000ms * dir / 360);

                break;

                case 5:
                cout << "What speed will you go forward-left? (0 to 100) ";
                cin >> speed;
                cout << "For how long in seconds would you like to drive? (Decimal value only): ";
                cin >> time;

                if (validate(speed)) {
                    cout << "Moving forward-left at a speed of " << speed << " for " << time << " seconds" << endl;
                    car.diagonalUpLeft(speed);
                    distance = 5 * (speed/100) * time * cos(45*3.141592/180);

                    car.getSim()->updateVal(-distance, -distance, 0);
                    std::this_thread::sleep_for(time*1000ms);
                }
                else {
                    cout << "Invalid speed.\n";
                }

                break;

                case 6:
                cout << "What speed will you go forward-right? (0 to 100) ";
                cin >> speed;
                cout << "For how long in seconds would you like to drive? (Decimal value only): ";
                cin >> time;

                if (validate(speed)) {
                    cout << "Moving forward-right at a speed of " << speed << " for " << time << " seconds" << endl;
                    car.diagonalUpLeft(speed);
                    distance = 5 * (speed/100) * time * cos(45*3.141592/180);

                    car.getSim()->updateVal(distance, -distance, 0);
                    std::this_thread::sleep_for(time*1000ms);
                }
                else {
                    cout << "Invalid speed.\n";
                }
                break;

                case 7:
                cout << "What speed will you go back-left? (0 to 100) ";
                cin >> speed;
                cout << "For how long in seconds would you like to drive? (Decimal value only): ";
                cin >> time;
                if (validate(speed)) {
                    cout << "Moving back-left at a speed of " << speed << " for " << time << " seconds" << endl;
                    car.diagonalUpLeft(speed);
                    distance = 5 * (speed/100) * time * cos(45*3.141592/180);

                    car.getSim()->updateVal(-distance, distance, 0);
                    std::this_thread::sleep_for(time*1000ms);
                }
                else {
                    cout << "Invalid speed.\n";
                }
                break;

                case 8:
                cout << "What speed will you go back-right? (0 to 100) ";
                cin >> speed;
                cout << "For how long in seconds would you like to drive? (Decimal value only): ";
                cin >> time;
                if (validate(speed)) {
                    cout << "Moving back-right at a speed of " << speed << " for " << time << " seconds" << endl;
                    car.diagonalUpLeft(speed);
                    distance = 5 * (speed/100) * time * cos(45*3.141592/180);

                    car.getSim()->updateVal(distance, distance, 0);
                    std::this_thread::sleep_for(time*1000ms);
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
                // car.cameraOn();
                break;

                case 11:
                cout << "Turning off camera.\n";
                // car.cameraOff();
                break;

                case 12:
                cout << "Exiting.\n";
                sentinel = 0;
                break;

                default:
                cout << "Invalid input.\n";
                
            }
        }
        while (sentinel == 1);
    }
    return 0;
}


bool validate(int speed) {
    return ((speed <= 100) && (speed >= 0));
}



void runDemoPath(Car& car){
    using namespace std::chrono_literals;

    int time = 1;
    int speed = 50;
    float distance;
    float dir = 90;

    // Moving forwards
    std::this_thread::sleep_for(800ms);

    distance = 5 * (speed/100) * time;
    std::cout << "Moving Forwards at speed of " << speed <<  " for " << time << " seconds" <<  endl;
    car.moveForward(speed);
    car.getSim()->updateVal(0, -distance, 0);
    car.getSim()->drawMap();
    std::this_thread::sleep_for(time*1000ms);

    // Moving backwards
    car.moveBackward(100);
    distance = 5 * (speed/100) * time;
    std::cout << "Moving Backwards at speed of " << speed <<  " for " << time << " seconds" <<  endl;
    car.moveForward(speed);
    car.getSim()->updateVal(0, distance, 0);
    car.getSim()->drawMap();
    std::this_thread::sleep_for(time*1000ms);

    // Turning left
    cout << "Turning " << dir << " degrees left." << endl;
    car.turnLeft();
    car.getSim()->updateVal(0, 0, -dir);
    car.getSim()->drawMap();
    std::this_thread::sleep_for(1000ms * dir / 360);


    // Turning right
    std::cout << "Turning right at speed of 75." << endl;
    car.turnLeft();
    car.getSim()->updateVal(0, 0, dir);
    car.getSim()->drawMap();
    std::this_thread::sleep_for(1000ms * dir / 360);


    // Moving back-left
    cout << "Moving back-left at a speed of " << speed << " for " << time << " seconds" << endl;
    car.diagonalUpLeft(speed);
    distance = 5 * (speed/100) * time * cos(45*3.141592/180);
    car.getSim()->updateVal(-distance, distance, 0);
    car.getSim()->drawMap();
    std::this_thread::sleep_for(time*1000ms);


    // Moving back-right
    cout << "Moving back-right at a speed of " << speed << " for " << time << " seconds" << endl;
    car.diagonalUpLeft(speed);
    distance = 5 * (speed/100) * time * cos(45*3.141592/180);
    car.getSim()->updateVal(distance, distance, 0);
    car.getSim()->drawMap();
    std::this_thread::sleep_for(time*1000ms);

    // Moving forward-right
    cout << "Moving forward-right at a speed of " << speed << " for " << time << " seconds" << endl;
    car.diagonalUpLeft(speed);
    distance = 5 * (speed/100) * time * cos(45*3.141592/180);
    car.getSim()->updateVal(distance, -distance, 0);
    car.getSim()->drawMap();
    std::this_thread::sleep_for(time*1000ms);

    cout << "Moving forward-left at a speed of " << speed << " for " << time << " seconds" << endl;
    car.diagonalUpLeft(speed);
    distance = 5 * (speed/100) * time * cos(45*3.141592/180);
    car.getSim()->updateVal(-distance, -distance, 0);
    car.getSim()->drawMap();
    std::this_thread::sleep_for(time*1000ms);

    car.stop();
    std::cout << "Stopping all motors.";
    std::this_thread::sleep_for(1000ms);
}