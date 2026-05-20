// MODULE 34 — Graph coloring: greedy (order 0,1,...,V-1), smallest non-conflicting color

#include <iostream>
#include <vector>
using namespace std;

vector<int> greedyColoring(int V, const vector<vector<int>>& adj) {
    vector<int> color(V, -1);

    for (int u = 0; u < V; u++) {
        vector<bool> forbidden(V + 2, false);
        for (int v : adj[u]) {
            if (color[v] != -1) {
                forbidden[color[v]] = true;
            }
        }
        int c = 0;
        while (forbidden[c]) c++;
        color[u] = c;
    }
    return color;
}

int main() {
    cout << "Module 34 — Greedy graph coloring (j.cpp)\n";
    cout << "=========================================\n\n";

    int V = 5;
    vector<vector<int>> c5(V);
    c5[0] = {1, 4};
    c5[1] = {0, 2};
    c5[2] = {1, 3};
    c5[3] = {2, 4};
    c5[4] = {3, 0};

    cout << "Undirected 5-cycle C5 (odd cycle, NOT bipartite):\n";
    vector<int> col = greedyColoring(V, c5);
    for (int i = 0; i < V; i++) {
        cout << "  vertex " << i << " -> color " << col[i] << "\n";
    }
    int mx = 0;
    for (int c : col) mx = max(mx, c);
    cout << "  Number of colors used (this run): " << (mx + 1) << "  (C5 has chromatic number 3)\n\n";

    cout << "K_{2,2} (bipartite) on vertices 0,1 | 2,3 — should use 2 colors:\n";
    V = 4;
    vector<vector<int>> k22(V);
    k22[0] = {2, 3};
    k22[1] = {2, 3};
    k22[2] = {0, 1};
    k22[3] = {0, 1};
    col = greedyColoring(V, k22);
    mx = 0;
    for (int c : col) mx = max(mx, c);
    for (int i = 0; i < V; i++) {
        cout << "  vertex " << i << " -> color " << col[i] << "\n";
    }
    cout << "  Colors used: " << (mx + 1) << "\n\n";

    cout << "Chi(G) = chromatic number (minimum colors for proper coloring).\n";
    cout << "Greedy gives an UPPER bound, not always Chi(G).\n";
    cout << "Time: O(V^2 + E) with this forbidden vector; O(V+E) per vertex if max degree small.\n";

    return 0;
}
