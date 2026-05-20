// MODULE 39 — Catalan numbers — naive recursion

#include <iostream>
using namespace std;

// C_n = sum_{k=0}^{n-1} C_k * C_{n-1-k},  C_0 = 1
long long catalanRecursive(int n) {
    if (n <= 1) return 1;
    long long sum = 0;
    for (int k = 0; k < n; k++)
        sum += catalanRecursive(k) * catalanRecursive(n - 1 - k);
    return sum;
}

int main() {
    cout << "Module 39 — Catalan numbers: recursion (b.cpp)\n";
    cout << "=============================================\n\n";

    cout << "C_n = sum_{k=0}^{n-1} C_k * C_{n-1-k},  C_0 = C_1 = 1\n\n";

    for (int n = 0; n <= 6; n++)
        cout << "  C_" << n << " = " << catalanRecursive(n) << "\n";

    cout << "\nExample from notes:\n";
    cout << "  C_2 = C_0*C_1 + C_1*C_0 = 1*1 + 1*1 = 2\n";
    cout << "  C_3 = C_0*C_2 + C_1*C_1 + C_2*C_0 = 1*2 + 1*1 + 2*1 = 5\n";
    cout << "  C_4 = 1*5 + 1*2 + 2*1 + 5*1 = 14\n\n";

    cout << "Many overlapping subproblems -> exponential without memo.\n";
    return 0;
}
