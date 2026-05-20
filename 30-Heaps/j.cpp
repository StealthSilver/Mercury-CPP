// MODULE 30 — Sliding window maximum — monotonic deque (O(n))

#include <deque>
#include <iostream>
#include <vector>
using namespace std;

vector<int> maxSlidingWindowDeque(const vector<int>& nums, int k) {
    vector<int> ans;
    if (nums.empty() || k == 0) {
        return ans;
    }

    deque<int> dq;  // stores indices; values at indices are decreasing

    cout << "  i   push   deque (indices → values)        max\n";

    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        // 1. Remove indices outside window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // 2. Before pushing i, remove smaller elements from back (useless for future max)
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            cout << "      pop back index " << dq.back() << " (" << nums[dq.back()]
                 << ") ≤ " << nums[i] << "\n";
            dq.pop_back();
        }

        dq.push_back(i);

        cout << "  " << i << "   " << nums[i] << "   [";
        for (int j = 0; j < static_cast<int>(dq.size()); ++j) {
            if (j) {
                cout << ", ";
            }
            cout << dq[j] << "→" << nums[dq[j]];
        }
        cout << "]";

        if (i >= k - 1) {
            cout << "        " << nums[dq.front()];
            ans.push_back(nums[dq.front()]);
        }
        cout << "\n";
    }
    return ans;
}

int main() {
    cout << "Sliding Window Maximum — deque (j.cpp)\n";
    cout << "======================================\n\n";

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    cout << "nums = ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\nK = " << k << "\n\n";
    cout << "Deque stores indices; front = index of current window maximum.\n\n";

    vector<int> ans = maxSlidingWindowDeque(nums, k);

    cout << "\nOutput: [";
    for (int i = 0; i < static_cast<int>(ans.size()); ++i) {
        if (i) {
            cout << ", ";
        }
        cout << ans[i];
    }
    cout << "]\n";

    cout << "\nTime: O(n)   Space: O(k)\n";

    return 0;
}
