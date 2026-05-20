// MODULE 39 — Minimum partitioning: minimize |sum(S1) - sum(S2)|
// DP: largest subset sum <= total/2 (0/1 subset sum), then diff = total - 2*best

#include <iostream>
#include <vector>
using namespace std;

// Max subset sum <= half using elements nums[idx..]
int maxSumRecursive(int idx, int cur, int half, const vector<int>& nums) {
    if (idx == (int)nums.size()) return cur;
    int best = maxSumRecursive(idx + 1, cur, half, nums);
    if (cur + nums[idx] <= half)
        best = max(best, maxSumRecursive(idx + 1, cur + nums[idx], half, nums));
    return best;
}

int maxSumMemo(int idx, int cur, int half, const vector<int>& nums, vector<vector<int>>& memo) {
    if (idx == (int)nums.size()) return cur;
    if (memo[idx][cur] != -1) return memo[idx][cur];
    int best = maxSumMemo(idx + 1, cur, half, nums, memo);
    if (cur + nums[idx] <= half)
        best = max(best, maxSumMemo(idx + 1, cur + nums[idx], half, nums, memo));
    return memo[idx][cur] = best;
}

int minPartitionTab(const vector<int>& nums, bool trace) {
    int total = 0;
    for (int x : nums) total += x;
    int half = total / 2;
    vector<bool> dp(half + 1, false);
    dp[0] = true;
    for (int x : nums)
        for (int s = half; s >= x; s--)
            dp[s] = dp[s] || dp[s - x];

    int best = 0;
    for (int s = half; s >= 0; s--)
        if (dp[s]) {
            best = s;
            break;
        }

    if (trace) {
        cout << "total = " << total << ", target <= " << half << "\n";
        cout << "dp[s] = true if some subset sums to s:\n  ";
        for (int s = 0; s <= half; s++) cout << (dp[s] ? 'T' : '.');
        cout << "\n  largest achievable s = " << best << "\n";
    }
    return total - 2 * best;
}

void demo(const vector<int>& nums, int expect) {
    int total = 0;
    for (int x : nums) total += x;
    int half = total / 2;
    vector<vector<int>> memo(nums.size(), vector<int>(half + 1, -1));
    int bestRec = maxSumRecursive(0, 0, half, nums);
    int bestMem = maxSumMemo(0, 0, half, nums, memo);
    int diff = minPartitionTab(nums, false);

    cout << "nums = {";
    for (int i = 0; i < (int)nums.size(); i++) {
        if (i) cout << ", ";
        cout << nums[i];
    }
    cout << "}  (sum = " << total << ", half = " << half << ")\n";
    cout << "  max subset sum <= half: rec=" << bestRec << ", memo=" << bestMem
         << ", tab=" << (total - diff) / 2 << "\n";
    cout << "  min |S1-S2| diff: " << diff;
    if (expect >= 0) cout << " (expect " << expect << ")";
    cout << "\n\n";
}

int main() {
    cout << "Module 39 — Minimum partitioning (j.cpp)\n";
    cout << "========================================\n\n";

    cout << "Split into two subsets; minimize absolute difference of sums.\n";
    cout << "Same as: max subset sum <= total/2, answer = total - 2*best.\n\n";

    demo({1, 6, 11, 5}, 1);

    cout << "Also (5 numbers):\n";
    demo({1, 7, 6, 11, 5}, 2);
    return 0;
}
