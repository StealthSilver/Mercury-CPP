// MODULE 33 — Building a graph using an edge list (+ optional conversion to adjacency list)

#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v;
};

int main() {
    cout << "Module 33 — Build graph: edge list (i.cpp)\n";
    cout << "==========================================\n\n";

    cout << "Steps:\n";
    cout << "  1. Define struct or tuple (u, v) or (u, v, weight).\n";
    cout << "  2. Push each edge into a vector<Edge>.\n";
    cout << "  3. Optionally build adjacency list in O(V + E) second pass.\n\n";

    vector<Edge> edges = {{0, 1}, {1, 2}, {1, 3}};
    cout << "   Stored edges (undirected meaning: treat as unique pairs when converting):\n";
    for (const auto& e : edges) {
        cout << "   (" << e.u << ", " << e.v << ")\n";
    }

    int V = 4;
    vector<vector<int>> adj(V);
    for (const auto& e : edges) {
        adj[e.u].push_back(e.v);
        adj[e.v].push_back(e.u);
    }

    cout << "\n   Converted adjacency list (dedupe not applied — demo of scan):\n";
    for (int u = 0; u < V; u++) {
        cout << "   " << u << " : ";
        for (int v : adj[u]) cout << v << " ";
        cout << "\n";
    }

    cout << "\nEdge list space: O(E). Conversion to adj list: O(E) pushes.\n";
    return 0;
}
