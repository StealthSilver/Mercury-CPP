// MODULE 39 — Matrix Chain Multiplication: memoization

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int mcmMemo(int i, int j, const vector<int>& dims, vector<vector<int>>& memo) {
    if (i >= j) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    int best = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = mcmMemo(i, k, dims, memo) + mcmMemo(k + 1, j, dims, memo) +
                   dims[i] * dims[k + 1] * dims[j + 1];
        best = min(best, cost);
    }
    return memo[i][j] = best;
}

int mcmMemoSolve(const vector<int>& dims) {
    int n = (int)dims.size() - 1;
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return mcmMemo(0, n - 1, dims, memo);
}

int main() {
    cout << "Module 39 — MCM: memoization (h.cpp)\n";
    cout << "==================================\n\n";

    vector<int> dims = {1, 2, 3, 4, 3};
    cout << "dims = {1, 2, 3, 4, 3}\n";
    cout << "  memo[i][j] = min cost to multiply matrices i..j\n\n";

    int ans = mcmMemoSolve(dims);
    cout << "  Minimum cost (memo): " << ans << " (expect 30)\n";
    cout << "  Time: O(n^3), Space: O(n^2)\n";
    return 0;
}
