#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
    while (1) {

        int max_index = 0;
        int max_value = 0;

        for (int i = 0; i < 8; i++) {
            int mountain_h;
            cin >> mountain_h; cin.ignore();
            if (mountain_h > max_value) {
                max_value = mountain_h;
                max_index = i;
            }
        }

        cout << max_index << endl;
    }
}