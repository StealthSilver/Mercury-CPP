// MODULE 40 — Max segment tree: range max query

#include <climits>
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

int queryMax(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return INT_MIN;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return max(queryMax(2 * node, start, mid, l, r),
               queryMax(2 * node + 1, mid + 1, end, l, r));
}

int main() {
    cout << "Module 40 — Max segment tree: range query (h.cpp)\n";
    cout << "================================================\n\n";

    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    n = (int)arr.size();
    tree.assign(4 * n, 0);
    build(1, 0, n - 1, arr);

    int qi = 2, qj = 5;
    cout << "arr: ";
    for (int x : arr) cout << x << " ";
    cout << "\n  rangeMax(" << qi << "," << qj << ") = " << queryMax(1, 0, n - 1, qi, qj)
         << " (expect max of 4,1,5,9 = 9)\n";
    cout << "  rangeMax(0,7) = " << queryMax(1, 0, n - 1, 0, 7) << "\n";
    return 0;
}
