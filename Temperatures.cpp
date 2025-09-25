#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int closest = 10000;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t; cin.ignore();

        if (abs(t) < abs(closest) || (abs(t) == abs(closest) && t > closest)) {
            closest = t;
        }
    }

    cout << closest << endl;
    return 0;
}