// MODULE 34 — Kahn's algorithm: topological order + detect directed cycle

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

pair<bool, vector<int>> topologicalSortKahn(int V, const vector<vector<int>>& adj) {
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

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    bool hasCycle = (static_cast<int>(order.size()) != V);
    return {hasCycle, order};
}

int main() {
    cout << "Module 34 — Kahn's algorithm (h.cpp)\n";
    cout << "====================================\n\n";

    int V = 6;
    vector<vector<int>> dag(V);
    dag[5].push_back(2);
    dag[5].push_back(0);
    dag[4].push_back(0);
    dag[4].push_back(1);
    dag[2].push_back(3);
    dag[3].push_back(1);

    auto [cyc1, topo1] = topologicalSortKahn(V, dag);
    cout << "Classic DAG example: hasCycle = " << (cyc1 ? "true" : "false") << "\n";
    cout << "Topological order (one valid): ";
    for (int x : topo1) cout << x << " ";
    cout << "\n\n";

    vector<vector<int>> dc(3);
    dc[0].push_back(1);
    dc[1].push_back(2);
    dc[2].push_back(0);
    auto [cyc2, topo2] = topologicalSortKahn(3, dc);
    cout << "Directed 3-cycle: hasCycle = " << (cyc2 ? "true" : "false") << "\n";
    cout << "Vertices in partial topo order when cyclic: " << topo2.size() << " (need 3 for acyclic)\n\n";

    cout << "Kahn: repeatedly remove indegree-0 vertex; if fewer than V removals, a directed cycle exists.\n";
    cout << "Time: O(V + E)   Space: O(V)\n";

    return 0;
}
