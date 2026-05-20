// MODULE 38 — Longest Increasing Subsequence (LIS)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int lisNaive(int idx, int prevIdx, const vector<int>& arr) {
    if (idx == (int)arr.size()) return 0;
    int skip = lisNaive(idx + 1, prevIdx, arr);
    int take = 0;
    if (prevIdx == -1 || arr[prevIdx] < arr[idx])
        take = 1 + lisNaive(idx + 1, idx, arr);
    return max(skip, take);
}

int lisMemo(int idx, int prevIdx, const vector<int>& arr, vector<vector<int>>& memo) {
    if (idx == (int)arr.size()) return 0;
    if (memo[idx][prevIdx + 1] != -1) return memo[idx][prevIdx + 1];
    int skip = lisMemo(idx + 1, prevIdx, arr, memo);
    int take = 0;
    if (prevIdx == -1 || arr[prevIdx] < arr[idx])
        take = 1 + lisMemo(idx + 1, idx, arr, memo);
    return memo[idx][prevIdx + 1] = max(skip, take);
}

// Classic O(n^2) DP: dp[i] = LIS ending at index i
int lisTabulation(const vector<int>& arr, bool trace) {
    int n = (int)arr.size();
    vector<int> dp(n, 1);
    int best = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        best = max(best, dp[i]);
        if (trace) cout << "  i=" << i << " arr[i]=" << arr[i] << " -> dp[i]=" << dp[i] << "\n";
    }
    return best;
}

// O(n log n) patience sort / tails array
int lisNLogN(const vector<int>& arr) {
    vector<int> tails;
    for (int x : arr) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end())
            tails.push_back(x);
        else
            *it = x;
    }
    return (int)tails.size();
}

int main() {
    cout << "Module 38 — Longest Increasing Subsequence (g.cpp)\n";
    cout << "==================================================\n\n";

    vector<int> arr = {50, 3, 10, 7, 40, 80};

    cout << "arr = {50, 3, 10, 7, 40, 80}\n\n";

    vector<vector<int>> memo(arr.size(), vector<int>(arr.size() + 1, -1));
    cout << "LIS length:\n";
    cout << "  Naive (prev index): " << lisNaive(0, -1, arr) << "\n";
    cout << "  Memoization:        " << lisMemo(0, -1, arr, memo) << "\n";
    cout << "  Tabulation O(n^2):\n";
    int tab = lisTabulation(arr, true);
    cout << "  Answer:             " << tab << " (expect 4, e.g. 3,7,40,80)\n";
    cout << "  O(n log n) tails:   " << lisNLogN(arr) << "\n\n";

    cout << "dp[i] = longest increasing subsequence ENDING at i.\n";
    return 0;
}
