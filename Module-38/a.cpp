// MODULE 38 — Coin Change: number of combinations (unbounded, order of coin types fixed)

#include <iostream>
#include <vector>
using namespace std;

// Count ways to make `amount` using coins (combinations — process coins in order)
long long coinCombNaive(int ci, int amount, const vector<int>& coins) {
    if (amount == 0) return 1;
    if (amount < 0 || ci == (int)coins.size()) return 0;
    long long ways = coinCombNaive(ci + 1, amount, coins);           // skip coin type
    ways += coinCombNaive(ci, amount - coins[ci], coins);            // use one more of coins[ci]
    return ways;
}

long long coinCombMemo(int ci, int amount, const vector<int>& coins,
                       vector<vector<long long>>& memo) {
    if (amount == 0) return 1;
    if (amount < 0 || ci == (int)coins.size()) return 0;
    if (memo[ci][amount] != -1) return memo[ci][amount];
    return memo[ci][amount] =
        coinCombMemo(ci + 1, amount, coins, memo) +
        coinCombMemo(ci, amount - coins[ci], coins, memo);
}

long long coinCombMemo(const vector<int>& coins, int amount) {
    vector<vector<long long>> memo(coins.size(), vector<long long>(amount + 1, -1));
    return coinCombMemo(0, amount, coins, memo);
}

// Tabulation: outer loop coin types, inner amount forward (combinations not permutations)
long long coinCombTab(const vector<int>& coins, int amount, bool trace) {
    vector<long long> dp(amount + 1, 0);
    dp[0] = 1;
    for (int c : coins) {
        if (trace) cout << "Coin " << c << ":\n";
        for (int a = c; a <= amount; a++) {
            dp[a] += dp[a - c];
            if (trace) cout << "  dp[" << a << "] += dp[" << (a - c) << "] -> " << dp[a] << "\n";
        }
    }
    if (trace) {
        cout << "Final dp: ";
        for (int a = 0; a <= amount; a++) cout << "a" << a << "=" << dp[a] << " ";
        cout << "\n";
    }
    return dp[amount];
}

int main() {
    cout << "Module 38 — Coin Change combinations (a.cpp)\n";
    cout << "============================================\n\n";

    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << "coins = {1, 2, 5}, amount = " << amount << "\n";
    cout << "Combinations (order of coin types fixed):\n";
    cout << "  5x1 | 3x1+1x2 | 1x1+2x2 | 1x5 => expect 4\n\n";

    cout << "  Naive:       " << coinCombNaive(0, amount, coins) << "\n";
    cout << "  Memoization: " << coinCombMemo(coins, amount) << "\n";
    cout << "  Tabulation trace:\n";
    long long tab = coinCombTab(coins, amount, true);
    cout << "  Answer:      " << tab << "\n\n";

    cout << "Same recurrence as unbounded knapsack COUNT; outer coin loop avoids permutations.\n";
    return 0;
}
