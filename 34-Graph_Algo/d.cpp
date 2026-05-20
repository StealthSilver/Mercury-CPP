// MODULE 34 — Detect cycle in undirected graph using DFS (parent tracking)

#include <iostream>
#include <vector>
using namespace std;

bool dfsUndirected(int u, int parent, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfsUndirected(v, u, adj, visited)) {
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycleUndirectedDFS(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsUndirected(i, -1, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cout << "Module 34 — Undirected cycle: DFS (d.cpp)\n";
    cout << "=========================================\n\n";

    int V = 4;
    vector<vector<int>> tree(V);
    tree[0] = {1};
    tree[1] = {0, 2};
    tree[2] = {1, 3};
    tree[3] = {2};
    cout << "Path 0-1-2-3: hasCycle = " << (hasCycleUndirectedDFS(V, tree) ? "true" : "false") << "\n";

    vector<vector<int>> cyc(V);
    cyc[0] = {1, 2};
    cyc[1] = {0, 2};
    cyc[2] = {0, 1, 3};
    cyc[3] = {2};
    cout << "Triangle + tail: hasCycle = " << (hasCycleUndirectedDFS(V, cyc) ? "true" : "false") << "\n\n";

    cout << "Same parent rule as BFS: visited neighbor not parent implies cycle.\n";
    cout << "Time: O(V + E)   Space: O(V) visited + O(V) stack worst case\n";

    return 0;
}
