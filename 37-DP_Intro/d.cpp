// MODULE 37 — LeetCode 70: Climbing Stairs
// Count ways to reach the nth stair climbing 1 or 2 steps at a time.

#include <iostream>
#include <vector>
using namespace std;

// ways(n) = distinct sequences of 1- and 2-stair moves summing to n
// ways(1)=1, ways(2)=2, ways(n)=ways(n-1)+ways(n-2) for n>=3

long long climbNaive(int n) {
    if (n <= 2) return n;
    return climbNaive(n - 1) + climbNaive(n - 2);
}

long long climbMemo(int n, vector<long long>& memo) {
    if (n <= 2) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = climbMemo(n - 1, memo) + climbMemo(n - 2, memo);
}

long long climbMemo(int n) {
    vector<long long> memo(n + 1, -1);
    return climbMemo(n, memo);
}

long long climbTab(int n) {
    if (n <= 2) return n;
    long long w1 = 1, w2 = 2;
    for (int i = 3; i <= n; i++) {
        long long w3 = w1 + w2;
        w1 = w2;
        w2 = w3;
    }
    return w2;
}

// Print call tree for ways(k) (same overlap pattern as Fibonacci)
void printCallTree(int k, int depth, const string& edge) {
    if (depth > 0) cout << edge << "ways(" << k << ")\n";
    else cout << "ways(" << k << ")\n";
    if (k <= 2) return;
    printCallTree(k - 1, depth + 1, string(depth * 2, ' ') + "|-- ");
    printCallTree(k - 2, depth + 1, string(depth * 2, ' ') + "\\-- ");
}

int main() {
    cout << "Module 37 — Climbing Stairs (d.cpp)\n";
    cout << "===================================\n\n";

    int n = 5;
    cout << "Ways to reach stair " << n << " (steps of size 1 or 2):\n";
    cout << "  Naive recursion: " << climbNaive(n) << "\n";
    cout << "  Memoization:     " << climbMemo(n) << "\n";
    cout << "  Tabulation:      " << climbTab(n) << "\n\n";

    cout << "n=3 by hand: (1,1,1), (1,2), (2,1) => 3 ways.\n";
    cout << "n=5 => " << climbTab(5) << " ways.\n\n";

    cout << "Recursion tree (function calls ways(k)):\n";
    printCallTree(n, 0, "");

    cout << "\nways(n) = ways(n-1) + ways(n-2)  |  Time O(n) DP, Space O(1) rolling\n";
    return 0;
}
