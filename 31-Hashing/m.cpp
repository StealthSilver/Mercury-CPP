// MODULE 31 — Count distinct elements in an array

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int countDistinct(const vector<int>& arr) {
    unordered_set<int> seen;
    for (int x : arr) {
        seen.insert(x);
    }
    return static_cast<int>(seen.size());
}

int main() {
    cout << "Module 31 — Count Distinct (m.cpp)\n";
    cout << "==================================\n\n";

    vector<int> arr1 = {4, 1, 2, 1, 5, 2};
    cout << "   arr = 4 1 2 1 5 2\n";
    cout << "   distinct count = " << countDistinct(arr1) << "\n\n";

    vector<int> arr2 = {10, 10, 10};
    cout << "   arr = 10 10 10\n";
    cout << "   distinct count = " << countDistinct(arr2) << "\n\n";

    vector<int> arr3 = {7, 8, 9};
    cout << "   arr = 7 8 9\n";
    cout << "   distinct count = " << countDistinct(arr3) << "\n\n";

    cout << "unordered_set keeps only unique keys; size() = answer.\n";
    cout << "Time: O(n) avg   Space: O(n)\n";
    return 0;
}
