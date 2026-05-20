// MODULE 39 — Longest Palindromic Subsequence (LPS) — interval DP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lpsInterval(const string& s) {
    int n = (int)s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j])
                dp[i][j] = 2 + (len > 2 ? dp[i + 1][j - 1] : 0);
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}

int main() {
    cout << "Module 39 — Longest Palindromic Subsequence (p.cpp)\n";
    cout << "==================================================\n\n";

    string s = "bbbab";
    cout << "s = \"" << s << "\"\n";
    cout << "  dp[i][j] = LPS length in s[i..j]\n";
    cout << "  if s[i]==s[j]: dp[i][j] = 2 + dp[i+1][j-1]\n";
    cout << "  else: max(dp[i+1][j], dp[i][j-1])\n\n";
    cout << "  LPS length: " << lpsInterval(s) << " (expect 4, e.g. \"bbbb\")\n";
    return 0;
}
