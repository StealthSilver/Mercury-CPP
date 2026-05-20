// MODULE 36 — Prim's algorithm (MST, lazy priority queue)

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

long long primMST(int V, const vector<vector<pair<int, int>>>& adj) {
    vector<bool> inMST(V, false);
    using P = pair<long long, int>;
    priority_queue<P, vector<P>, greater<P>> pq;

    long long total = 0;
    int edgesUsed = 0;

    inMST[0] = true;
    for (auto [v, w] : adj[0]) {
        pq.push({w, v});
    }

    while (!pq.empty() && edgesUsed < V - 1) {
        auto [w, u] = pq.top();
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        total += w;
        edgesUsed++;
        for (auto [v, w2] : adj[u]) {
            if (!inMST[v]) {
                pq.push({w2, v});
            }
        }
    }

    return (edgesUsed == V - 1) ? total : -1;
}

int main() {
    cout << "Module 36 — Prim MST (c.cpp)\n";
    cout << "============================\n\n";

    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    auto addU = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    addU(0, 1, 9);
    addU(0, 2, 75);
    addU(1, 2, 95);
    addU(1, 3, 19);
    addU(1, 4, 42);
    addU(2, 3, 51);
    addU(2, 4, 66);
    addU(3, 4, 31);

    long long cost = primMST(V, adj);
    cout << "MST total weight (Prim) = " << cost << "\n\n";

    cout << "Grow tree T: repeatedly add cheapest edge from T to outside (cut property).\n";
    cout << "Time: O(E log V) with binary heap   Space: O(V + E) graph + heap\n";

    return 0;
}
