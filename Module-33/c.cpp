// MODULE 33 — Adjacency matrix (V x V), unweighted and weighted examples

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "Module 33 — Adjacency Matrix (c.cpp)\n";
    cout << "====================================\n\n";

    const int V = 4;

    cout << "1) Unweighted (1 = edge, 0 = no edge)\n";
    vector<vector<int>> unweighted(V, vector<int>(V, 0));
    unweighted[0][1] = unweighted[1][0] = 1;
    unweighted[1][2] = unweighted[2][1] = 1;
    unweighted[2][3] = unweighted[3][2] = 1;
    unweighted[0][3] = unweighted[3][0] = 1;

    cout << "     ";
    for (int j = 0; j < V; j++) cout << j << " ";
    cout << "\n";
    for (int i = 0; i < V; i++) {
        cout << "  " << i << " ";
        for (int j = 0; j < V; j++) cout << unweighted[i][j] << " ";
        cout << "\n";
    }

    cout << "\n2) Weighted (weight or 0 = no edge; here 0 means no edge)\n";
    vector<vector<int>> weighted(V, vector<int>(V, 0));
    weighted[0][1] = 4;
    weighted[0][2] = 2;
    weighted[1][3] = 5;
    weighted[2][3] = 1;

    cout << "     ";
    for (int j = 0; j < V; j++) cout << j << " ";
    cout << "\n";
    for (int i = 0; i < V; i++) {
        cout << "  " << i << " ";
        for (int j = 0; j < V; j++) cout << weighted[i][j] << " ";
        cout << "\n";
    }

    cout << "\nMatrix size: V x V = " << V * V << " cells.\n";
    cout << "Trade-off: O(1) edge test mat[u][v], but O(V^2) memory and slow neighbor scan O(V).\n";

    return 0;
}
