// MODULE 36 — Dijkstra's algorithm (single-source shortest paths, non-negative weights)

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const long long INF = (long long)4e18;

vector<long long> dijkstra(int src, int V, const vector<vector<pair<int, int>>>& adj) {
    vector<long long> dist(V, INF);
    dist[src] = 0;

    using P = pair<long long, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) {
            continue;
        }
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    cout << "Module 36 — Dijkstra (a.cpp)\n";
    cout << "============================\n\n";

    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    auto add = [&](int u, int v, int w) { adj[u].push_back({v, w}); };

    add(0, 1, 10);
    add(0, 4, 3);
    add(1, 2, 2);
    add(1, 4, 4);
    add(2, 3, 9);
    add(3, 2, 7);
    add(3, 1, 5);
    add(3, 0, 2);
    add(4, 1, 1);
    add(4, 2, 8);

    int src = 0;
    vector<long long> d = dijkstra(src, V, adj);

    cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "   dist[" << i << "] = ";
        if (d[i] >= INF / 2)
            cout << "INF\n";
        else
            cout << d[i] << "\n";
    }
    cout << "\nGreedy: always settle closest unsettled vertex (non-negative => optimal).\n";
    cout << "Time: O((V+E) log V) with binary heap; O(V^2) with array scan for dense graphs.\n";
    cout << "Space: O(V) dist + O(V) heap roughly\n";

    return 0;
}
