// MODULE 35 — Topological sort: DFS (postorder stack, reverse)

#include <iostream>
#include <vector>
using namespace std;

bool dfsTopo(int u, const vector<vector<int>>& adj, vector<int>& state, vector<int>& finishOrder) {
    state[u] = 1;
    for (int v : adj[u]) {
        if (state[v] == 1) {
            return false;
        }
        if (state[v] == 0 && !dfsTopo(v, adj, state, finishOrder)) {
            return false;
        }
    }
    state[u] = 2;
    finishOrder.push_back(u);
    return true;
}

bool topologicalSortDFS(int V, const vector<vector<int>>& adj, vector<int>& outOrder) {
    vector<int> state(V, 0);
    vector<int> finishOrder;

    for (int i = 0; i < V; i++) {
        if (state[i] == 0 && !dfsTopo(i, adj, state, finishOrder)) {
            return false;
        }
    }

    outOrder.assign(finishOrder.rbegin(), finishOrder.rend());
    return true;
}

int main() {
    cout << "Module 35 — Topological sort DFS (a.cpp)\n";
    cout << "=======================================\n\n";

    int V = 6;
    vector<vector<int>> adj(V);
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> order;
    bool ok = topologicalSortDFS(V, adj, order);

    cout << "DAG (classic example). Valid topo order (one of many):\n   ";
    if (ok) {
        for (int x : order) cout << x << " ";
        cout << "\n";
    } else {
        cout << "cycle detected\n";
    }

    cout << "\nDFS pushes vertex when finished; reverse = topological order.\n";
    cout << "Time: O(V + E)   Space: O(V) state + stack + output\n";

    return 0;
}
