// MODULE 36 — Flood fill: DFS on a 2D grid (count connected regions of '1')

#include <iostream>
#include <vector>
using namespace std;

void fill(int r, int c, vector<vector<char>>& grid) {
    int R = static_cast<int>(grid.size());
    int C = static_cast<int>(grid[0].size());
    if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] != '1') return;
    grid[r][c] = '0';
    fill(r - 1, c, grid);
    fill(r + 1, c, grid);
    fill(r, c - 1, grid);
    fill(r, c + 1, grid);
}

int numIslands(vector<vector<char>> grid) {
    int R = static_cast<int>(grid.size());
    if (R == 0) return 0;
    int C = static_cast<int>(grid[0].size());
    int count = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '1') {
                count++;
                fill(i, j, grid);
            }
        }
    }
    return count;
}

int main() {
    cout << "Module 36 — Flood fill (i.cpp)\n";
    cout << "==============================\n\n";

    vector<vector<char>> g1 = {
        {'1', '1', '0', '0'},
        {'1', '1', '0', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '0', '1'},
    };

    cout << "Grid (1=land, 0=water):\n";
    for (const auto& row : g1) {
        cout << "   ";
        for (char ch : row) cout << ch << ' ';
        cout << "\n";
    }
    cout << "Islands (4-connected) = " << numIslands(g1)
         << "  (one 2x2 block + two isolated land cells)\n\n";

    cout << "DFS paints cell and recurses to 4 neighbors — same idea as paint bucket.\n";
    cout << "Time: O(R*C) each cell visited constant times   Space: O(R*C) stack worst case\n";

    return 0;
}
