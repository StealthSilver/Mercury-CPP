// MODULE 39 — Matrix Chain Multiplication (MCM): naive recursion

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// dims[i] x dims[i+1] for matrix i; multiply chain i..j (inclusive)
int mcmRecursive(int i, int j, const vector<int>& dims) {
    if (i >= j) return 0;
    int best = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = mcmRecursive(i, k, dims) + mcmRecursive(k + 1, j, dims) +
                   dims[i] * dims[k + 1] * dims[j + 1];
        best = min(best, cost);
    }
    return best;
}

void printMatrices(const vector<int>& dims) {
    int n = (int)dims.size() - 1;
    for (int i = 0; i < n; i++)
        cout << "  M" << i << ": " << dims[i] << " x " << dims[i + 1] << "\n";
}

int main() {
    cout << "Module 39 — Matrix Chain Multiplication: recursion (g.cpp)\n";
    cout << "========================================================\n\n";

    vector<int> dims = {1, 2, 3, 4, 3};
    cout << "dims = {1, 2, 3, 4, 3}  ->  4 matrices:\n";
    printMatrices(dims);
    cout << "\nRecurrence: split at k, multiply left chain * right chain.\n";
    cout << "  cost(i,j) = min_k { cost(i,k) + cost(k+1,j) + dims[i]*dims[k+1]*dims[j+1] }\n\n";

    int ans = mcmRecursive(0, (int)dims.size() - 2, dims);
    cout << "  Minimum scalar multiplications (naive): " << ans << " (expect 30)\n";
    cout << "  Time: exponential — many subproblems recomputed.\n";
    return 0;
}
