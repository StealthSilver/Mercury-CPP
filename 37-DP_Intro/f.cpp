// MODULE 37 — Variations: k steps at a time, and 1/2/3 steps (Tribonacci-style)

#include <iostream>
#include <vector>
using namespace std;

// Ways to reach n using steps in {1, 2, ..., k}
long long climbKSteps(int n, int k) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;  // one way to be at "ground" before climbing
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= k && i - s >= 0; s++)
            dp[i] += dp[i - s];
    }
    return dp[n];
}

// Ways with steps 1, 2, or 3 only
long long climb123(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    if (n >= 1) dp[1] = 1;
    if (n >= 2) dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    return dp[n];
}

// Forbidden stairs: cannot step on indices in bad set (0-indexed steps 1..n)
long long climbForbidden(int n, const vector<int>& bad) {
    vector<long long> dp(n + 1, 0);
    vector<bool> isBad(n + 1, false);
    for (int b : bad) if (b >= 0 && b <= n) isBad[b] = true;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (isBad[i]) {
            dp[i] = 0;
            continue;
        }
        if (i >= 1) dp[i] += dp[i - 1];
        if (i >= 2) dp[i] += dp[i - 2];
    }
    return dp[n];
}

int main() {
    cout << "Module 37 — Climbing Stairs variations (f.cpp)\n";
    cout << "=============================================\n\n";

    int n = 5;
    cout << "n=" << n << ", steps 1..3 at a time: " << climbKSteps(n, 3) << " ways\n";
    cout << "n=" << n << ", steps 1 or 2 only:     " << climbKSteps(n, 2) << " ways (Climbing Stairs)\n";
    cout << "n=" << n << ", explicit 1/2/3:        " << climb123(n) << " ways\n\n";

    cout << "Forbidden stair 3 (0-indexed step index 3):\n";
    cout << "  ways = " << climbForbidden(5, {3}) << "  (paths skipping landing on 3)\n";
    return 0;
}
