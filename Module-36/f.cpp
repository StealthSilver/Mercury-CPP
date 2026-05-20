// MODULE 36 — Min Cost to Connect All Cities (MST — given edges; return -1 if not connected)

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

long long connectAllCities(int n, vector<vector<int>>& connections) {
    vector<tuple<int, int, int>> edges;
    for (const auto& c : connections) {
        int u = c[0] - 1;
        int v = c[1] - 1;
        int w = c[2];
        edges.push_back({w, u, v});
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
    if (used != n - 1) return -1;
    return total;
}

int main() {
    cout << "Module 36 — Min Cost Connect All Cities (f.cpp)\n";
    cout << "================================================\n\n";

    cout << "LeetCode 1135 style: connections [u, v, cost] with cities 1..n\n\n";

    int n = 3;
    vector<vector<int>> con1 = {{1, 2, 5}, {1, 3, 6}, {2, 3, 1}};
    cout << "n=3, edges (1-2,5), (1-3,6), (2-3,1)  =>  MST cost = " << connectAllCities(n, con1)
         << "  (expected 6)\n";

    n = 4;
    vector<vector<int>> con2 = {{1, 2, 3}, {3, 4, 4}};
    long long r = connectAllCities(n, con2);
    cout << "n=4, only two edges (disconnected) => " << (r < 0 ? -1 : r) << "  (expected -1)\n\n";

    cout << "If fewer than n-1 MST edges, graph of cities is disconnected.\n";
    cout << "Time: O(E log E)   Space: O(E)\n";

    return 0;
}
