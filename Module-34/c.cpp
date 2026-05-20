// MODULE 34 — Detect cycle in undirected graph using BFS (parent tracking)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool hasCycleUndirectedBFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);

    for (int s = 0; s < V; s++) {
        if (visited[s]) continue;

        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, -1});

        while (!q.empty()) {
            auto [u, parent] = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, u});
                } else if (v != parent) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cout << "Module 34 — Undirected cycle: BFS (c.cpp)\n";
    cout << "=========================================\n\n";

    int V = 4;
    vector<vector<int>> tree(V);
    tree[0].push_back(1);
    tree[1].push_back(0);
    tree[1].push_back(2);
    tree[2].push_back(1);
    tree[2].push_back(3);
    tree[3].push_back(2);
    cout << "Path 0-1-2-3 (tree): hasCycle = " << (hasCycleUndirectedBFS(V, tree) ? "true" : "false") << "\n";

    vector<vector<int>> cyc(V);
    cyc[0].push_back(1);
    cyc[1].push_back(0);
    cyc[1].push_back(2);
    cyc[2].push_back(1);
    cyc[2].push_back(0);
    cyc[0].push_back(2);
    cyc[2].push_back(3);
    cyc[3].push_back(2);
    cout << "Triangle 0-1-2 plus edge 2-3: hasCycle = " << (hasCycleUndirectedBFS(V, cyc) ? "true" : "false") << "\n\n";

    cout << "Rule: from u, if neighbor v is visited and v is not the BFS parent of u, back edge -> cycle.\n";
    cout << "Time: O(V + E)   Space: O(V)\n";

    return 0;
}
