// MODULE 39 — Matrix Chain Multiplication: tabulation + optional parenthesis trace

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void printParen(int i, int j, const vector<vector<int>>& split) {
    if (i >= j) {
        cout << "M" << i;
        return;
    }
    int k = split[i][j];
    cout << "(";
    printParen(i, k, split);
    cout << " x ";
    printParen(k + 1, j, split);
    cout << ")";
}

int main() {
    cout << "Module 39 — MCM: tabulation (i.cpp)\n";
    cout << "===================================\n\n";

    vector<int> dims = {1, 2, 3, 4, 3};
    int n = (int)dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> split(n, vector<int>(n, -1));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    cout << "dims = {1, 2, 3, 4, 3}\n";
    cout << "  Fill by chain length len = 2 .. n\n\n";
    cout << "  Minimum cost (tab): " << dp[0][n - 1] << " (expect 30)\n";
    cout << "  One optimal parenthesization: ";
    printParen(0, n - 1, split);
    cout << "\n\n";

    cout << "dp table (same fill as mcmTab):\n";
    for (int i = 0; i < n; i++) {
        cout << "  i" << i << ": ";
        for (int j = 0; j < n; j++) cout << dp[i][j] << (j + 1 < n ? " " : "");
        cout << "\n";
    }
    return 0;
}
