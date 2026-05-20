// MODULE 36 — Kruskal's algorithm (MST via sorting edges + DSU)

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n), r(n, 0) {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

long long kruskalMST(int V, vector<tuple<int, int, int>>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(V);
    long long total = 0;
    int used = 0;
    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            total += w;
            used++;
        }
    }
    return (used == V - 1) ? total : -1;
}

int main() {
    cout << "Module 36 — Kruskal MST (d.cpp)\n";
    cout << "===============================\n\n";

    int V = 5;
    vector<tuple<int, int, int>> edges = {
        {9, 0, 1},
        {75, 0, 2},
        {95, 1, 2},
        {19, 1, 3},
        {42, 1, 4},
        {51, 2, 3},
        {66, 2, 4},
        {31, 3, 4},
    };

    long long cost = kruskalMST(V, edges);
    cout << "MST total weight (Kruskal) = " << cost << " (should match Prim on same graph)\n\n";

    cout << "Sort edges ascending; add edge if it connects two components (DSU).\n";
    cout << "Time: O(E log E) sort + O(E * alpha(V)) DSU\n";
    cout << "Space: O(V + E)\n";

    return 0;
}
