#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over. But who cares really.
    cin >> N; cin.ignore();
    int x, y; //Batman's position
    cin >> x >> y; cin.ignore();

    int minX = 0, maxX = W - 1;
    int minY = 0, maxY = H - 1;

    // game loop
    while (1) {
        string bombDir;
        cin >> bombDir; cin.ignore();
        cerr << bombDir << endl;
        for (char c : bombDir)
        {
            switch (c)
            {
            case 'L':
                maxX = x - 1;
                x = (minX + maxX) / 2;
                break;
            case 'R':
                minX = x + 1;
                x = (minX + maxX) / 2;
                break;
            case 'U':
                maxY = y - 1;
                y = (minY + maxY) / 2;
                break;
            case 'D':
                minY = y + 1;
                y = (minY + maxY) / 2;
                break;
            }
        }

        cerr << minX << " <= " << maxX << endl;
        cerr << minY << " <= " << maxY << endl;

        cout << x << " " << y << endl;
    }
}