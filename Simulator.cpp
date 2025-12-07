/*
This is the DEMO instructions of our program. We will give the Car directions here. 

Should tell the car how fast it should go, what direction to go, and where to turn. 

*/

#include "Simulator.h"

static const int MAP_WIDTH  = 20;
static const int MAP_HEIGHT = 20;


SimulateCar::SimulateCar() : x(0), y(0), dir(0)
{
}

char SimulateCar::headingSymbol(float dirDegFromNorth)
{
    // Normalize to [0, 360)
    while (dirDegFromNorth < 0.0f)       dirDegFromNorth += 360.0f;
    while (dirDegFromNorth >= 360.0f)    dirDegFromNorth -= 360.0f;

    // 0°   = North
    // 90°  = East
    // 180° = South
    // 270° = West
    if (dirDegFromNorth >= 315.0f || dirDegFromNorth < 45.0f)
        return '^';   // facing roughly North
    else if (dirDegFromNorth >= 45.0f && dirDegFromNorth < 135.0f)
        return '>';   // facing roughly East
    else if (dirDegFromNorth >= 135.0f && dirDegFromNorth < 225.0f)
        return 'v';   // facing roughly South
    else
        return '<';   // facing roughly West
}

void SimulateCar::drawMap()
{
    // Round to nearest tile. Since movement is on a grid, coordinates need to be int values. 
    int xVal = static_cast<int>(round(x)) + MAP_WIDTH / 2;
    int yVal = static_cast<int>(round(y)) + MAP_HEIGHT / 2;
    float dirVal = dir;

    // Bounds check for car on map. If car moves out of map range, it will let the user know.
    if (xVal < 0 || xVal >= MAP_WIDTH || yVal < 0 || yVal >= MAP_HEIGHT) {
        cerr << "\nError: object position out of bounds\n";
        return;
    }

    // Determine object heading symbol. Either >, <, ^, or v.
    char objSymbol = headingSymbol(dirVal);

    int northX = xVal;
    int northY = yVal - 1;

    int southX = xVal;
    int southY = yVal + 1;

    int eastX  = xVal + 1;
    int eastY  = yVal;

    int westX  = xVal - 1;
    int westY  = yVal;

    bool hasNorth = (northY >= 0);
    bool hasSouth = (southY < MAP_HEIGHT);
    bool hasEast  = (eastX  < MAP_WIDTH);
    bool hasWest  = (westX  >= 0);



    // Below will create the grid. 
    cout << "    ";
    for (int i = 0; i < MAP_WIDTH; ++i) {
        cout << setw(3) << i;
    }
    cout << '\n';

    cout << "    ";
    for (int i = 0; i < MAP_WIDTH; ++i) {
        cout << setw(3) << '-';
    }
    cout << '\n';

    for (int j = 0; j < MAP_HEIGHT; ++j) {
        cout << setw(3) << j << "|";
        for (int i = 0; i < MAP_WIDTH; ++i) {
            char cell = '.';
            if (i == xVal && j == yVal) {
                cell = objSymbol;
            }
            else if (hasNorth && i == northX && j == northY) {
                cell = 'N';
            }
            else if (hasSouth && i == southX && j == southY) {
                cell = 'S';
            }
            else if (hasEast && i == eastX && j == eastY) {
                cell = 'E';
            }
            else if (hasWest && i == westX && j == westY) {
                cell = 'W';
            }

            cout << setw(3) << cell;
        }
        cout << '\n';
    }
}


void SimulateCar::updateVal(float xMove, float yMove, float dirMove)
{
    dir += dirMove;

    constexpr float DEG2RAD = 3.14159265358979f / 180.0f;
    float theta = dir * DEG2RAD;

    float cosT = cos(theta);
    float sinT = sin(theta);

    float dxMap = xMove * cosT - yMove * sinT;
    float dyMap = xMove * sinT + yMove * cosT;

    x += dxMap;
    y += dyMap;
}
