// MODULE 36 — Bellman–Ford (single-source; allows negative edges; detects negative cycles)

#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

bool bellmanFord(int V, int src, const vector<Edge>& edges, vector<long long>& dist) {
    const long long INF = (long long)4e18;
    dist.assign(V, INF);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        bool any = false;
        for (const auto& e : edges) {
            if (dist[e.u] < INF && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                any = true;
            }
        }
        if (!any) break;
    }

    for (const auto& e : edges) {
        if (dist[e.u] < INF && dist[e.v] > dist[e.u] + e.w) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Module 36 — Bellman–Ford (b.cpp)\n";
    cout << "==============================\n\n";

    int V = 5;
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3},
    };

    vector<long long> dist;
    bool ok = bellmanFord(V, 0, edges, dist);

    cout << "Graph with negative edge weights (no negative cycle):\n";
    if (ok) {
        cout << "dist from 0:\n";
        for (int i = 0; i < V; i++) {
            cout << "   " << i << ": " << dist[i] << "\n";
        }
    } else {
        cout << "negative weight cycle reachable from src\n";
    }

    vector<Edge> negCycle = {{0, 1, 1}, {1, 2, -3}, {2, 0, 1}};
    ok = bellmanFord(3, 0, negCycle, dist);
    cout << "\nTriangle with total weight -1: ok = " << (ok ? "true" : "false") << "\n\n";

    cout << "Relax all edges V-1 times (DP on shortest path edge count).\n";
    cout << "V-th pass can still relax => negative cycle.\n";
    cout << "Time: O(V * E)   Space: O(V)\n";

    return 0;
}
