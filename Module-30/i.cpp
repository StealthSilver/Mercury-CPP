// MODULE 30 — Sliding window maximum — max-heap (value, index) + lazy removal

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<int> maxSlidingWindowHeap(const vector<int>& nums, int k) {
    vector<int> ans;
    if (nums.empty() || k == 0) {
        return ans;
    }

    // Max-heap: largest value on top; tie-break by larger index
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second < b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    cout << "  Window [i-k+1 .. i]   heap top (max)\n";

    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        pq.push({nums[i], i});

        // Remove indices that left the window
        while (!pq.empty() && pq.top().second <= i - k) {
            pq.pop();
        }

        if (i >= k - 1) {
            cout << "  i=" << i << "  [" << i - k + 1 << ".." << i << "]"
                 << "  → max = " << pq.top().first
                 << "  (index " << pq.top().second << ")\n";
            ans.push_back(pq.top().first);
        }
    }
    return ans;
}

int main() {
    cout << "Sliding Window Maximum — heap (i.cpp)\n";
    cout << "=====================================\n\n";

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    cout << "nums = ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\nK = " << k << "\n\n";

    vector<int> ans = maxSlidingWindowHeap(nums, k);

    cout << "\nOutput: [";
    for (int i = 0; i < static_cast<int>(ans.size()); ++i) {
        if (i) {
            cout << ", ";
        }
        cout << ans[i];
    }
    cout << "]\n";

    cout << "\nTime: O(n log n) worst-case   Space: O(n)\n";
    cout << "(Each index pushed once; stale tops popped lazily)\n";

    return 0;
}
