// MODULE 40 — Segment tree structure: node count, levels, what each node means

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void explainStructure(int n) {
    int height = (n <= 1) ? 1 : (int)floor(log2(n - 1)) + 2;
    int nextPow2 = 1;
    while (nextPow2 < n) nextPow2 <<= 1;
    int leaves = nextPow2;
    int totalNodesHeap = 2 * nextPow2;  // 1-indexed tree[1..2*nextPow2-1] often enough

    cout << "  n (array size)     = " << n << "\n";
    cout << "  height (approx)    = " << height << " levels from root to deepest leaf\n";
    cout << "  padded leaf count  = " << leaves << " (next power of 2 >= n)\n";
    cout << "  safe array size    = 4*n = " << (4 * n) << " (competitive programming rule)\n";
    cout << "  heap slots used    = about " << totalNodesHeap << " (1-indexed 1..2*nextPow2-1)\n";
    cout << "\n  Node meaning:\n";
    cout << "    - Internal node = aggregate (sum/min/gcd) of its children's intervals\n";
    cout << "    - Leaf node i   = value of array at index i (or 0 if i >= n padding)\n";
    cout << "    - tree[1]       = answer over full range [0, n-1]\n";
}

void demoLevels(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i + 1;
    vector<long long> tree(4 * n, 0);

    auto build = [&](auto&& self, int node, int l, int r) -> void {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        self(self, 2 * node, l, m);
        self(self, 2 * node + 1, m + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    };
    if (n > 0) build(build, 1, 0, n - 1);

    cout << "  Example arr[i] = i+1 for n=" << n << ":\n";
    int pow2 = 1;
    while (pow2 < n) pow2 <<= 1;
    int maxIdx = 2 * pow2 - 1;
    int level = 0, cnt = 1, idx = 1;
    while (idx <= maxIdx) {
        cout << "    level " << level << " (interval width ~ "
             << (1 << max(0, (int)ceil(log2(n)) - level)) << "): ";
        for (int i = 0; i < cnt && idx <= maxIdx; i++, idx++)
            cout << tree[idx] << " ";
        cout << "\n";
        level++;
        cnt *= 2;
    }
}

int main() {
    cout << "Module 40 — Segment tree structure (b.cpp)\n";
    cout << "============================================\n\n";

    cout << "Why 4*n nodes?\n";
    cout << "  Complete binary tree on n leaves has <= 2n-1 nodes;\n";
    cout << "  1-indexed heap indexing leaves extra space; 4n is a safe upper bound.\n\n";

    explainStructure(8);
    cout << "\n";
    demoLevels(8);

    cout << "\n  Compare: prefix sum -> range query O(1), but point update O(n).\n";
    cout << "           segment tree -> both query and update O(log n).\n";
    return 0;
}
