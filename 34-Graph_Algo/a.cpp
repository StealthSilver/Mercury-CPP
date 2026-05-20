// MODULE 34 — Count connected components (undirected) using DFS

#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int countComponentsDFS(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    int components = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }
    return components;
}

int main() {
    cout << "Module 34 — Disconnected components via DFS (a.cpp)\n";
    cout << "=================================================\n\n";

    int V = 7;
    vector<vector<int>> adj(V);
    auto addU = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addU(0, 1);
    addU(1, 2);
    addU(3, 4);
    addU(5, 6);

    cout << "Graph: component {0,1,2}, {3,4}, {5,6}  (three pieces)\n\n";

    int c = countComponentsDFS(V, adj);
    cout << "Number of connected components (DFS) = " << c << "\n\n";

    cout << "Idea: every time DFS starts from an unvisited vertex, that is a new component.\n";
    cout << "Time: O(V + E)   Space: O(V) visited + O(V) recursion stack worst case\n";

    return 0;
}
