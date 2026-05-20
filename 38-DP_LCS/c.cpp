// MODULE 38 — Longest Common Subsequence (LCS) — naive recursion

#include <iostream>
#include <string>
using namespace std;

// LCS length of s1[i..] and s2[j..]
int lcsRecursive(const string& s1, const string& s2, int i, int j) {
    if (i == (int)s1.size() || j == (int)s2.size()) return 0;
    if (s1[i] == s2[j]) return 1 + lcsRecursive(s1, s2, i + 1, j + 1);
    return max(lcsRecursive(s1, s2, i + 1, j),
              lcsRecursive(s1, s2, i, j + 1));
}

string buildLCS(const string& s1, const string& s2, int i, int j) {
    if (i == (int)s1.size() || j == (int)s2.size()) return "";
    if (s1[i] == s2[j]) return s1[i] + buildLCS(s1, s2, i + 1, j + 1);
    int skip1 = lcsRecursive(s1, s2, i + 1, j);
    int skip2 = lcsRecursive(s1, s2, i, j + 1);
    if (skip1 >= skip2) return buildLCS(s1, s2, i + 1, j);
    return buildLCS(s1, s2, i, j + 1);
}

int main() {
    cout << "Module 38 — LCS naive recursion (c.cpp)\n";
    cout << "=========================================\n\n";

    string s1 = "abcdge";
    string s2 = "abedg";

    int len = lcsRecursive(s1, s2, 0, 0);
    cout << "s1 = \"" << s1 << "\"\n";
    cout << "s2 = \"" << s2 << "\"\n\n";
    cout << "LCS length (naive): " << len << " (expect 4)\n";
    cout << "One LCS string:     \"" << buildLCS(s1, s2, 0, 0) << "\" (expect abdg)\n\n";

    cout << "Branches: match -> both advance; else skip char in s1 OR s2.\n";
    cout << "Time O(2^(n+m)) — many overlapping (i,j) states.\n";
    return 0;
}
