// MODULE 31 — Count subarrays with sum exactly K (prefix sum + hash map)

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countSubarraysWithSumK(const vector<int>& arr, int k) {
    unordered_map<long long, int> prefixCount;
    prefixCount[0] = 1;

    long long prefix = 0;
    int count = 0;

    for (int x : arr) {
        prefix += x;

        if (prefixCount.count(prefix - k)) {
            count += prefixCount[prefix - k];
        }
        prefixCount[prefix]++;
    }
    return count;
}

int main() {
    cout << "Module 31 — Subarray Sum Equals K (p.cpp)\n";
    cout << "=========================================\n\n";

    vector<int> arr1 = {1, 1, 1};
    int k1 = 2;
    cout << "   arr = 1 1 1,  K = 2\n";
    cout << "   count = " << countSubarraysWithSumK(arr1, k1) << "\n";
    cout << "   ([1,1], [1,1] from index 1, entire array — 2 subarrays)\n\n";

    vector<int> arr2 = {1, 2, 3};
    int k2 = 3;
    cout << "   arr = 1 2 3,  K = 3\n";
    cout << "   count = " << countSubarraysWithSumK(arr2, k2) << "\n";
    cout << "   ([3], [1,2])\n\n";

    vector<int> arr3 = {1, -1, 0};
    int k3 = 0;
    cout << "   arr = 1 -1 0,  K = 0\n";
    cout << "   count = " << countSubarraysWithSumK(arr3, k3) << "\n\n";

    cout << "At each index, add how many earlier prefix sums equal (current - K).\n";
    cout << "Time: O(n) avg   Space: O(n)\n";
    return 0;
}
