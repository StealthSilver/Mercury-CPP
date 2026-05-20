// MODULE 37 — Unbounded Knapsack: unlimited copies of each item

#include <iostream>
#include <vector>
using namespace std;

int unboundedRecursive(int i, int w, const vector<int>& wt, const vector<int>& val,
                       vector<vector<int>>& memo) {
    if (i == 0 || w == 0) return 0;
    if (memo[i][w] != -1) return memo[i][w];
    int best = unboundedRecursive(i - 1, w, wt, val, memo);  // skip using item i-1 further
    if (wt[i - 1] <= w)
        best = max(best, val[i - 1] + unboundedRecursive(i, w - wt[i - 1], wt, val, memo));
    return memo[i][w] = best;
}

int unboundedMemo(int n, int W, const vector<int>& wt, const vector<int>& val) {
    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1));
    return unboundedRecursive(n, W, wt, val, memo);
}

// 1D tabulation: loop capacity FORWARD from wt[i] to W
int unboundedTab(int n, int W, const vector<int>& wt, const vector<int>& val, bool trace) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int w = wt[i]; w <= W; w++) {
            int cand = val[i] + dp[w - wt[i]];
            if (trace && w == W) cout << "  item " << i << " at w=" << w << ": try " << cand << "\n";
            dp[w] = max(dp[w], cand);
        }
    }
    if (trace) {
        cout << "dp[w] = max value with capacity w:\n  ";
        for (int w = 0; w <= W; w++) cout << "w" << w << "=" << dp[w] << " ";
        cout << "\n";
    }
    return dp[W];
}

int main() {
    cout << "Module 37 — Unbounded Knapsack (i.cpp)\n";
    cout << "======================================\n\n";

    // Classic: unlimited supply of each "item type"
    vector<int> wt = {1, 3, 4};
    vector<int> val = {15, 20, 30};
    int W = 7, n = (int)wt.size();

    cout << "Types (w,v): ";
    for (int i = 0; i < n; i++) cout << "(" << wt[i] << "," << val[i] << ") ";
    cout << "  capacity W=" << W << " (unlimited copies each)\n\n";

    cout << "Max value:\n";
    cout << "  Memoization: " << unboundedMemo(n, W, wt, val) << "\n";
    cout << "  1D tab (forward w):\n";
    int ans = unboundedTab(n, W, wt, val, true);
    cout << "  Answer: " << ans << " (seven copies of weight-1: 7*15=105)\n\n";

    // Better demo: W=8 -> 2*30 + 2*1 = 60 or 2*30 + val from 2...
    // wt1=1 v15, wt2=3 v20, wt3=4 v30, W=7: best often 2*item3 + 3*item1? 2*30+3*15=105 too big weight
    // 7 = 4+3 -> 30+20=50, or 4+1+1+1 -> 30+45=75? 1+1+1+4 invalid order
    // 7 = 3+3+1 -> 20+20+15=55
    // Let me recalc: unbounded W=7, items (1,15)(3,20)(4,30)
    // 7x1=105, 2*3+1=55, 1*4+3=50, 1*4+1*3=50, 1*4+3*1=75? 4+1+1+1=7 -> 30+45=75
    cout << "Recurrence: dp[w] = max_i ( val[i] + dp[w - wt[i]] )\n";
    cout << "Loop w from wt[i] to W (FORWARD) — unlike 0/1 knapsack.\n";
    return 0;
}
