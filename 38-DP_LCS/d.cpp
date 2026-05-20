// MODULE 38 — LCS — top-down memoization

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lcsMemo(const string& s1, const string& s2, int i, int j, vector<vector<int>>& memo) {
    if (i == (int)s1.size() || j == (int)s2.size()) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    if (s1[i] == s2[j]) return memo[i][j] = 1 + lcsMemo(s1, s2, i + 1, j + 1, memo);
    return memo[i][j] = max(lcsMemo(s1, s2, i + 1, j, memo),
                            lcsMemo(s1, s2, i, j + 1, memo));
}

int lcsLengthMemo(const string& s1, const string& s2) {
    vector<vector<int>> memo(s1.size(), vector<int>(s2.size(), -1));
    return lcsMemo(s1, s2, 0, 0, memo);
}

int main() {
    cout << "Module 38 — LCS memoization (d.cpp)\n";
    cout << "===================================\n\n";

    string s1 = "abcdge", s2 = "abedg";
    int len = lcsLengthMemo(s1, s2);

    cout << "s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"\n";
    cout << "LCS length (memo): " << len << " (expect 4)\n\n";

    cout << "State (i,j) = LCS length of suffixes s1[i..] and s2[j..].\n";
    cout << "Each (i,j) computed once -> O(n*m) time, O(n*m) space.\n";
    return 0;
}
