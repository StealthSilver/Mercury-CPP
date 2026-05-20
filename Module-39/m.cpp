// MODULE 39 — Longest Increasing Path in a Matrix (4-directional, strictly increasing)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int dfs(int r, int c, const vector<vector<int>>& mat, vector<vector<int>>& memo) {
    if (memo[r][c] != 0) return memo[r][c];
    int best = 1;
    int rows = (int)mat.size(), cols = (int)mat[0].size();
    for (int d = 0; d < 4; d++) {
        int nr = r + dx[d], nc = c + dy[d];
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
        if (mat[nr][nc] > mat[r][c])
            best = max(best, 1 + dfs(nr, nc, mat, memo));
    }
    return memo[r][c] = best;
}

int longestIncreasingPath(vector<vector<int>>& mat) {
    if (mat.empty()) return 0;
    int rows = (int)mat.size(), cols = (int)mat[0].size();
    vector<vector<int>> memo(rows, vector<int>(cols, 0));
    int ans = 0;
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            ans = max(ans, dfs(r, c, mat, memo));
    return ans;
}

int main() {
    cout << "Module 39 — Longest Increasing Path in Matrix (m.cpp)\n";
    cout << "====================================================\n\n";

    vector<vector<int>> mat = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    cout << "Matrix:\n";
    for (auto& row : mat) {
        cout << "  ";
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    cout << "\n  DFS + memo from each cell, move to strictly larger neighbor.\n";
    cout << "  Longest path length: " << longestIncreasingPath(mat) << " (expect 4)\n";
    cout << "  Example path: 1 -> 2 -> 6 -> 9\n";
    return 0;
}
