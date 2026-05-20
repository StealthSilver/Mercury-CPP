// MODULE 37 — Type 2: Tabulation (bottom-up DP) — Fibonacci table fill trace

#include <iostream>
#include <vector>
using namespace std;

long long fibTabulationTrace(int n, bool printTable) {
    if (n <= 1) return n;
    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    if (printTable) {
        cout << "Base cases: dp[0]=0, dp[1]=1\n";
        cout << "Fill i = 2 .. " << n << " using dp[i] = dp[i-1] + dp[i-2]\n\n";
    }

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        if (printTable) {
            cout << "  i=" << i << ": dp[" << i << "] = dp[" << (i - 1) << "] + dp[" << (i - 2)
                 << "] = " << dp[i - 1] << " + " << dp[i - 2] << " = " << dp[i] << "\n";
        }
    }
    return dp[n];
}

long long fibRolling(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    cout << "Module 37 — Tabulation / bottom-up DP (c.cpp)\n";
    cout << "============================================\n\n";

    int n = 8;
    cout << "--- Full table dp[0.." << n << "] ---\n";
    long long ans = fibTabulationTrace(n, true);

    cout << "\nAnswer: F(" << n << ") = " << ans << "\n";
    cout << "\n--- Space O(1): rolling variables only ---\n";
    cout << "F(" << n << ") with rolling = " << fibRolling(n) << "\n\n";

    cout << "Pattern: choose loop order so every dp[i] only uses already-filled cells.\n";
    return 0;
}
