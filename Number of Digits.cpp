#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n;
    cin >> n; cin.ignore();
    int k;
    cin >> k; cin.ignore();

    long long count = 0;

    for (long long digit_place = 1; digit_place <= n; digit_place *= 10) {

        long long full_cycles = n / (digit_place * 10);

        long long remainder = n % (digit_place * 10);

        count += full_cycles * digit_place;

        // Обработка остатка
        int current_digit = (remainder / digit_place) % 10;

        if (current_digit > k) {

            count += digit_place;
        }
        else if (current_digit == k) {

            count += (remainder % digit_place) + 1;
        }
    }
    cout << count << endl;
}
