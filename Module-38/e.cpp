// MODULE 38 — LCS — bottom-up tabulation (2D table + optional reconstruction)

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lcsTable(const string& s1, const string& s2, vector<vector<int>>& dp, bool trace) {
    int n = (int)s1.size(), m = (int)s2.size();
    dp.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    if (trace) {
        cout << "dp[i][j] = LCS length of s1[0..i-1] and s2[0..j-1]:\n      ";
        for (int j = 0; j <= m; j++) cout << "j" << j << "\t";
        cout << "\n";
        for (int i = 0; i <= n; i++) {
            cout << "i" << i << " ";
            for (int j = 0; j <= m; j++) cout << dp[i][j] << "\t";
            cout << "\n";
        }
    }
    return dp[n][m];
}

string reconstructLCS(const string& s1, const string& s2, const vector<vector<int>>& dp) {
    string out;
    int i = (int)s1.size(), j = (int)s2.size();
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            out.push_back(s1[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(out.begin(), out.end());
    return out;
}

int main() {
    cout << "Module 38 — LCS tabulation (e.cpp)\n";
    cout << "==================================\n\n";

    string s1 = "abcdge", s2 = "abedg";
    vector<vector<int>> dp;
    int len = lcsTable(s1, s2, dp, true);

    cout << "\nLCS length: " << len << " (expect 4)\n";
    cout << "LCS string: \"" << reconstructLCS(s1, s2, dp) << "\" (expect abdg)\n\n";

    cout << "Fill i,j increasing; match takes diagonal, else max(up, left).\n";
    cout << "Time O(n*m), Space O(n*m) or O(min(n,m)) with rolling row.\n";
    return 0;
}
