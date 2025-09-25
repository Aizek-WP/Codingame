#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    string stream_of_consciousness;
    getline(cin, stream_of_consciousness);
    int bust_threshold;
    cin >> bust_threshold; cin.ignore();

    // Количество карт
    int deck[11] = { 0 };
    for (int i = 1; i <= 10; i++) {
        if (i == 1) deck[i] = 4;
        else if (i == 10) deck[i] = 16;
        else deck[i] = 4;
    }

    vector<string> thoughts;
    stringstream ss(stream_of_consciousness);
    string item;

    while (getline(ss, item, '.')) {
        thoughts.push_back(item);
    }

    // Мысли
    for (const string& thought : thoughts) {
        bool valid = true;

        // Check
        for (char c : thought) {
            if (c != 'A' && c != 'K' && c != 'Q' && c != 'J' && c != 'T' &&
                (c < '2' || c > '9')) {
                valid = false;
                break;
            }
        }

        if (!valid) continue;

        // Process 
        for (char c : thought) {
            int value = 0;

            if (c == 'A') value = 1;
            else if (c == 'K' || c == 'Q' || c == 'J' || c == 'T') value = 10;
            else value = c - '0';

            if (deck[value] > 0) {
                deck[value]--;
            }
        }
    }

    // Подсчёт карт
    int total_remaining = 0;
    int favorable = 0;

    for (int i = 1; i <= 10; i++) {
        total_remaining += deck[i];
        if (i < bust_threshold) {
            favorable += deck[i];
        }
    }

    // Вычисление процента
    int percentage = 0;
    if (total_remaining > 0) {
        percentage = round((double)favorable * 100 / total_remaining);
    }

    cout << percentage << "%" << endl;

    return 0;
}