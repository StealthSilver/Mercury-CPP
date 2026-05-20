// MODULE 40 — Create segment tree: vector resize 4*n, then build (sum)

#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree;
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
    cout << "Module 40 — Create segment tree (c.cpp)\n";
    cout << "======================================\n\n";

    vector<int> arr = {2, 1, 5, 3, 4, 6, 2, 7};
    n = (int)arr.size();

    cout << "Step 1: n = " << n << "\n";
    cout << "Step 2: tree.resize(4 * n)  -> size " << (4 * n) << "\n";
    tree.assign(4 * n, 0);

    cout << "Step 3: build(1, 0, n-1, arr)  // root at index 1\n";
    build(1, 0, n - 1, arr);

    cout << "\n  arr: ";
    for (int x : arr) cout << x << " ";
    cout << "\n  tree[1] (sum of full array) = " << tree[1] << " (expect 30)\n";
    cout << "  tree[2] ([0..3]) = " << tree[2] << ", tree[3] ([4..7]) = " << tree[3] << "\n";
    cout << "\n  Time O(n), space O(n) in tree array.\n";
    return 0;
}
