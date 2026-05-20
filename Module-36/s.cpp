// MODULE 36 — LeetCode 1129: Shortest Path with Alternating Colors

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// State = (node, parity): last edge taken was red (0) or blue (1).
// From (u,0) extend along blue edges; from (u,1) along red edges.
// Start at 0 with both parities at distance 0 so first step may use either color.
vector<int> shortestAlternatingPaths(int n, const vector<vector<int>>& redEdges,
                                     const vector<vector<int>>& blueEdges) {
    vector<vector<vector<int>>> adj(2, vector<vector<int>>(n));
    for (auto& e : redEdges) adj[0][e[0]].push_back(e[1]);
    for (auto& e : blueEdges) adj[1][e[0]].push_back(e[1]);

    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(2, INF));
    queue<pair<int, int>> q;
    dist[0][0] = dist[0][1] = 0;
    q.push({0, 0});
    q.push({0, 1});

    while (!q.empty()) {
        auto [u, last] = q.front();
        q.pop();
        int nxt = 1 - last;
        int c = dist[u][last];
        for (int v : adj[nxt][u]) {
            if (dist[v][nxt] > c + 1) {
                dist[v][nxt] = c + 1;
                q.push({v, nxt});
            }
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int m = min(dist[i][0], dist[i][1]);
        ans[i] = (m == INF ? -1 : m);
    }
    return ans;
}

int main() {
    cout << "Module 36 — Shortest Path with Alt. Colors (s.cpp)\n";
    cout << "=================================================\n\n";
    int n = 3;
    vector<vector<int>> red = {{0, 1}, {1, 2}};
    vector<vector<int>> blue = {};
    auto a = shortestAlternatingPaths(n, red, blue);
    cout << "n=3, red [[0,1],[1,2]], no blue -> distances: ";
    for (int x : a) cout << x << ' ';
    cout << "\n";
    return 0;
}
