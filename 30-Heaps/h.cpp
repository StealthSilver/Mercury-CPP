// MODULE 30 — Problem 3: K weakest rows in a matrix (min-heap on pair)

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int countSoldiers(const vector<int>& row) {
    int c = 0;
    for (int x : row) {
        if (x == 1) {
            ++c;
        } else {
            break;
        }
    }
    return c;
}

vector<int> kWeakestRows(const vector<vector<int>>& mat, int k) {
    using RowKey = pair<int, int>;  // (soldiers, row index)

    priority_queue<RowKey, vector<RowKey>, greater<RowKey>> pq;

    cout << "  Row strengths (soldiers, index):\n";
    for (int i = 0; i < static_cast<int>(mat.size()); ++i) {
        int s = countSoldiers(mat[i]);
        pq.push({s, i});
        cout << "    row " << i << ": ";
        for (int x : mat[i]) {
            cout << x << " ";
        }
        cout << " → (" << s << ", " << i << ")\n";
    }

    vector<int> ans;
    cout << "\n  Pop K weakest from min-heap:\n";
    for (int t = 0; t < k && !pq.empty(); ++t) {
        auto [s, i] = pq.top();
        pq.pop();
        cout << "    pop → row " << i << "  (soldiers=" << s << ")\n";
        ans.push_back(i);
    }
    return ans;
}

int main() {
    cout << "Problem 3: K weakest soldier rows\n";
    cout << "=================================\n\n";

    vector<vector<int>> mat = {
        {1, 1, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 0},
    };
    int k = 2;

    cout << "Matrix:\n";
    for (int i = 0; i < static_cast<int>(mat.size()); ++i) {
        cout << "  row " << i << ": ";
        for (int x : mat[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }
    cout << "\nK = " << k << "\n\n";

    vector<int> weak = kWeakestRows(mat, k);

    cout << "\nAnswer (weakest row indices): [";
    for (int i = 0; i < static_cast<int>(weak.size()); ++i) {
        if (i) {
            cout << ", ";
        }
        cout << weak[i];
    }
    cout << "]\n";

    cout << "\nTime: O(m·n + m log m)   Space: O(m)\n";
    return 0;
}
