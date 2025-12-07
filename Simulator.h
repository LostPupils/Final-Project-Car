

#include "Motor.h"



class SimulateCar{
private:
    float x;
    float y;
    float dir;
    char coor;

public:
    SimulateCar();


    void drawMap();
    char headingSymbol(float dirDegFromNorth);

    void updateVal(float xMove, float yMove, float dirMove);
};

