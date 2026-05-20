// MODULE 39 — Catalan numbers — top-down memoization

#include <iostream>
#include <vector>
using namespace std;

long long catalanMemo(int n, vector<long long>& memo) {
    if (n <= 1) return 1;
    if (memo[n] != -1) return memo[n];
    long long sum = 0;
    for (int k = 0; k < n; k++)
        sum += catalanMemo(k, memo) * catalanMemo(n - 1 - k, memo);
    return memo[n] = sum;
}

int main() {
    cout << "Module 39 — Catalan numbers: memoization (c.cpp)\n";
    cout << "================================================\n\n";

    int maxN = 20;
    vector<long long> memo(maxN + 1, -1);

    cout << "C_0 .. C_" << maxN << " (each n computed once):\n";
    for (int n = 0; n <= maxN; n++)
        cout << "  C_" << n << " = " << catalanMemo(n, memo) << "\n";

    cout << "\nTime O(n^2) states, each sum O(n) -> O(n^3) naive memo loop;\n";
    cout << "can optimize to O(n^2) with careful order (same as tabulation).\n";
    return 0;
}
