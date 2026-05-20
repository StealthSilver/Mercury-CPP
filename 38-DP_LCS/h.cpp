// MODULE 38 — Edit Distance (Levenshtein): min ops to convert s1 -> s2
// Operations: insert, delete, replace (unit cost 1 each)

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int editDistRecursive(const string& s1, const string& s2, int i, int j) {
    if (i == 0) return j;
    if (j == 0) return i;
    if (s1[i - 1] == s2[j - 1])
        return editDistRecursive(s1, s2, i - 1, j - 1);
    return 1 + min({editDistRecursive(s1, s2, i - 1, j),      // delete s1[i-1]
                    editDistRecursive(s1, s2, i, j - 1),      // insert s2[j-1]
                    editDistRecursive(s1, s2, i - 1, j - 1)}); // replace
}

int editDistMemo(const string& s1, const string& s2, int i, int j,
                 vector<vector<int>>& memo) {
    if (i == 0) return j;
    if (j == 0) return i;
    if (memo[i][j] != -1) return memo[i][j];
    if (s1[i - 1] == s2[j - 1])
        return memo[i][j] = editDistMemo(s1, s2, i - 1, j - 1, memo);
    return memo[i][j] = 1 + min({editDistMemo(s1, s2, i - 1, j, memo),
                                 editDistMemo(s1, s2, i, j - 1, memo),
                                 editDistMemo(s1, s2, i - 1, j - 1, memo)});
}

int editDistTab(const string& s1, const string& s2, bool trace) {
    int n = (int)s1.size(), m = (int)s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }
    if (trace) {
        cout << "dp[i][j] = min edits for s1[0..i-1] -> s2[0..j-1]\n";
        cout << "      ";
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

void demo(const string& s1, const string& s2) {
    int n = (int)s1.size(), m = (int)s2.size();
    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
    cout << "  \"" << s1 << "\" -> \"" << s2 << "\": ";
    cout << "memo=" << editDistMemo(s1, s2, n, m, memo);
    cout << ", tab=" << editDistTab(s1, s2, false) << "\n";
}

int main() {
    cout << "Module 38 — Edit Distance (h.cpp)\n";
    cout << "=================================\n\n";

    cout << "Example 1:\n";
    demo("abc", "ac");
    cout << "  (delete 'b') expect 1\n\n";

    cout << "Example 2:\n";
    demo("horse", "ros");
    cout << "  expect 3 (replace h->r, delete r, delete e)\n\n";

    cout << "Full table for horse -> ros:\n";
    cout << "  distance = " << editDistTab("horse", "ros", true) << "\n";
    return 0;
}
