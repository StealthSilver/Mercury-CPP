// MODULE 33 — Edge list (store edges explicitly; common for MST / Kruskal)

#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    cout << "Module 33 — Edge List (d.cpp)\n";
    cout << "=============================\n\n";

    using Edge = tuple<int, int, int>;
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 2},
        {2, 3, 5},
    };

    cout << "Weighted undirected edges (u, v, weight):\n";
    for (auto [u, v, w] : edges) {
        cout << "  (" << u << ", " << v << ", w=" << w << ")\n";
    }

    cout << "\nWhy edge lists?\n";
    cout << "  • Sorting edges by weight is O(E log E) — Kruskal's MST does this.\n";
    cout << "  • When algorithms only touch edges (not all vertex pairs), edge list is natural.\n";
    cout << "  • Can convert to adjacency list in O(E) for local neighbor queries.\n";

    return 0;
}
