// MODULE 33 — Depth-First Search (DFS) on adjacency list (recursive)

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> order;

void dfs(int u) {
    visited[u] = true;
    order.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    cout << "Module 33 — DFS (k.cpp)\n";
    cout << "=======================\n\n";

    int V = 6;
    adj.assign(V, {});
    auto addU = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addU(0, 1);
    addU(0, 2);
    addU(1, 3);
    addU(2, 4);
    addU(3, 5);
    addU(4, 5);

    cout << "Same graph as j.cpp (neighbor order may affect DFS preorder).\n\n";

    visited.assign(V, false);
    order.clear();
    int start = 0;
    dfs(start);

    cout << "DFS preorder from vertex " << start << ":\n   ";
    for (int x : order) cout << x << " ";
    cout << "\n\n";

    cout << "Algorithm: go deep along one edge until stuck, backtrack, try next branch.\n";
    cout << "Time: O(V + E)   Space: O(V) visited + O(V) recursion stack worst (long path)\n";
    cout << "Iterative DFS: explicit stack; same time bounds.\n";

    return 0;
}
