// MODULE 37 — 0/1 Knapsack: each item at most once

#include <iostream>
#include <vector>
using namespace std;

// State: best value using items 0..i-1 with capacity w
int knap01Recursive(int i, int w, const vector<int>& wt, const vector<int>& val,
                    vector<vector<int>>& memo) {
    if (i == 0 || w == 0) return 0;
    if (memo[i][w] != -1) return memo[i][w];
    int skip = knap01Recursive(i - 1, w, wt, val, memo);
    int take = 0;
    if (wt[i - 1] <= w)
        take = val[i - 1] + knap01Recursive(i - 1, w - wt[i - 1], wt, val, memo);
    return memo[i][w] = max(skip, take);
}

int knap01Memo(int n, int W, const vector<int>& wt, const vector<int>& val) {
    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1));
    return knap01Recursive(n, W, wt, val, memo);
}

// 2D tabulation: dp[i][w]
int knap01Table2D(int n, int W, const vector<int>& wt, const vector<int>& val, bool trace) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
        }
    }
    if (trace) {
        cout << "dp table (rows=item prefix, cols=capacity):\n";
        cout << "     ";
        for (int w = 0; w <= W; w++) cout << "w=" << w << "\t";
        cout << "\n";
        for (int i = 0; i <= n; i++) {
            cout << "i=" << i << " ";
            for (int w = 0; w <= W; w++) cout << dp[i][w] << "\t";
            cout << "\n";
        }
    }
    return dp[n][W];
}

// 1D space: MUST loop capacity W down to wt[i] when processing item i
int knap01Space1D(int n, int W, const vector<int>& wt, const vector<int>& val) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++)
        for (int w = W; w >= wt[i]; w--)
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
    return dp[W];
}

int main() {
    cout << "Module 37 — 0/1 Knapsack (h.cpp)\n";
    cout << "================================\n\n";

    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7, n = (int)wt.size();

    cout << "Items (w,v): ";
    for (int i = 0; i < n; i++) cout << "(" << wt[i] << "," << val[i] << ") ";
    cout << "  capacity W=" << W << "\n\n";

    cout << "Max value:\n";
    cout << "  Memoization:  " << knap01Memo(n, W, wt, val) << "\n";
    cout << "  2D table:     " << knap01Table2D(n, W, wt, val, true) << "\n";
    cout << "  1D (W down):  " << knap01Space1D(n, W, wt, val) << " (expect 9: items 2+3)\n\n";

    cout << "Decision per item: TAKE or SKIP (each item at most once).\n";
    cout << "Time O(n*W), Space O(W) with 1D DP.\n";
    return 0;
}
