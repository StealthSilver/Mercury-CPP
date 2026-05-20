// MODULE 36 — Min Cost to Connect All Points (MST with Manhattan distance on complete graph)

#include <algorithm>
#include <cmath>
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

int manhattan(const vector<int>& a, const vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

long long minCostConnectPoints(const vector<vector<int>>& points) {
    int n = static_cast<int>(points.size());
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({manhattan(points[i], points[j]), i, j});
        }
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long total = 0;
    int used = 0;
    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            total += w;
            used++;
        }
    }
    return total;
}

int main() {
    cout << "Module 36 — Min Cost Connect All Points (e.cpp)\n";
    cout << "===============================================\n\n";

    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << "Points (LeetCode 1584 example): ";
    for (auto& p : points) cout << "[" << p[0] << "," << p[1] << "] ";
    cout << "\n";

    long long ans = minCostConnectPoints(points);
    cout << "Minimum total Manhattan wiring (MST) = " << ans << "  (expected 20)\n\n";

    cout << "Complete graph: edge (i,j) weight = |dx|+|dy|. Run Kruskal.\n";
    cout << "Naive: O(n^2) edges, O(n^2 log n) sort — Prim variant O(n^2) possible without all edges.\n";
    cout << "Space: O(n^2) edges worst case\n";

    return 0;
}
