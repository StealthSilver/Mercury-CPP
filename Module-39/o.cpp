// MODULE 39 — House Robber: max sum with no two adjacent houses robbed

#include <iostream>
#include <vector>
using namespace std;

int robNaive(int idx, const vector<int>& nums) {
    if (idx >= (int)nums.size()) return 0;
    return max(robNaive(idx + 1, nums), nums[idx] + robNaive(idx + 2, nums));
}

int robTab(const vector<int>& nums, bool trace) {
    int n = (int)nums.size();
    if (n == 0) return 0;
    int prev2 = 0, prev1 = 0;
    for (int i = 0; i < n; i++) {
        int cur = max(prev1, nums[i] + prev2);
        if (trace) cout << "  house " << i << " (" << nums[i] << "): best=" << cur << "\n";
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    cout << "Module 39 — House Robber (o.cpp)\n";
    cout << "================================\n\n";

    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "nums = {2,7,9,3,1}\n";
    cout << "  dp[i] = max(rob i..end, skip house i)\n";
    cout << "  naive(0): " << robNaive(0, nums) << "\n";
    cout << "  tabulation:\n";
    int ans = robTab(nums, true);
    cout << "  answer: " << ans << " (expect 12 = 2+9+1)\n";
    return 0;
}
