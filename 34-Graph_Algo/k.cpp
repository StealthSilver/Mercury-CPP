// MODULE 34 — Enumerate all simple paths from src to dest (directed graph, DFS + path vector)

#include <iostream>
#include <vector>
using namespace std;

void allPathsUtil(int u, int dest, const vector<vector<int>>& adj, vector<bool>& onPath,
                  vector<int>& path, vector<vector<int>>& result) {
    onPath[u] = true;
    path.push_back(u);

    if (u == dest) {
        result.push_back(path);
    } else {
        for (int v : adj[u]) {
            if (!onPath[v]) {
                allPathsUtil(v, dest, adj, onPath, path, result);
            }
        }
    }

    path.pop_back();
    onPath[u] = false;
}

vector<vector<int>> allPaths(int V, const vector<vector<int>>& adj, int src, int dest) {
    vector<bool> onPath(V, false);
    vector<int> path;
    vector<vector<int>> result;
    allPathsUtil(src, dest, adj, onPath, path, result);
    return result;
}

int main() {
    cout << "Module 34 — All paths src -> dest (k.cpp)\n";
    cout << "=========================================\n\n";

    int V = 5;
    vector<vector<int>> adj(V);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[0].push_back(3);
    adj[3].push_back(4);

    cout << "Directed graph:\n";
    cout << "   0 ---> 1 ---> 3 ---> 4\n";
    cout << "   | \\         ^\n";
    cout << "   |  \\-> 2 ---/\n";
    cout << "   +---------> 3\n\n";

    int src = 0, dest = 4;
    vector<vector<int>> paths = allPaths(V, adj, src, dest);

    cout << "All simple paths from " << src << " to " << dest << ":\n";
    for (const auto& p : paths) {
        cout << "  ";
        for (size_t i = 0; i < p.size(); i++) {
            if (i) cout << " -> ";
            cout << p[i];
        }
        cout << "\n";
    }
    cout << "Total paths: " << paths.size() << "\n\n";

    cout << "DFS + onPath[] avoids revisiting vertex on current walk (simple paths).\n";
    cout << "Worst-case exponential in V; use only on small graphs or DAGs in practice.\n";

    return 0;
}
