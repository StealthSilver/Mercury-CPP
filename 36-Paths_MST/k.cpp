// MODULE 36 — LeetCode 994: Rotting Oranges (multi-source BFS on grid)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Multi-source BFS: all rotten cells are sources; each "minute" expands one layer.
// Time O(m*n), Space O(m*n) for queue + counts.
int orangesRotting(vector<vector<int>>& grid) {
    int m = (int)grid.size();
    int n = (int)grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2)
                q.push({i, j});
            else if (grid[i][j] == 1)
                fresh++;
        }
    }
    if (fresh == 0) return 0;

    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minutes = 0;
    while (!q.empty()) {
        int sz = (int)q.size();
        bool progressed = false;
        for (int s = 0; s < sz; s++) {
            auto [r, c] = q.front();
            q.pop();
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (grid[nr][nc] != 1) continue;
                grid[nr][nc] = 2;
                fresh--;
                progressed = true;
                q.push({nr, nc});
            }
        }
        if (progressed) minutes++;
        else
            break;
    }
    return fresh == 0 ? minutes : -1;
}

int main() {
    cout << "Module 36 — Rotting Oranges (k.cpp)\n";
    cout << "==================================\n\n";
    vector<vector<int>> g = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int t = orangesRotting(g);
    cout << "Example: matrix with some 2s and 1s -> minutes = " << t << " (expect 4)\n";
    return 0;
}
