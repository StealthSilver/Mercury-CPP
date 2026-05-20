// MODULE 36 — Disjoint Set Union (Union–Find) with path compression + union by rank

#include <iostream>
#include <vector>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> rankv;

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

    bool same(int a, int b) { return find(a) == find(b); }
};

int main() {
    cout << "Module 36 — Disjoint Set Union (h.cpp)\n";
    cout << "======================================\n\n";

    DSU dsu(5);
    cout << "Start: each element in its own set {0},{1},{2},{3},{4}\n";
    dsu.unite(0, 1);
    dsu.unite(2, 3);
    cout << "After unite(0,1) and unite(2,3):\n";
    cout << "   same(0,1)? " << (dsu.same(0, 1) ? "yes" : "no") << "\n";
    cout << "   same(1,2)? " << (dsu.same(1, 2) ? "yes" : "no") << "\n";
    dsu.unite(1, 2);
    cout << "After unite(1,2): same(0,3)? " << (dsu.same(0, 3) ? "yes" : "no") << "\n\n";

    cout << "find: path compression. unite: union by rank.\n";
    cout << "Time: find/unite O(alpha(n)) amortized ~ O(1)\n";
    cout << "Space: O(n)\n";

    return 0;
}
