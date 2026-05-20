// MODULE 34 — Bipartite graph check (2-coloring with BFS)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isBipartite(int V, const vector<vector<int>>& adj) {
    vector<int> color(V, -1);

    for (int s = 0; s < V; s++) {
        if (color[s] != -1) continue;

        queue<int> q;
        color[s] = 0;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    cout << "Module 34 — Bipartite check / 2-coloring (i.cpp)\n";
    cout << "==============================================\n\n";

    int V = 4;
    vector<vector<int>> path(V);
    path[0] = {1};
    path[1] = {0, 2};
    path[2] = {1, 3};
    path[3] = {2};
    cout << "Path 0-1-2-3 (bipartite): " << (isBipartite(V, path) ? "YES" : "NO") << "\n";

    vector<vector<int>> tri(V);
    tri[0] = {1, 2};
    tri[1] = {0, 2};
    tri[2] = {0, 1};
    cout << "Triangle C3 (odd cycle):   " << (isBipartite(V, tri) ? "YES" : "NO") << "\n\n";

    cout << "BFS assigns color 0/1; conflict = edge inside one set => not bipartite.\n";
    cout << "Time: O(V + E)   Space: O(V)\n";

    return 0;
}
