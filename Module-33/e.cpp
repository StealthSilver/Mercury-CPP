// MODULE 33 — Directed vs undirected edges (how they appear in storage)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "Module 33 — Edge directions (e.cpp)\n";
    cout << "===================================\n\n";

    int V = 3;
    vector<vector<int>> directed(V);
    vector<vector<int>> undirected(V);

    cout << "Directed: single edge 0 -> 1\n";
    directed[0].push_back(1);

    cout << "Undirected: same link stored both ways 0 <-> 1\n";
    undirected[0].push_back(1);
    undirected[1].push_back(0);

    cout << "\nDirected adjacency:\n";
    for (int u = 0; u < V; u++) {
        cout << "  " << u << " -> ";
        for (int v : directed[u]) cout << v << " ";
        cout << "\n";
    }

    cout << "\nUndirected adjacency:\n";
    for (int u = 0; u < V; u++) {
        cout << "  " << u << " -> ";
        for (int v : undirected[u]) cout << v << " ";
        cout << "\n";
    }

    cout << "\nBi-directional on a line is often modeled as two directed edges u->v and v->u.\n";

    return 0;
}
