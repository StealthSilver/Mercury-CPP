// MODULE 39 — Palindrome partitioning: list all ways to cut s into palindrome substrings

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPal(const string& s, int lo, int hi) {
    while (lo < hi)
        if (s[lo++] != s[hi--]) return false;
    return true;
}

void buildPalTable(const string& s, vector<vector<bool>>& pal) {
    int n = (int)s.size();
    pal.assign(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i <= 2 || pal[i + 1][j - 1]))
                pal[i][j] = true;
        }
    }
}

void backtrack(const string& s, int start, const vector<vector<bool>>& pal,
               vector<string>& path, vector<vector<string>>& out) {
    if (start == (int)s.size()) {
        out.push_back(path);
        return;
    }
    for (int end = start; end < (int)s.size(); end++) {
        if (!pal[start][end]) continue;
        path.push_back(s.substr(start, end - start + 1));
        backtrack(s, end + 1, pal, path, out);
        path.pop_back();
    }
}

vector<vector<string>> partition(const string& s) {
    vector<vector<bool>> pal;
    buildPalTable(s, pal);
    vector<string> path;
    vector<vector<string>> out;
    backtrack(s, 0, pal, path, out);
    return out;
}

int main() {
    cout << "Module 39 — Palindrome Partitioning (t.cpp)\n";
    cout << "==========================================\n\n";

    string s = "aab";
    auto parts = partition(s);
    cout << "s = \"" << s << "\"\n";
    cout << "  Step 1: precompute palindrome table pal[i][j]\n";
    cout << "  Step 2: backtrack — try every palindrome prefix, recurse on rest\n\n";
    cout << "  " << parts.size() << " partitions:\n";
    for (auto& p : parts) {
        cout << "    [";
        for (int i = 0; i < (int)p.size(); i++) {
            if (i) cout << " | ";
            cout << "\"" << p[i] << "\"";
        }
        cout << "]\n";
    }
    return 0;
}
