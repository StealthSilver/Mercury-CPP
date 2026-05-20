// MODULE 39 — Catalan numbers — bottom-up tabulation

#include <iostream>
#include <vector>
using namespace std;

long long catalanTab(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    if (n >= 1) dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int k = 0; k < i; k++)
            dp[i] += dp[k] * dp[i - 1 - k];
    }
    return dp[n];
}

// Closed form (for verification): C_n = binomial(2n,n) / (n+1)
long long binomial(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    long long res = 1;
    for (int i = 0; i < k; i++)
        res = res * (n - i) / (i + 1);
    return res;
}

long long catalanFormula(int n) {
    return binomial(2 * n, n) / (n + 1);
}

int main() {
    cout << "Module 39 — Catalan numbers: tabulation (d.cpp)\n";
    cout << "===============================================\n\n";

    cout << "Fill dp[0]=1, dp[1]=1, then:\n";
    cout << "  dp[i] += dp[k] * dp[i-1-k]  for k = 0 .. i-1\n\n";

    for (int n = 0; n <= 10; n++) {
        long long tab = catalanTab(n);
        long long formula = catalanFormula(n);
        cout << "  C_" << n << " = " << tab;
        if (tab != formula) cout << " (formula mismatch!)";
        cout << "\n";
    }

    cout << "\nC_4 = dp[0]*dp[3] + dp[1]*dp[2] + dp[2]*dp[1] + dp[3]*dp[0]\n";
    cout << "    = 1*5 + 1*2 + 2*1 + 5*1 = 14\n";
    cout << "\nApplications: valid BST counts, balanced parentheses, triangulations, etc.\n";
    return 0;
}
