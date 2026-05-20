// MODULE 36 — LeetCode 685: Redundant Connection II (directed rooted tree + one extra edge)

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

struct DSU {
    vector<int> p;
    explicit DSU(int n) : p(n) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) { return p[x] == x ? x : (p[x] = find(p[x])); }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        p[b] = a;
        return true;
    }
};

static bool hasCycleSkipping(const vector<vector<int>>& edges, int skip) {
    int n = (int)edges.size();
    DSU dsu(n + 1);
    for (int i = 0; i < n; i++) {
        if (i == skip) continue;
        int u = edges[i][0], v = edges[i][1];
        if (!dsu.unite(u, v)) return true;
    }
    return false;
}

vector<int> findRedundantDirectedConnection(vector<vector<int>> edges) {
    int n = (int)edges.size();
    vector<int> intoParent(n + 1, -1), cand;
    for (int i = 0; i < n; i++) {
        int v = edges[i][1];
        if (intoParent[v] != -1) {
            cand = {intoParent[v], i};  // indices of two edges pointing to v (first, second)
            break;
        }
        intoParent[v] = i;
    }

    // Case A: some node has two parents — exactly one of the two edges is the
    // redundant extra (or removing the right one breaks both cycle + double parent).
    if (!cand.empty()) {
        if (!hasCycleSkipping(edges, cand[1])) return edges[cand[1]];
        return edges[cand[0]];
    }

    // Case B: every node has at most one parent — the extra edge completes a directed cycle.
    DSU dsu(n + 1);
    for (int i = 0; i < n; i++) {
        int u = edges[i][0], v = edges[i][1];
        if (!dsu.unite(u, v)) return edges[i];
    }
    return {};
}

int main() {
    cout << "Module 36 — Redundant Connection II (n.cpp)\n";
    cout << "===========================================\n\n";
    vector<vector<int>> ex1 = {{1, 2}, {1, 3}, {2, 3}};
    auto a = findRedundantDirectedConnection(ex1);
    cout << "Tree+cycle: -> remove [" << a[0] << "," << a[1] << "] (expect 2,3)\n";
    vector<vector<int>> ex2 = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}};
    auto b = findRedundantDirectedConnection(ex2);
    cout << "Case with two parents / later edge: [" << b[0] << "," << b[1] << "]\n";
    return 0;
}
