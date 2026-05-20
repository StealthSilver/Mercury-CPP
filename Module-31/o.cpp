// MODULE 31 — Longest subarray with sum 0 (prefix sum + hash map)

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestZeroSumSubarray(const vector<int>& arr) {
    unordered_map<int, int> firstIndex;
    firstIndex[0] = -1;

    int prefix = 0;
    int maxLen = 0;

    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        prefix += arr[i];

        if (firstIndex.count(prefix)) {
            maxLen = max(maxLen, i - firstIndex[prefix]);
        } else {
            firstIndex[prefix] = i;
        }
    }
    return maxLen;
}

int main() {
    cout << "Module 31 — Longest Subarray with Sum 0 (o.cpp)\n";
    cout << "================================================\n\n";

    vector<int> arr1 = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << "   arr = 15 -2 2 -8 1 7 10 23\n";
    cout << "   longest zero-sum length = " << longestZeroSumSubarray(arr1) << "\n";
    cout << "   (subarray: -2, 2, -8, 1, 7)\n\n";

    vector<int> arr2 = {1, -1, 3, 4, -1};
    cout << "   arr = 1 -1 3 4 -1\n";
    cout << "   longest zero-sum length = " << longestZeroSumSubarray(arr2) << "\n\n";

    vector<int> arr3 = {5, 1, 2};
    cout << "   arr = 5 1 2\n";
    cout << "   longest zero-sum length = " << longestZeroSumSubarray(arr3) << "\n\n";

    cout << "Key: equal prefix sums at i and j  =>  subarray (i+1..j) sums to 0.\n";
    cout << "Store first index of each prefix sum in unordered_map.\n";
    cout << "Time: O(n) avg   Space: O(n)\n";
    return 0;
}
