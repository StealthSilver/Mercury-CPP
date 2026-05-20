// MODULE 39 — Count structurally unique BSTs with n nodes (= Catalan number C_n)

#include <iostream>
#include <vector>
using namespace std;

long long catalan(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    if (n >= 1) dp[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int k = 0; k < i; k++)
            dp[i] += dp[k] * dp[i - 1 - k];
    return dp[n];
}

void describeBSTSplit(int n) {
    cout << "BST with " << n << " nodes (keys 1.." << n << " fixed, shape only):\n";
    cout << "  Pick root k in 1.." << n << ": left has (k-1) nodes, right has (n-k) nodes.\n";
    cout << "  Count = sum_k C(k-1)*C(n-k) = C_" << n << "\n\n";
}

int main() {
    cout << "Module 39 — Count unique BST structures (e.cpp)\n";
    cout << "============================================\n\n";

    describeBSTSplit(3);

    for (int n : {2, 3, 4, 5}) {
        long long cnt = catalan(n);
        cout << "  n = " << n << " -> " << cnt << " structurally unique BSTs";
        if (n == 2) cout << " (expect 2)";
        if (n == 3) cout << " (expect 5)";
        cout << "\n";
    }

    cout << "\nSame C_n as parentheses / mountains — see [d.cpp](d.cpp) recurrence.\n";
    return 0;
}
