// MODULE 27 — Problem 5: Split array largest sum (binary search + greedy split)

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

bool canSplit(const vector<int>& nums, int k, long long maxSum) {
    int parts = 1;
    long long cur = 0;
    for (int x : nums) {
        if (x > maxSum) {
            return false;
        }
        if (cur + x > maxSum) {
            parts++;
            cur = x;
        } else {
            cur += x;
        }
    }
    return parts <= k;
}

int splitArray(vector<int>& nums, int k) {
    long long lo = *max_element(nums.begin(), nums.end());
    long long hi = accumulate(nums.begin(), nums.end(), 0LL);

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (canSplit(nums, k, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return static_cast<int>(lo);
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    int ans = splitArray(nums, k);

    cout << "Split array largest sum\n\n";
    cout << "nums: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\nk = " << k << "\n";
    cout << "minimized largest sum: " << ans << "  (expected 18)\n";
    cout << "(split [7,2,5]=14 and [10,8]=18 -> max 18; optimal may be 14 with k=2: [7,2,5] and [10,8] -> 14)\n";

    // Correct answer for [7,2,5,10,8], k=2 is 18? Let me verify
    // split [7,2,5,10] [8] -> 18
    // split [7,2,5] [10,8] -> max(14,18)=18
    // split [7,2] [5,10,8] -> max(9,23)=23
    // Actually optimal is 18 for k=2? 
    // LC example: [7,2,5,10,8] k=2 answer 18
    // Wait LC 410 says answer 18 for that example

    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << "\nnums [1..5], k=2 -> " << splitArray(nums2, 2) << "  (expected 9)\n";

    return 0;
}
