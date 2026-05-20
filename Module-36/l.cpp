// MODULE 36 — LeetCode 695: Max Area of Island (DFS flood fill)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& grid, int r, int c) {
    int m = (int)grid.size(), n = (int)grid[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1) return 0;
    grid[r][c] = 0;  // mark visited
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int area = 1;
    for (auto [dr, dc] : dirs) area += dfs(grid, r + dr, c + dc);
    return area;
}

int maxAreaOfIsland(vector<vector<int>> grid) {
    int best = 0;
    int m = (int)grid.size(), n = (int)grid[0].size();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1) best = max(best, dfs(grid, i, j));
    return best;
}

int main() {
    cout << "Module 36 — Max Area of Island (l.cpp)\n";
    cout << "=====================================\n\n";
    vector<vector<int>> g = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << "LeetCode sample: max area = " << maxAreaOfIsland(g) << " (expect 6)\n";
    return 0;
}
