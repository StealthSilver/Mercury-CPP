// MODULE 37 — Target Sum Subset (subset sum / knapsack decision)
// Is there a subset of nums that sums exactly to target?

#include <iostream>
#include <vector>
using namespace std;

bool subsetSumNaive(int idx, int rem, const vector<int>& nums) {
    if (rem == 0) return true;
    if (idx == (int)nums.size() || rem < 0) return false;
    return subsetSumNaive(idx + 1, rem, nums) ||
           subsetSumNaive(idx + 1, rem - nums[idx], nums);
}

bool subsetSumMemo(int idx, int rem, const vector<int>& nums, vector<vector<int>>& memo) {
    if (rem == 0) return true;
    if (idx == (int)nums.size() || rem < 0) return false;
    if (memo[idx][rem] != -1) return memo[idx][rem] == 1;
    bool ok = subsetSumMemo(idx + 1, rem, nums, memo) ||
              subsetSumMemo(idx + 1, rem - nums[idx], nums, memo);
    memo[idx][rem] = ok ? 1 : 0;
    return ok;
}

bool subsetSumMemo(const vector<int>& nums, int target) {
    int n = (int)nums.size();
    vector<vector<int>> memo(n, vector<int>(target + 1, -1));
    return subsetSumMemo(0, target, nums, memo);
}

// 2D tabulation: dp[i][s] = can we make sum s using first i numbers?
bool subsetSumTable2D(const vector<int>& nums, int target, bool trace) {
    int n = (int)nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= target; s++) {
            dp[i][s] = dp[i - 1][s];
            if (s >= nums[i - 1] && dp[i - 1][s - nums[i - 1]])
                dp[i][s] = true;
        }
    }
    if (trace) {
        cout << "dp[i][s] = true if sum s achievable with first i nums:\n     ";
        for (int s = 0; s <= target; s++) cout << "s=" << s << "\t";
        cout << "\n";
        for (int i = 0; i <= n; i++) {
            cout << "i=" << i << " ";
            for (int s = 0; s <= target; s++) cout << (dp[i][s] ? 'T' : '.') << "\t";
            cout << "\n";
        }
    }
    return dp[n][target];
}

// 1D tabulation: loop s from target DOWN (0/1 style)
bool subsetSum1D(const vector<int>& nums, int target) {
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int x : nums)
        for (int s = target; s >= x; s--)
            dp[s] = dp[s] || dp[s - x];
    return dp[target];
}

void printOneSubset(int target, const vector<int>& nums) {
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    vector<int> parent(target + 1, -1);
    vector<int> used(target + 1, -1);
    for (int i = 0; i < (int)nums.size(); i++) {
        for (int s = target; s >= nums[i]; s--) {
            if (!dp[s] && dp[s - nums[i]]) {
                dp[s] = true;
                parent[s] = s - nums[i];
                used[s] = i;
            }
        }
    }
    if (!dp[target]) return;
    cout << "  Example subset: { ";
    int s = target;
    bool first = true;
    while (s > 0 && used[s] != -1) {
        if (!first) cout << ", ";
        cout << nums[used[s]];
        first = false;
        s = parent[s];
    }
    cout << " }\n";
}

int main() {
    cout << "Module 37 — Target Sum Subset (j.cpp)\n";
    cout << "====================================\n\n";

    vector<int> nums = {4, 2, 7, 1, 3};
    int target = 7;

    cout << "nums = {4, 2, 7, 1, 3},  target = " << target << "\n\n";

    cout << "Exists subset with sum = target?\n";
    cout << "  Naive recursion: " << (subsetSumNaive(0, target, nums) ? "YES" : "NO") << "\n";
    cout << "  Memoization:     " << (subsetSumMemo(nums, target) ? "YES" : "NO") << "\n";
    cout << "  2D tabulation:\n";
    bool ok = subsetSumTable2D(nums, target, true);
    cout << "  => " << (ok ? "YES" : "NO") << "\n";
    cout << "  1D tabulation:   " << (subsetSum1D(nums, target) ? "YES" : "NO") << "\n";
    if (ok) printOneSubset(target, nums);

    cout << "\nSame as 0/1 knapsack with weight=value=nums[i], capacity=target (boolean dp).\n";
    cout << "Time O(n*target), Space O(target) with 1D.\n";
    return 0;
}
