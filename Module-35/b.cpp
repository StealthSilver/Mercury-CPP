// MODULE 35 — Topological sort: Kahn's algorithm (BFS on indegree-0)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool topologicalSortKahn(int V, const vector<vector<int>>& adj, vector<int>& outOrder) {
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

    outOrder.clear();
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        outOrder.push_back(u);
        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return static_cast<int>(outOrder.size()) == V;
}

int main() {
    cout << "Module 35 — Topological sort Kahn / BFS (b.cpp)\n";
    cout << "===============================================\n\n";

    int V = 6;
    vector<vector<int>> adj(V);
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> order;
    bool ok = topologicalSortKahn(V, adj, order);

    cout << "Same DAG as a.cpp. Kahn order:\n   ";
    if (ok) {
        for (int x : order) cout << x << " ";
        cout << "\n";
    } else {
        cout << "cycle\n";
    }

    cout << "\nRepeatedly remove indegree-0 vertices (sources).\n";
    cout << "Time: O(V + E)   Space: O(V)\n";

    return 0;
}
