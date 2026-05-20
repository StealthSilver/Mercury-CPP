// MODULE 34 — Count connected components (undirected) using BFS

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int countComponentsBFS(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    int components = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;
            bfs(i, adj, visited);
        }
    }
    return components;
}

int main() {
    cout << "Module 34 — Disconnected components via BFS (b.cpp)\n";
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

    cout << "Same graph as a.cpp (three components).\n\n";

    int c = countComponentsBFS(V, adj);
    cout << "Number of connected components (BFS) = " << c << "\n\n";

    cout << "Idea: same as DFS — each BFS flood-fill from a fresh start vertex = one component.\n";
    cout << "Time: O(V + E)   Space: O(V) visited + O(V) queue worst case\n";

    return 0;
}
