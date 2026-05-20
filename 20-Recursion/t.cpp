#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Even index → digit in {0,2,4,6,8} (5 choices)
// Odd index  → digit in {2,3,5,7} (4 choices)
long long countGoodStrings(int n, int pos) {
    if (pos == n)
        return 1;

    if (pos % 2 == 0)
        return (5LL * countGoodStrings(n, pos + 1)) % MOD;
    return (4LL * countGoodStrings(n, pos + 1)) % MOD;
}

int main() {
    int n = 4;
    cout << countGoodStrings(n, 0) << endl; // n=4 → 5^2 * 4^2 = 400
    return 0;
}
