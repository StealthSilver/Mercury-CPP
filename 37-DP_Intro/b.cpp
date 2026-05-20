// MODULE 37 — Type 1: Memoization (top-down DP) — Fibonacci with cache trace

#include <iostream>
#include <vector>
using namespace std;

struct MemoFib {
    vector<long long> memo;
    int hits = 0;   // returned from cache
    int misses = 0; // computed fresh

    explicit MemoFib(int n) : memo(n + 1, -1) {}

    long long solve(int n) {
        if (n <= 1) return n;
        if (memo[n] != -1) {
            hits++;
            return memo[n];
        }
        misses++;
        memo[n] = solve(n - 1) + solve(n - 2);
        return memo[n];
    }
};

int main() {
    cout << "Module 37 — Memoization / top-down DP (b.cpp)\n";
    cout << "=============================================\n\n";

    int n = 8;
    MemoFib mf(n);
    long long ans = mf.solve(n);

    cout << "F(" << n << ") = " << ans << "\n\n";
    cout << "Memo table after solve (index -> value, -1 = never needed):\n";
    for (int i = 0; i <= n; i++) {
        cout << "  memo[" << i << "] = ";
        if (mf.memo[i] == -1)
            cout << "(unused)\n";
        else
            cout << mf.memo[i] << "\n";
    }

    cout << "\nCache stats:\n";
    cout << "  misses (first compute): " << mf.misses << "  (= distinct subproblems)\n";
    cout << "  hits   (reuse cache):   " << mf.hits << "\n";
    cout << "  Total recursive calls with memo: " << (mf.misses + mf.hits)
         << "  vs naive ~ exponential for same n\n\n";

    cout << "Pattern: if (memo[state] known) return it; else compute, store, return.\n";
    return 0;
}
