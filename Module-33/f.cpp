// MODULE 33 — Implicit graph: cells of a 2D grid as vertices, 4-neighbor moves

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    cout << "Module 33 — Implicit graph on a 2D grid (f.cpp)\n";
    cout << "===============================================\n\n";

    const int R = 4, C = 5;
    vector<string> grid = {
        ".....",
        ".#.#.",
        ".#...",
        ".....",
    };

    cout << "Grid ('.' walkable, '#' blocked):\n";
    for (const string& row : grid) cout << "  " << row << "\n";

    int sr = 0, sc = 0, tr = 3, tc = 4;
    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int, int>> q;
    dist[sr][sc] = 0;
    q.push({sr, sc});

    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (grid[nr][nc] == '#') continue;
            if (dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    cout << "\nImplicit graph: each cell (r,c) is a vertex; edges to 4 neighbors if walkable.\n";
    cout << "Shortest path length from (" << sr << "," << sc << ") to (" << tr << "," << tc
         << ") = " << dist[tr][tc] << " edges\n";
    cout << "No explicit adjacency array — neighbors computed from (r,c) and grid.\n";

    return 0;
}
