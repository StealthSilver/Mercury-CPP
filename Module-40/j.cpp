// MODULE 40 — Lazy segment tree: creation (tree 4*n + lazy tag array)

#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree, lazy;
int n;

void build(int node, int start, int end, const vector<int>& arr) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid, arr);
    build(2 * node + 1, mid + 1, end, arr);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {
    cout << "Module 40 — Lazy segment tree: create (j.cpp)\n";
    cout << "=============================================\n\n";

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    n = (int)arr.size();
    tree.assign(4 * n, 0);
    lazy.assign(4 * n, 0);

    cout << "Step 1: tree.assign(4*n, 0)\n";
    cout << "Step 2: lazy.assign(4*n, 0)  // pending range-add tags\n";
    cout << "Step 3: build sum tree\n\n";

    build(1, 0, n - 1, arr);
    cout << "  tree[1] = sum = " << tree[1] << " (expect 36)\n";
    cout << "  lazy[i] = 0 means no pending add on that node's interval\n";
    cout << "\n  Supports: range add on [l,r], range sum query (see k.cpp, l.cpp)\n";
    return 0;
}
