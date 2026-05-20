// MODULE 33 — Has path? (BFS or DFS from src to dest)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool hasPathBFS(const vector<vector<int>>& adj, int src, int dest) {
    int V = static_cast<int>(adj.size());
    if (src == dest) {
        return true;
    }

    vector<bool> visited(V, false);
    queue<int> q;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (v == dest) {
                return true;
            }
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return false;
}

bool hasPathDFS(const vector<vector<int>>& adj, int src, int dest, vector<bool>& visited) {
    if (src == dest) {
        return true;
    }
    visited[src] = true;
    for (int v : adj[src]) {
        if (!visited[v] && hasPathDFS(adj, v, dest, visited)) {
            return true;
        }
    }
    return false;
}

bool hasPathDFSWrapper(const vector<vector<int>>& adj, int src, int dest) {
    vector<bool> visited(adj.size(), false);
    return hasPathDFS(adj, src, dest, visited);
}

int main() {
    cout << "Module 33 — Has path src -> dest? (l.cpp)\n";
    cout << "=========================================\n\n";

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

    cout << "Graph (same as j.cpp / k.cpp):\n";
    cout << "  0 -- 1 -- 3 -- 5\n";
    cout << "  |    |    |    ^\n";
    cout << "  2 -- 4-------+\n\n";

    auto test = [&](int src, int dest) {
        bool bfs = hasPathBFS(adj, src, dest);
        bool dfs = hasPathDFSWrapper(adj, src, dest);
        cout << "hasPath(" << src << ", " << dest << ")  BFS=" << (bfs ? "true" : "false")
             << "  DFS=" << (dfs ? "true" : "false") << "\n";
    };

    test(0, 5);
    test(0, 0);
    test(5, 0);

    cout << "\nDisconnected: edge only 0--1, vertex 2 alone\n";
    vector<vector<int>> dis(3);
    dis[0].push_back(1);
    dis[1].push_back(0);
    cout << "hasPath(0, 2)  BFS=" << (hasPathBFS(dis, 0, 2) ? "true" : "false")
         << "  DFS=" << (hasPathDFSWrapper(dis, 0, 2) ? "true" : "false") << "\n";

    cout << "\nDisconnected component test: only vertex {0} isolated\n";
    vector<vector<int>> solo(1);
    cout << "hasPath(0, 0) = " << (hasPathBFS(solo, 0, 0) ? "true" : "false") << "\n";

    cout << "\nTime: O(V + E)   Space: O(V) visited + O(V) queue or stack worst case\n";
    return 0;
}
