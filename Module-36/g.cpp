// MODULE 36 — Cheapest flights within K stops (Bellman-Ford layer trick, LC 787 style)

#include <iostream>
#include <vector>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    dist[src] = 0;

    for (int s = 0; s <= K; s++) {
        vector<int> next = dist;
        for (const auto& f : flights) {
            int u = f[0], v = f[1], price = f[2];
            if (dist[u] < INF) {
                next[v] = min(next[v], dist[u] + price);
            }
        }
        dist.swap(next);
    }

    return dist[dst] >= INF ? -1 : dist[dst];
}

int main() {
    cout << "Module 36 — Cheapest flights within K stops (g.cpp)\n";
    cout << "==================================================\n\n";

    int n = 3;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << "3 cities, flights 0->1(100), 1->2(100), 0->2(500)\n";
    cout << "src=0 dst=2 K=0 (no stops): " << findCheapestPrice(n, flights, 0, 2, 0)
         << "  (direct 500)\n";
    cout << "src=0 dst=2 K=1 (one stop): " << findCheapestPrice(n, flights, 0, 2, 1)
         << "  (via 1: 200)\n\n";

    cout << "Each round extends paths by one flight; at most K+1 edges total.\n";
    cout << "Time: O((K+1) * |flights|)   Space: O(n)\n";

    return 0;
}
