// MODULE 40 — Range sum query: no overlap, complete overlap, partial overlap

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<long long> tree;
int n;
int depth = 0;

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

long long query(int node, int start, int end, int l, int r, const string& path) {
    string indent(depth * 2, ' ');
    if (r < start || end < l) {
        cout << indent << "node " << node << " [" << start << "," << end
             << "] vs Q[" << l << "," << r << "] -> NO OVERLAP -> 0\n";
        return 0;
    }
    if (l <= start && end <= r) {
        cout << indent << "node " << node << " [" << start << "," << end
             << "] vs Q[" << l << "," << r << "] -> COMPLETE OVERLAP -> tree[" << node
             << "]=" << tree[node] << "\n";
        return tree[node];
    }
    cout << indent << "node " << node << " [" << start << "," << end << "] vs Q[" << l << ","
         << r << "] -> PARTIAL OVERLAP -> split\n";
    int mid = (start + end) / 2;
    depth++;
    long long left = query(2 * node, start, mid, l, r, path + "L");
    long long right = query(2 * node + 1, mid + 1, end, l, r, path + "R");
    depth--;
    return left + right;
}

int main() {
    cout << "Module 40 — Segment tree queries (d.cpp)\n";
    cout << "========================================\n\n";

    vector<int> arr = {2, 1, 5, 3, 4, 6, 2, 7};
    n = (int)arr.size();
    tree.assign(4 * n, 0);
    build(1, 0, n - 1, arr);

    int qi = 2, qj = 5;
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nQuery Q[" << qi << "," << qj << "] = sum of arr[2..5]\n\n";

    long long ans = query(1, 0, n - 1, qi, qj, "");
    cout << "\n  Answer = " << ans << " (expect 5+3+4+6 = 18)\n";
    cout << "\n  Three cases:\n";
    cout << "    NO OVERLAP     — interval disjoint from Q -> return neutral (0)\n";
    cout << "    COMPLETE       — node interval inside Q -> return tree[node]\n";
    cout << "    PARTIAL        — recurse to children that intersect Q\n";
    return 0;
}
