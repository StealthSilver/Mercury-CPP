// MODULE 39 — Mountain ranges: n up-strokes & n down-strokes, never more downs than ups
// (Dyck paths) — count = Catalan C_n

#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long catalanTab(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    if (n >= 1) dp[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int k = 0; k < i; k++)
            dp[i] += dp[k] * dp[i - 1 - k];
    return dp[n];
}

// DFS count valid paths; ups used, downs used; need ups >= downs always
long long countMountainsDFS(int ups, int downs, int pairs) {
    if (ups == pairs && downs == pairs) return 1;
    if (ups > pairs || downs > pairs || downs > ups) return 0;
    long long ways = 0;
    if (ups < pairs) ways += countMountainsDFS(ups + 1, downs, pairs);  // up stroke
    if (downs < ups) ways += countMountainsDFS(ups, downs + 1, pairs);  // down (only if safe)
    return ways;
}

// Memo on (ups, downs)
long long countMountainsMemo(int ups, int downs, int pairs, vector<vector<long long>>& memo) {
    if (ups == pairs && downs == pairs) return 1;
    if (ups > pairs || downs > pairs || downs > ups) return 0;
    if (memo[ups][downs] != -1) return memo[ups][downs];
    long long ways = 0;
    if (ups < pairs) ways += countMountainsMemo(ups + 1, downs, pairs, memo);
    if (downs < ups) ways += countMountainsMemo(ups, downs + 1, pairs, memo);
    return memo[ups][downs] = ways;
}

void listMountains(int ups, int downs, int pairs, string& path, vector<string>& all) {
    if (ups == pairs && downs == pairs) {
        all.push_back(path);
        return;
    }
    if (ups > pairs || downs > pairs || downs > ups) return;
    if (ups < pairs) {
        path.push_back('U');
        listMountains(ups + 1, downs, pairs, path, all);
        path.pop_back();
    }
    if (downs < ups) {
        path.push_back('D');
        listMountains(ups, downs + 1, pairs, path, all);
        path.pop_back();
    }
}

int main() {
    cout << "Module 39 — Mountain ranges (f.cpp)\n";
    cout << "=================================\n\n";

    int pairs = 3;
    vector<vector<long long>> memo(pairs + 1, vector<long long>(pairs + 1, -1));

    cout << "n pairs of up (U) and down (D) strokes.\n";
    cout << "Rule: at every prefix, #U >= #D (never go below ground).\n\n";

    long long dfs = countMountainsDFS(0, 0, pairs);
    long long mem = countMountainsMemo(0, 0, pairs, memo);
    long long cat = catalanTab(pairs);

    cout << "  pairs = " << pairs << ":\n";
    cout << "    DFS count:      " << dfs << "\n";
    cout << "    Memo count:     " << mem << "\n";
    cout << "    Catalan C_" << pairs << ": " << cat << " (expect 5)\n\n";

    vector<string> paths;
    string cur;
    listMountains(0, 0, pairs, cur, paths);
    cout << "  All " << paths.size() << " mountain paths (U=up, D=down):\n";
    for (const string& p : paths) cout << "    " << p << "\n";

    cout << "\nSame as balanced parentheses of " << pairs << " pairs: () ()(), (()) (), etc.\n";
    return 0;
}
