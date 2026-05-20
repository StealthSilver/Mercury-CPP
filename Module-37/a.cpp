// MODULE 37 — Fibonacci: naive recursion vs dynamic programming (memoization & tabulation)

#include <iostream>
#include <vector>
using namespace std;

// Naive recursion: F(n) = F(n-1) + F(n-2), base F(0)=0, F(1)=1
// Time ~ O(phi^n), space O(n) call stack
long long fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Top-down DP (memoization): each subproblem solved once
long long fibMemo(int n, vector<long long>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
}

long long fibMemo(int n) {
    vector<long long> memo(n + 1, -1);
    return fibMemo(n, memo);
}

// Bottom-up DP (tabulation): fill table in increasing n
long long fibTabulation(int n) {
    if (n <= 1) return n;
    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// Space-optimized tabulation: only last two values needed
long long fibTabulationO1Space(int n) {
    if (n <= 1) return n;
    long long prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        long long cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    cout << "Module 37 — Fibonacci: recursion vs DP (a.cpp)\n";
    cout << "================================================\n\n";

    int n = 10;
    cout << "n = " << n << "\n";
    cout << "  Naive recursion:     F(" << n << ") = " << fibRecursive(n) << "\n";
    cout << "  Memoization (top-down): F(" << n << ") = " << fibMemo(n) << "\n";
    cout << "  Tabulation (bottom-up): F(" << n << ") = " << fibTabulation(n) << "\n";
    cout << "  Tabulation O(1) space:  F(" << n << ") = " << fibTabulationO1Space(n) << "\n\n";

    cout << "Why naive recursion is slow for large n:\n";
    cout << "  fib(5) recomputes fib(3), fib(2), fib(1) many times.\n";
    cout << "  Subproblems overlap → exponential call count ~ O(1.618^n).\n";
    cout << "  DP stores each F(k) once → O(n) time, O(n) or O(1) space.\n\n";

    cout << "Try n=40: recursion may hang; memo/tabulation are instant.\n";
    return 0;
}
