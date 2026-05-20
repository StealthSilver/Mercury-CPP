// MODULE 35 — Cycle in directed graph via Kahn (processed count < V => cycle)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool hasDirectedCycleKahn(int V, const vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    int processed = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        processed++;
        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return processed != V;
}

int main() {
    cout << "Module 35 — Kahn detects directed cycle (c.cpp)\n";
    cout << "===============================================\n\n";

    int V = 4;
    vector<vector<int>> dag(V);
    dag[0].push_back(1);
    dag[1].push_back(2);
    dag[2].push_back(3);
    cout << "DAG 0->1->2->3: hasCycle = " << (hasDirectedCycleKahn(V, dag) ? "YES" : "NO") << "\n";

    vector<vector<int>> cyc(V);
    cyc[0].push_back(1);
    cyc[1].push_back(2);
    cyc[2].push_back(0);
    cout << "Directed triangle: hasCycle = " << (hasDirectedCycleKahn(V, cyc) ? "YES" : "NO") << "\n\n";

    cout << "If indegree never becomes 0 for some vertices, they sit on a directed cycle.\n";
    cout << "Time: O(V + E)   Space: O(V)\n";

    return 0;
}
