// MODULE 40 — Segment tree: range sum query + point update

#include <iostream>
#include <vector>
using namespace std;

class SumSegTree {
    int n;
    vector<long long> tree;

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

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) +
               query(2 * node + 1, mid + 1, end, l, r);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

public:
    SumSegTree(const vector<int>& arr) : n((int)arr.size()), tree(4 * n, 0) {
        if (n > 0) build(1, 0, n - 1, arr);
    }

    long long rangeSum(int l, int r) { return query(1, 0, n - 1, l, r); }
    void pointUpdate(int idx, int val) { update(1, 0, n - 1, idx, val); }

    void printTreeLevels() const {
        cout << "  tree[1..] stores aggregates (1-indexed heap):\n";
        int pow2 = 1;
        while (pow2 < n) pow2 <<= 1;
        int maxIdx = 2 * pow2 - 1;
        int level = 0, nodesAtLevel = 1, idx = 1;
        while (idx <= maxIdx) {
            cout << "    level " << level << ": ";
            for (int i = 0; i < nodesAtLevel && idx <= maxIdx; i++, idx++)
                cout << "tree[" << idx << "]=" << tree[idx] << "  ";
            cout << "\n";
            level++;
            nodesAtLevel *= 2;
        }
    }
};

int main() {
    cout << "Module 40 — Segment tree: sum (a.cpp)\n";
    cout << "======================================\n\n";

    vector<int> arr = {2, 1, 5, 3, 4, 6, 2, 7};
    cout << "Array (n=8): ";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";

    SumSegTree st(arr);
    st.printTreeLevels();

    cout << "\n  rangeSum(2, 5) = " << st.rangeSum(2, 5) << " (expect 5+3+4+6=18)\n";
    cout << "  rangeSum(0, 7) = " << st.rangeSum(0, 7) << " (expect 30)\n";

    cout << "\n  pointUpdate(3, 10)  // arr[3]: 3 -> 10\n";
    st.pointUpdate(3, 10);
    cout << "  rangeSum(2, 5) = " << st.rangeSum(2, 5) << " (expect 5+10+4+6=25)\n";
    cout << "  rangeSum(0, 7) = " << st.rangeSum(0, 7) << " (expect 37)\n";

    cout << "\n  query / update visit O(log n) nodes on one root-to-leaf path.\n";
    return 0;
}
