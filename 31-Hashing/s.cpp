// MODULE 31 — Two Sum (unordered_map complement lookup)

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> valueToIndex;

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        int need = target - nums[i];
        if (valueToIndex.count(need)) {
            return {valueToIndex[need], i};
        }
        valueToIndex[nums[i]] = i;
    }
    return {};
}

int main() {
    cout << "Module 31 — Two Sum (s.cpp)\n";
    cout << "============================\n\n";

    auto run = [](vector<int> nums, int target) {
        vector<int> ans = twoSum(nums, target);
        cout << "   nums = ";
        for (int x : nums) cout << x << " ";
        cout << ", target = " << target << "\n";
        cout << "   indices = [" << ans[0] << ", " << ans[1] << "]";
        cout << "  (values " << nums[ans[0]] << " + " << nums[ans[1]] << ")\n\n";
    };

    run({2, 7, 11, 15}, 9);
    run({3, 2, 4}, 6);
    run({3, 3}, 6);

    cout << "Store value -> index; check if (target - nums[i]) seen.\n";
    cout << "Time: O(n) avg   Space: O(n)\n";
    return 0;
}
