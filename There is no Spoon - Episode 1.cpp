#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();

    vector<string> grid;
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line); // width characters, each either 0 or .
        grid.push_back(line);
    }

    // Обработка ячеяк
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Если ячейка является узлом
            if (grid[y][x] == '0') {
                // Инициализация не найденых соседей
                int right_x = -1, right_y = -1;
                int bottom_x = -1, bottom_y = -1;

                // Поиск правого соседа
                for (int rx = x + 1; rx < width; rx++) {
                    if (grid[y][rx] == '0') {
                        right_x = rx;
                        right_y = y;
                        break;
                    }
                }

                // Поиск нижнего соседа
                for (int by = y + 1; by < height; by++) {
                    if (grid[by][x] == '0') {
                        bottom_x = x;
                        bottom_y = by;
                        break;
                    }
                }

                // Вывод узла
                cout << x << " " << y << " "
                    << right_x << " " << right_y << " "
                    << bottom_x << " " << bottom_y << endl;
            }
        }
    }

    return 0;
}