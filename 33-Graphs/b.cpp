// MODULE 33 — Adjacency list representation (vector of neighbor lists)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "Module 33 — Adjacency List (b.cpp)\n";
    cout << "==================================\n\n";

    int V = 6;
    vector<vector<int>> adj(V);

    auto addDirected = [&](int u, int v) { adj[u].push_back(v); };

    cout << "Example: directed edges of a small workflow graph\n";
    cout << "  0 -> 1 -> 3\n";
    cout << "  |    v    v\n";
    cout << "  v    2 -> 4 -> 5\n\n";

    addDirected(0, 1);
    addDirected(0, 2);
    addDirected(1, 3);
    addDirected(2, 4);
    addDirected(3, 5);
    addDirected(4, 5);

    for (int u = 0; u < V; u++) {
        cout << "  " << u << " :";
        for (int v : adj[u]) cout << " -> " << v;
        if (adj[u].empty()) cout << " (no outgoing)";
        cout << "\n";
    }

    cout << "\nBenefits:\n";
    cout << "  • Space O(V + E) — only stores edges that exist.\n";
    cout << "  • Iterating neighbors of u is O(degree(u)), not O(V).\n";
    cout << "  • Standard for sparse graphs (social nets, road nets).\n";

    return 0;
}
