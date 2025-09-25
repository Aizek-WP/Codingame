#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int lightX, lightY, initialTX, initialTY;
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    int currentTX = initialTX;
    int currentTY = initialTY;

    while (1) {
        int remainingTurns;
        cin >> remainingTurns; cin.ignore();

        int diffX = lightX - currentTX;
        int diffY = lightY - currentTY;

        string direction = "";

        if (diffY > 0) {
            direction += "S";
            currentTY++;
        }
        else if (diffY < 0) {
            direction += "N";
            currentTY--;
        }

        if (diffX > 0) {
            direction += "E";
            currentTX++;
        }
        else if (diffX < 0) {
            direction += "W";
            currentTX--;
        }

        cout << direction << endl;
    }
}