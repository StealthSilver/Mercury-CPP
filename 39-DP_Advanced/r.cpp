// MODULE 39 — Minimum removals to make a mountain array
// Mountain: exists peak i (0<i<n-1) with strict increase to i, strict decrease after

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int longestMountainSubseq(const vector<int>& nums) {
    int n = (int)nums.size();
    if (n < 3) return 0;
    vector<int> inc(n, 1), dec(n, 1);
    for (int i = 1; i < n; i++)
        if (nums[i] > nums[i - 1]) inc[i] = inc[i - 1] + 1;
    for (int i = n - 2; i >= 0; i--)
        if (nums[i] > nums[i + 1]) dec[i] = dec[i + 1] + 1;

    int best = 0;
    for (int i = 1; i < n - 1; i++)
        if (inc[i] >= 2 && dec[i] >= 2)
            best = max(best, inc[i] + dec[i] - 1);
    return best;
}

int minRemovalsMountain(const vector<int>& nums) {
    return (int)nums.size() - longestMountainSubseq(nums);
}

// Longest Bitonic Subsequence (related): inc ending at i + dec starting at i - 1
int longestBitonic(const vector<int>& nums) {
    int n = (int)nums.size();
    if (n == 0) return 0;
    vector<int> inc(n, 1), dec(n, 1);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (nums[j] < nums[i]) inc[i] = max(inc[i], inc[j] + 1);
    for (int i = n - 2; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            if (nums[j] < nums[i]) dec[i] = max(dec[i], dec[j] + 1);
    int best = 0;
    for (int i = 0; i < n; i++) best = max(best, inc[i] + dec[i] - 1);
    return best;
}

int main() {
    cout << "Module 39 — Mountain array / bitonic (r.cpp)\n";
    cout << "============================================\n\n";

    vector<int> nums = {1, 3, 1};
    cout << "nums = {1, 3, 1}\n";
    cout << "  longest mountain subsequence length: " << longestMountainSubseq(nums) << "\n";
    cout << "  min removals to become mountain: " << minRemovalsMountain(nums) << "\n\n";

    vector<int> nums2 = {2, 1, 1, 5, 6, 2, 1};
    cout << "nums = {2,1,1,5,6,2,1}\n";
    cout << "  min removals (mountain): " << minRemovalsMountain(nums2) << "\n";
    cout << "  longest bitonic subsequence: " << longestBitonic(nums2) << "\n";
    return 0;
}
