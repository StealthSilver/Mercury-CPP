// MODULE 40 — Max segment tree: creation (vector 4*n + build)

#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;
int n;

void build(int node, int start, int end, const vector<int>& arr) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid, arr);
    build(2 * node + 1, mid + 1, end, arr);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int main() {
    cout << "Module 40 — Max segment tree: create (g.cpp)\n";
    cout << "============================================\n\n";

    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    n = (int)arr.size();
    tree.assign(4 * n, 0);

    cout << "arr: ";
    for (int x : arr) cout << x << " ";
    cout << "\n\ntree.resize(4*n); build with combine = max\n\n";

    build(1, 0, n - 1, arr);
    cout << "  tree[1] = max[0.." << (n - 1) << "] = " << tree[1] << " (expect 9)\n";
    cout << "  tree[2] = max[0..3] = " << tree[2] << " (expect 4)\n";
    cout << "  tree[3] = max[4..7] = " << tree[3] << " (expect 9)\n";
    return 0;
}
