// MODULE 38 — Longest Common Substring (contiguous only)

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lcSubstringRecursive(const string& s1, const string& s2, int i, int j) {
    if (i == 0 || j == 0) return 0;
    if (s1[i - 1] == s2[j - 1])
        return 1 + lcSubstringRecursive(s1, s2, i - 1, j - 1);
    return 0;
}

int lcSubstringMemo(const string& s1, const string& s2, int i, int j,
                    vector<vector<int>>& memo) {
    if (i == 0 || j == 0) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    if (s1[i - 1] == s2[j - 1])
        return memo[i][j] = 1 + lcSubstringMemo(s1, s2, i - 1, j - 1, memo);
    return memo[i][j] = 0;
}

// Returns max length and fills end indices for reconstruction
int lcSubstringTab(const string& s1, const string& s2, int& endI, int& endJ, bool trace) {
    int n = (int)s1.size(), m = (int)s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int best = 0;
    endI = endJ = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > best) {
                    best = dp[i][j];
                    endI = i;
                    endJ = j;
                }
            }
        }
    }
    if (trace) {
        cout << "On mismatch dp[i][j]=0 (unlike LCS). Track global max.\n";
        cout << "Max length " << best << " ending at i=" << endI << ", j=" << endJ << "\n";
    }
    return best;
}

string extractSubstring(const string& s1, int endI, int len) {
    return s1.substr(endI - len, len);
}

int main() {
    cout << "Module 38 — Longest Common Substring (f.cpp)\n";
    cout << "==========================================\n\n";

    string s1 = "abcde", s2 = "abgce";

    int n = (int)s1.size(), m = (int)s2.size();
    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
    int maxLen = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            maxLen = max(maxLen, lcSubstringMemo(s1, s2, i, j, memo));

    int endI, endJ;
    int tabLen = lcSubstringTab(s1, s2, endI, endJ, true);

    cout << "s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"\n\n";
    cout << "Max contiguous common length (memo scan): " << maxLen << "\n";
    cout << "Tabulation max length: " << tabLen << " (expect 2)\n";
    cout << "Substring: \"" << extractSubstring(s1, endI, tabLen) << "\" (expect ab)\n\n";

    cout << "LCS allows gaps; substring requires contiguous match -> dp=0 on mismatch.\n";
    return 0;
}
