// MODULE 38 — Rod Cutting: maximize revenue cutting rod of length n

#include <iostream>
#include <vector>
using namespace std;

// price[i] = selling price of a piece of length (i+1)
int rodCutNaive(int len, const vector<int>& price) {
    if (len == 0) return 0;
    int best = 0;
    for (int cut = 1; cut <= len; cut++)
        best = max(best, price[cut - 1] + rodCutNaive(len - cut, price));
    return best;
}

int rodCutMemo(int len, const vector<int>& price, vector<int>& memo) {
    if (len == 0) return 0;
    if (memo[len] != -1) return memo[len];
    int best = 0;
    for (int cut = 1; cut <= len; cut++)
        best = max(best, price[cut - 1] + rodCutMemo(len - cut, price, memo));
    return memo[len] = best;
}

int rodCutMemo(int rodLen, const vector<int>& price) {
    vector<int> memo(rodLen + 1, -1);
    return rodCutMemo(rodLen, price, memo);
}

int rodCutTab(int rodLen, const vector<int>& price, bool trace) {
    vector<int> dp(rodLen + 1, 0);
    for (int len = 1; len <= rodLen; len++) {
        for (int cut = 1; cut <= len; cut++)
            dp[len] = max(dp[len], price[cut - 1] + dp[len - cut]);
        if (trace) cout << "  len " << len << " -> max profit " << dp[len] << "\n";
    }
    return dp[rodLen];
}

int main() {
    cout << "Module 38 — Rod Cutting (b.cpp)\n";
    cout << "===============================\n\n";

    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int rodLen = 8;

    cout << "Lengths 1..8, price[i] = price for piece length (i+1)\n";
    cout << "Rod length = " << rodLen << "\n\n";

    cout << "Max profit:\n";
    cout << "  Naive:       " << rodCutNaive(rodLen, price) << "\n";
    cout << "  Memoization: " << rodCutMemo(rodLen, price) << "\n";
    cout << "  Tabulation:\n";
    int ans = rodCutTab(rodLen, price, true);
    cout << "  Answer:      " << ans << " (expect 22: e.g. 2+6)\n\n";

    cout << "dp[len] = max_{cut} ( price[cut-1] + dp[len-cut] ) — unbounded knapsack on length.\n";
    return 0;
}
