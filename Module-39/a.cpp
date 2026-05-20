// MODULE 39 — Wildcard pattern matching (? and *)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool matchNaive(int ti, int pi, const string& text, const string& pattern) {
    int n = (int)text.size(), m = (int)pattern.size();
    if (pi == m) return ti == n;
    if (pattern[pi] == '*')
        return matchNaive(ti, pi + 1, text, pattern) ||
               (ti < n && matchNaive(ti + 1, pi, text, pattern));
    if (pattern[pi] == '?')
        return ti < n && matchNaive(ti + 1, pi + 1, text, pattern);
    return ti < n && text[ti] == pattern[pi] && matchNaive(ti + 1, pi + 1, text, pattern);
}

bool matchMemo(int ti, int pi, const string& text, const string& pattern,
               vector<vector<int>>& memo) {
    int n = (int)text.size(), m = (int)pattern.size();
    if (pi == m) return ti == n;
    if (memo[ti][pi] != -1) return memo[ti][pi] == 1;
    bool ok = false;
    if (pattern[pi] == '*')
        ok = matchMemo(ti, pi + 1, text, pattern, memo) ||
             (ti < n && matchMemo(ti + 1, pi, text, pattern, memo));
    else if (pattern[pi] == '?')
        ok = ti < n && matchMemo(ti + 1, pi + 1, text, pattern, memo);
    else
        ok = ti < n && text[ti] == pattern[pi] &&
             matchMemo(ti + 1, pi + 1, text, pattern, memo);
    memo[ti][pi] = ok ? 1 : 0;
    return ok;
}

bool wildcardMatch(const string& text, const string& pattern) {
    int n = (int)text.size(), m = (int)pattern.size();
    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
    return matchMemo(0, 0, text, pattern, memo);
}

// Bottom-up: dp[ti][pi] = can match text[ti..] with pattern[pi..]
bool matchTab(const string& text, const string& pattern) {
    int n = (int)text.size(), m = (int)pattern.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[n][m] = true;
    for (int pi = m - 1; pi >= 0; pi--) {
        if (pattern[pi] == '*')
            dp[n][pi] = dp[n][pi + 1];
    }
    for (int ti = n - 1; ti >= 0; ti--) {
        for (int pi = m - 1; pi >= 0; pi--) {
            if (pattern[pi] == '*')
                dp[ti][pi] = dp[ti][pi + 1] || dp[ti + 1][pi];
            else if (pattern[pi] == '?')
                dp[ti][pi] = dp[ti + 1][pi + 1];
            else
                dp[ti][pi] = (text[ti] == pattern[pi]) && dp[ti + 1][pi + 1];
        }
    }
    return dp[0][0];
}

void runCase(const string& text, const string& pattern, bool expect) {
    bool m1 = wildcardMatch(text, pattern);
    bool m2 = matchTab(text, pattern);
    cout << "  text=\"" << text << "\"\n";
    cout << "  pattern=\"" << pattern << "\"\n";
    cout << "  match (memo): " << (m1 ? "true" : "false")
         << ", tab: " << (m2 ? "true" : "false")
         << " (expect " << (expect ? "true" : "false") << ")\n\n";
}

int main() {
    cout << "Module 39 — Wildcard Matching (a.cpp)\n";
    cout << "====================================\n\n";
    cout << "? = any one char, * = any sequence (including empty)\n\n";

    runCase("baaabab", "**ba****ab*", true);
    runCase("baaabab", "a*ab", false);

    cout << "Recurrence on (text_i, pattern_j):\n";
    cout << "  '*' -> skip star (empty) OR consume one text char and keep star\n";
    cout << "  '?' -> need one text char, advance both\n";
    cout << "Time O(n*m) with memo/tab.\n";
    return 0;
}
