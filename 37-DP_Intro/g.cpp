// MODULE 37 — Climbing Stairs variation: steps of 1, 2, or 3
// Count ways to reach stair n (LeetCode-style counting).

#include <iostream>
#include <vector>
using namespace std;

long long ways123Naive(int n) {
    if (n <= 0) return n == 0 ? 1 : 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return ways123Naive(n - 1) + ways123Naive(n - 2) + ways123Naive(n - 3);
}

long long ways123Tab(int n, bool trace) {
    if (n == 0) return 1;
    vector<long long> dp(n + 1);
    dp[0] = 1;  // one way at ground before climbing (optional convention)
    if (n >= 1) dp[1] = 1;
    if (n >= 2) dp[2] = 2;
    if (trace && n >= 1) {
        cout << "Base: ways(1)=1, ways(2)=2\n";
        if (n == 0) return 1;
    }
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        if (trace)
            cout << "  ways(" << i << ") = " << dp[i - 1] << " + " << dp[i - 2] << " + "
                 << dp[i - 3] << " = " << dp[i] << "\n";
    }
    return n >= 3 ? dp[n] : (n == 2 ? 2LL : 1LL);
}

// Same recurrence, LeetCode indexing: reach exactly stair n from 0
long long ways123ReachN(int n) {
    if (n <= 2) return n;  // 1->1 way, 2->2 ways
    long long a = 1, b = 2, c = 4;  // ways(1), ways(2), ways(3)
    for (int i = 4; i <= n; i++) {
        long long d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return c;
}

int main() {
    cout << "Module 37 — Climbing Stairs: steps 1, 2, or 3 (g.cpp)\n";
    cout << "====================================================\n\n";

    int n = 5;
    cout << "Ways to reach stair " << n << " using steps {1, 2, 3}:\n";
    cout << "  Naive (small n only): " << ways123Naive(n) << "\n";
    cout << "  Tabulation:           " << ways123Tab(n, false) << "\n";
    cout << "  Rolling O(1) space:   " << ways123ReachN(n) << "\n\n";

    cout << "Table build for n=5:\n";
    ways123Tab(n, true);
    cout << "Answer: " << ways123Tab(n, false) << " ways\n\n";

    cout << "n=3 by hand: (1,1,1), (1,2), (2,1), (3) => 4 ways.\n";
    cout << "Recurrence: ways(n) = ways(n-1) + ways(n-2) + ways(n-3)\n";
    cout << "Time O(n), Space O(1) with three rolling variables.\n";
    return 0;
}
