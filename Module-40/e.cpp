// MODULE 40 — Point update on segment tree (sum)

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

void update(int node, int start, int end, int idx, int val, int d = 0) {
    string ind(d * 2, ' ');
    if (start == end) {
        cout << ind << "leaf node " << node << " [" << idx << "," << idx << "]: set " << tree[node]
             << " -> " << val << "\n";
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    cout << ind << "node " << node << " [" << start << "," << end << "] go "
         << (idx <= mid ? "LEFT" : "RIGHT") << "\n";
    if (idx <= mid) update(2 * node, start, mid, idx, val, d + 1);
    else update(2 * node + 1, mid + 1, end, idx, val, d + 1);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    cout << ind << "recompute tree[" << node << "] = " << tree[node] << "\n";
}

long long query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

int main() {
    cout << "Module 40 — Segment tree point update (e.cpp)\n";
    cout << "=============================================\n\n";

    vector<int> arr = {2, 1, 5, 3, 4, 6, 2, 7};
    n = (int)arr.size();
    tree.assign(4 * n, 0);
    build(1, 0, n - 1, arr);

    cout << "Before: sum[2,5] = " << query(1, 0, n - 1, 2, 5) << "\n\n";
    cout << "update(idx=3, val=10):\n";
    update(1, 0, n - 1, 3, 10);
    cout << "\nAfter:  sum[2,5] = " << query(1, 0, n - 1, 2, 5) << " (expect 25)\n";
    cout << "        sum[0,7] = " << query(1, 0, n - 1, 0, 7) << " (expect 37)\n";
    return 0;
}
