// MODULE 40 — Lazy segment tree: range sum query (with propagation)

#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree, lazy;
int n;

void push(int node, int start, int end) {
    if (lazy[node] == 0) return;
    tree[node] += lazy[node] * (end - start + 1);
    if (start != end) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
}

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

void rangeAdd(int node, int start, int end, int l, int r, long long val) {
    push(node, start, end);
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        lazy[node] += val;
        push(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    rangeAdd(2 * node, start, mid, l, r, val);
    rangeAdd(2 * node + 1, mid + 1, end, l, r, val);
    push(2 * node, start, mid);
    push(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

long long rangeSum(int node, int start, int end, int l, int r) {
    push(node, start, end);
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return rangeSum(2 * node, start, mid, l, r) +
           rangeSum(2 * node + 1, mid + 1, end, l, r);
}

int main() {
    cout << "Module 40 — Lazy segment tree: range query (k.cpp)\n";
    cout << "==================================================\n\n";

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    n = (int)arr.size();
    tree.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
    build(1, 0, n - 1, arr);

    cout << "  Initial sum[0,7] = " << rangeSum(1, 0, n - 1, 0, 7) << "\n";
    cout << "  rangeAdd(2,5,+10) then query:\n";
    rangeAdd(1, 0, n - 1, 2, 5, 10);

    cout << "  sum[2,5] = " << rangeSum(1, 0, n - 1, 2, 5)
         << " (was 18, +10 on 4 cells -> 58)\n";
    cout << "  sum[0,7] = " << rangeSum(1, 0, n - 1, 0, 7) << " (was 36, +40 -> 76)\n";
    cout << "\n  Each query calls push() to apply pending lazy tags first.\n";
    return 0;
}
