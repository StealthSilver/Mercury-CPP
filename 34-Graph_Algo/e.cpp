// MODULE 34 — Detect cycle in undirected graph using DSU (Union–Find)

#include <iostream>
#include <vector>
using namespace std;

struct DSU {
    vector<int> parent, rankv;

    explicit DSU(int n) : parent(n), rankv(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

bool hasCycleUndirectedDSU(int V, const vector<pair<int, int>>& edges) {
    DSU dsu(V);
    for (auto [u, v] : edges) {
        if (!dsu.unite(u, v)) {
            return true;
        }
    }
    return false;
}

int main() {
    cout << "Module 34 — Undirected cycle: DSU (e.cpp)\n";
    cout << "=========================================\n\n";

    vector<pair<int, int>> tree = {{0, 1}, {1, 2}, {2, 3}};
    cout << "Tree edges: hasCycle = " << (hasCycleUndirectedDSU(4, tree) ? "true" : "false") << "\n";

    vector<pair<int, int>> cyc = {{0, 1}, {1, 2}, {2, 0}};
    cout << "Triangle edges: hasCycle = " << (hasCycleUndirectedDSU(3, cyc) ? "true" : "false") << "\n\n";

    cout << "If u and v are already connected, edge (u,v) closes a cycle.\n";
    cout << "Time: O(E * alpha(V)) ~ O(E)   Space: O(V)\n";

    return 0;
}
