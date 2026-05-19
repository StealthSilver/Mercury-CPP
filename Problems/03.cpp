/*
 * Problem: Two Sum
 * ---------------------------------------------------------------------------
 * Given an integer array nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 *
 * You may assume exactly one solution exists, and you may not use the same
 * element twice. Return the answer in any order.
 *
 * Examples:
 *   Input:  nums = [2, 7, 11, 15], target = 9   →  Output: [0, 1]
 *           (nums[0] + nums[1] = 2 + 7 = 9)
 *   Input:  nums = [3, 2, 4],      target = 6   →  Output: [1, 2]
 *   Input:  nums = [3, 3],         target = 6   →  Output: [0, 1]
 *
 * This file: brute force, hash map, sorting + two pointers.
 * Related: 01.cpp (contains duplicate), 02.cpp (valid anagram).
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

void printAnswer(const string& label, const vector<int>& ans) {
    cout << label << ": [";
    if (ans.size() >= 1) cout << ans[0];
    if (ans.size() >= 2) cout << ", " << ans[1];
    cout << "]" << endl;
}

// =============================================================================
// Approach 1 — Brute force (try every pair)
// =============================================================================
class SolutionBruteForce {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < (int)nums.size(); i++) {
            for (int j = i + 1; j < (int)nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// • Fix i, try every j > i
// • If nums[i] + nums[j] == target → return indices {i, j}
// • If no pair works → return empty vector
//
// Time:  O(n²)
// Space: O(1)

// =============================================================================
// Approach 2 — Hash map (store value → index, look for complement)
// =============================================================================
class SolutionHashMap {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // value → index

        for (int i = 0; i < (int)nums.size(); i++) {
            int need = target - nums[i];

            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

// • need = target - nums[i] is the value we must have seen earlier
// • If need is already in the map → pair found → return {old index, i}
// • Otherwise store nums[i] with its index and continue
// • One pass, no nested loops
//
// Time:  O(n) average
// Space: O(n) for the map

// =============================================================================
// Approach 3 — Sorting + two pointers (keep original indices)
// =============================================================================
class SolutionTwoPointers {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr;  // (value, original index)

        for (int i = 0; i < (int)nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int l = 0, r = (int)arr.size() - 1;

        while (l < r) {
            int sum = arr[l].first + arr[r].first;

            if (sum == target) {
                return {arr[l].second, arr[r].second};
            }
            if (sum < target) {
                l++;
            } else {
                r--;
            }
        }

        return {};
    }
};

// • Copy (value, index) pairs so sorting does not lose original positions
// • Sort by value — two pointers work on sorted values
// • l at start, r at end: if sum too small → l++; too big → r--
// • If sum == target → return the two stored indices
//
// Time:  O(n log n) — sort dominates
// Space: O(n) for the pair array

// =============================================================================
// main
// =============================================================================
int main() {
    SolutionBruteForce brute;
    SolutionHashMap hashMap;
    SolutionTwoPointers twoPtr;

    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;

    vector<int> nums3 = {3, 3};
    int target3 = 6;

    printAnswer("Brute force  [2,7,11,15], t=9",
                brute.twoSum(nums1, target1));
    nums1 = {2, 7, 11, 15};

    printAnswer("Hash map     [2,7,11,15], t=9",
                hashMap.twoSum(nums1, target1));
    nums1 = {2, 7, 11, 15};

    printAnswer("Two pointers [2,7,11,15], t=9",
                twoPtr.twoSum(nums1, target1));

    printAnswer("Hash map     [3,2,4], t=6",
                hashMap.twoSum(nums2, target2));
    printAnswer("Two pointers [3,3], t=6",
                twoPtr.twoSum(nums3, target3));

    return 0;
}
