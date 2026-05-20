// MODULE 27 — Minimize sum of absolute differences (sort A and B, zip)

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int minAbsDiffSum(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int sum = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        sum += abs(A[i] - B[i]);
    }
    return sum;
}

int main() {
    vector<int> A = {1, 4, 7, 8};
    vector<int> B = {2, 3, 6, 9};

    int ans = minAbsDiffSum(A, B);

    cout << "Min absolute difference pairing\n\n";
    cout << "A: ";
    for (int x : A) {
        cout << x << " ";
    }
    cout << "\nB: ";
    for (int x : B) {
        cout << x << " ";
    }
    cout << "\n\nAfter sorting, pair A[i] with B[i]:\n";
    vector<int> a = A, b = B;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (size_t i = 0; i < a.size(); ++i) {
        cout << "  (" << a[i] << ", " << b[i] << ") -> |diff| = " << abs(a[i] - b[i]) << "\n";
    }
    cout << "\nmin sum: " << ans << "  (expected 4)\n";

    return 0;
}
