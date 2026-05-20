// MODULE 36 — LeetCode 765: Couples Holding Hands (DSU on couples)

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

struct DSU {
    vector<int> p;
    int comps;
    explicit DSU(int n) : p(n), comps(n) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) { return p[x] == x ? x : (p[x] = find(p[x])); }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            p[b] = a;
            comps--;
        }
    }
};

// Couple k occupies people (2k, 2k+1). Seats 2i and 2i+1 should hold one couple.
// For each pair of seats, merge the couple-indices of the two occupants.
// If persons from c1 and c2 sit together, those couples are "linked"; one swap can
// fix two pairs — formula: swaps = nCouples - connectedComponents.
int minSwapsCouplesRow(const vector<int>& row) {
    int nCouples = (int)row.size() / 2;
    DSU dsu(nCouples);
    for (int i = 0; i < (int)row.size(); i += 2) {
        int a = row[i] / 2;
        int b = row[i + 1] / 2;
        dsu.unite(a, b);
    }
    return nCouples - dsu.comps;
}

int main() {
    cout << "Module 36 — Couples Holding Hands (o.cpp)\n";
    cout << "========================================\n\n";
    vector<int> row = {0, 2, 1, 3};
    cout << "row [0,2,1,3] -> min swaps = " << minSwapsCouplesRow(row) << " (expect 1)\n";
    vector<int> row2 = {3, 2, 0, 1};
    cout << "row [3,2,0,1] -> min swaps = " << minSwapsCouplesRow(row2) << " (expect 0)\n";
    return 0;
}
