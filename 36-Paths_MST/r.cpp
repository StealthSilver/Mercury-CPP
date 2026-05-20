// MODULE 36 — LeetCode 1254: Number of Closed Islands (boundary flood + DFS)

#include <iostream>
#include <vector>
using namespace std;

void flood(vector<vector<int>>& g, int r, int c) {
    int m = (int)g.size(), n = (int)g[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n || g[r][c] != 0) return;
    g[r][c] = 1;
    flood(g, r - 1, c);
    flood(g, r + 1, c);
    flood(g, r, c - 1);
    flood(g, r, c + 1);
}

int dfsIsland(vector<vector<int>>& g, int r, int c) {
    int m = (int)g.size(), n = (int)g[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n || g[r][c] != 0) return 0;
    g[r][c] = 1;
    return 1 + dfsIsland(g, r - 1, c) + dfsIsland(g, r + 1, c) + dfsIsland(g, r, c - 1) +
           dfsIsland(g, r, c + 1);
}

// Land = 0, water = 1. Closed island = 0-component not touching grid border.
int closedIsland(vector<vector<int>> grid) {
    int m = (int)grid.size(), n = (int)grid[0].size();
    for (int j = 0; j < n; j++) {
        flood(grid, 0, j);
        flood(grid, m - 1, j);
    }
    for (int i = 0; i < m; i++) {
        flood(grid, i, 0);
        flood(grid, i, n - 1);
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 0) {
                dfsIsland(grid, i, j);
                ans++;
            }
    return ans;
}

int main() {
    cout << "Module 36 — Number of Closed Islands (r.cpp)\n";
    cout << "===========================================\n\n";
    // LeetCode 1254 Example 1 (official 5×8 grid).
    vector<vector<int>> g = {{1, 1, 1, 1, 1, 1, 1, 0},
                             {1, 0, 0, 0, 0, 1, 1, 0},
                             {1, 0, 1, 0, 1, 1, 1, 0},
                             {1, 0, 0, 0, 0, 1, 0, 1},
                             {1, 1, 1, 1, 1, 1, 1, 0}};
    cout << "Closed islands = " << closedIsland(g) << " (expect 2)\n";
    return 0;
}
