// MODULE 39 — Tribonacci: T0=0, T1=1, T2=1, T(n)=T(n-1)+T(n-2)+T(n-3)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long tribNaive(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    return tribNaive(n - 1) + tribNaive(n - 2) + tribNaive(n - 3);
}

long long tribMemo(int n, vector<long long>& memo) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    if (memo[n] != -1) return memo[n];
    return memo[n] = tribMemo(n - 1, memo) + tribMemo(n - 2, memo) + tribMemo(n - 3, memo);
}

long long tribTab(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    long long t0 = 0, t1 = 1, t2 = 1;
    for (int i = 3; i <= n; i++) {
        long long t3 = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = t3;
    }
    return t2;
}

int main() {
    cout << "Module 39 — Tribonacci (k.cpp)\n";
    cout << "==============================\n\n";
    cout << "Recurrence: T(n) = T(n-1) + T(n-2) + T(n-3)\n\n";

    for (int n : {0, 1, 2, 3, 4, 5, 10, 15}) {
        vector<long long> memo(n + 1, -1);
        cout << "  T(" << n << "): naive=" << (n <= 8 ? to_string(tribNaive(n)) : "(skip)")
             << ", memo=" << tribMemo(n, memo) << ", tab=" << tribTab(n) << "\n";
    }
    return 0;
}
