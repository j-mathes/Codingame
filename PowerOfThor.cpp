#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    int thorX = initialTX;
    int thorY = initialTY;
    
    // game loop
    while (1) {

        string xDir = "";
        string yDir = "";

        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        if (thorX > lightX) {
            xDir = "W";
            thorX--;
        } else if (thorX < lightX) {
            xDir = "E";
            thorX++;
        }
        
        if (thorY > lightY) {
            yDir = "N";
            thorY--;
        } else if (thorY < lightY) {
            yDir = "S";
            thorY++;
        }
        
        cout << yDir << xDir << endl;
    }
}
