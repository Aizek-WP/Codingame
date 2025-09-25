#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

void dfs(int x, int y, int n, vector<string>& grid, vector<vector<bool>>& visited,
    vector<pair<int, int>>& island_blocks) {
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (visited[y][x] || grid[y][x] != '#') return;

    visited[y][x] = true;
    island_blocks.push_back({ x, y });

    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i], n, grid, visited, island_blocks);
    }
}

int main()
{
    int n;
    cin >> n; cin.ignore();

    vector<string> grid;
    for (int i = 0; i < n; i++) {
        string row;
        getline(cin, row);
        grid.push_back(row);
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<pair<int, int>>> islands;

    // Поиск островов
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (!visited[y][x] && grid[y][x] == '#') {
                vector<pair<int, int>> island_blocks;
                dfs(x, y, n, grid, visited, island_blocks);
                islands.push_back(island_blocks);
            }
        }
    }

    int max_water = -1;
    int best_island_index = -1;

    for (int i = 0; i < islands.size(); i++) {
        int total_water = 0;

        // Водные ячейки, прилегающие к острову
        vector<vector<bool>> water_counted(n, vector<bool>(n, false));

        for (auto& block : islands[i]) {
            int x = block.first, y = block.second;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    grid[ny][nx] == '~' && !water_counted[ny][nx]) {
                    total_water++;
                    water_counted[ny][nx] = true;
                }
            }
        }

        if (total_water > max_water || (total_water == max_water && i < best_island_index)) {
            max_water = total_water;
            best_island_index = i;
        }
    }

    cout << (best_island_index + 1) << " " << max_water << endl;

    return 0;
}