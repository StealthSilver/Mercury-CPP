// MODULE 36 — LeetCode 684: Redundant Connection (undirected tree + one extra edge)

#include <iostream>
#include <vector>
using namespace std;

struct DSU {
    vector<int> p;
    explicit DSU(int n) : p(n) {
        for (int i = 0; i < n; i++) p[i] = i;
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

// Graph was a tree on n nodes; exactly n undirected edges are given (one extra).
// Remove one edge so the graph is a tree again. If several edges work, return the
// one that appears last in `edges`.
vector<int> findRedundantConnection(const vector<vector<int>>& edges) {
    int n = (int)edges.size();
    DSU dsu(n + 1);  // nodes labeled 1..n
    vector<int> ans;
    for (const auto& e : edges) {
        int u = e[0], v = e[1];
        if (!dsu.unite(u, v))
            ans = e;  // tree + one chord ⇒ this edge lies on the unique cycle; keep last in input
    }
    return ans;
}

int main() {
    cout << "Module 36 — Redundant Connection (j.cpp)\n";
    cout << "========================================\n\n";
    vector<vector<int>> ex1 = {{1, 2}, {1, 3}, {2, 3}};
    auto r1 = findRedundantConnection(ex1);
    cout << "Example 1: {1,2},{1,3},{2,3} -> redundant edge: [" << r1[0] << "," << r1[1]
         << "] (expect 2,3)\n";
    vector<vector<int>> ex2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    auto r2 = findRedundantConnection(ex2);
    cout << "Example 2: ... -> redundant edge: [" << r2[0] << "," << r2[1] << "] (expect 1,4)\n";
    return 0;
}
