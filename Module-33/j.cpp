// MODULE 33 — Breadth-First Search (BFS) on adjacency list

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    cout << "Module 33 — BFS (j.cpp)\n";
    cout << "=======================\n\n";

    int V = 6;
    vector<vector<int>> adj(V);
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

    cout << "Undirected graph (same as module b-style):\n";
    cout << "  0 -- 1 -- 3 -- 5\n";
    cout << "  |    |    |    ^\n";
    cout << "  2 -- 4 -------+\n\n";

    int start = 0;
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS order from vertex " << start << ":\n   ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n\n";

    cout << "Algorithm: queue FIFO; visit all neighbors at distance 1 before distance 2, ...\n";
    cout << "Time: O(V + E)   Space: O(V) for visited + queue (worst O(V) vertices in queue)\n";
    cout << "Unweighted shortest path (#edges) from start: BFS level gives distances.\n";

    return 0;
}
