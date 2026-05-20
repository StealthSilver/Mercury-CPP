// MODULE 39 — Equal subset sum partition (can split into two equal-sum subsets?)

#include <iostream>
#include <vector>
using namespace std;

bool canPartitionTab(const vector<int>& nums) {
    int total = 0;
    for (int x : nums) total += x;
    if (total % 2 != 0) return false;
    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int x : nums)
        for (int s = target; s >= x; s--)
            dp[s] = dp[s] || dp[s - x];
    return dp[target];
}

bool canPartitionRecursive(int idx, int rem, const vector<int>& nums) {
    if (rem == 0) return true;
    if (idx == (int)nums.size() || rem < 0) return false;
    return canPartitionRecursive(idx + 1, rem, nums) ||
           canPartitionRecursive(idx + 1, rem - nums[idx], nums);
}

int main() {
    cout << "Module 39 — Equal Subset Sum Partition (q.cpp)\n";
    cout << "==============================================\n\n";

    vector<vector<int>> tests = {{1, 5, 11, 5}, {1, 2, 3, 5}, {2, 2, 1, 1}};
    for (auto& nums : tests) {
        int total = 0;
        for (int x : nums) total += x;
        cout << "nums = {";
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i) cout << ", ";
            cout << nums[i];
        }
        cout << "}  sum=" << total << "\n";
        cout << "  can partition equally? " << (canPartitionTab(nums) ? "true" : "false");
        if (total % 2 == 0)
            cout << "  (target subset sum " << total / 2 << ")";
        cout << "\n\n";
    }
    return 0;
}
