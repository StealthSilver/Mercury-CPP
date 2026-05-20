// MODULE 40 — Max segment tree: point update

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

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update(2 * node, start, mid, idx, val);
    else update(2 * node + 1, mid + 1, end, idx, val);
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
    cout << "Module 40 — Max segment tree: update (i.cpp)\n";
    cout << "============================================\n\n";

    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    n = (int)arr.size();
    tree.assign(4 * n, 0);
    build(1, 0, n - 1, arr);

    cout << "  rangeMax(2,5) before = " << queryMax(1, 0, n - 1, 2, 5) << "\n";
    cout << "  pointUpdate(4, 12)   // arr[4]: 5 -> 12\n";
    update(1, 0, n - 1, 4, 12);
    cout << "  rangeMax(2,5) after  = " << queryMax(1, 0, n - 1, 2, 5) << " (expect 12)\n";
    cout << "  rangeMax(0,7) after  = " << queryMax(1, 0, n - 1, 0, 7) << " (expect 12)\n";
    return 0;
}
