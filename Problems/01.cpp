/*
 * Problem: Contains Duplicate
 * ---------------------------------------------------------------------------
 * Given an integer array nums, return true if any value appears at least
 * twice in the array, and false if every element is distinct.
 *
 * Examples:
 *   Input:  nums = [1, 2, 3, 1]   →  Output: true
 *   Input:  nums = [1, 2, 3, 4]   →  Output: false
 *   Input:  nums = [1, 1, 1, 3]   →  Output: true
 *
 * This file collects three approaches (brute force, sorting, hash set).
 * Standalone sorting version: 02.cpp · hash set version: 03.cpp (when added)
 */

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// =============================================================================
// Approach 1 — Brute force (compare every pair)
// =============================================================================
class SolutionBruteForce {
public:
    bool hasDuplicate(vector<int>& nums) {
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};

// • Outer loop picks one index i
// • Inner loop compares nums[i] with every nums[j] where j > i
// • If any pair matches → duplicate exists → return true
// • If all pairs checked with no match → return false
//
// Time:  O(n²) — nested loops over the array
// Space: O(1) — only a few index variables

// =============================================================================
// Approach 2 — Sorting (adjacent duplicates after sort)
// See also: 02.cpp
// =============================================================================
class SolutionSorting {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i + 1 < (int)nums.size(); i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }

        return false;
    }
};

// • Sort nums so equal values end up next to each other
// • Scan adjacent pairs: if nums[i] == nums[i + 1] → duplicate → true
// • If scan finishes with no equal neighbors → false
//
// Time:  O(n log n) — dominated by sort
// Space: O(1) extra if sort is in-place (ignoring sort implementation details)

// =============================================================================
// Approach 3 — Hash set (track seen values)
// See also: 03.cpp
// =============================================================================
class SolutionHashSet {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
};

// • Walk through nums once
// • If num is already in seen → we have seen it before → duplicate → true
// • Otherwise insert num into seen and continue
// • If loop ends → every value was unique → false
//
// Time:  O(n) average — one pass, O(1) average set operations
// Space: O(n) — set may store up to n elements

// =============================================================================
// main — quick test of all three approaches
// =============================================================================
int main() {
    vector<int> withDup = {1, 2, 3, 1};
    vector<int> noDup = {1, 2, 3, 4};

    SolutionBruteForce brute;
    SolutionSorting sorting;
    SolutionHashSet hashSet;

    cout << "Brute force  [1,2,3,1]: " << (brute.hasDuplicate(withDup) ? "true" : "false") << endl;
    cout << "Brute force  [1,2,3,4]: " << (brute.hasDuplicate(noDup) ? "true" : "false") << endl;

    withDup = {1, 2, 3, 1};
    noDup = {1, 2, 3, 4};
    cout << "Sorting      [1,2,3,1]: " << (sorting.hasDuplicate(withDup) ? "true" : "false") << endl;
    cout << "Sorting      [1,2,3,4]: " << (sorting.hasDuplicate(noDup) ? "true" : "false") << endl;

    withDup = {1, 2, 3, 1};
    noDup = {1, 2, 3, 4};
    cout << "Hash set     [1,2,3,1]: " << (hashSet.hasDuplicate(withDup) ? "true" : "false") << endl;
    cout << "Hash set     [1,2,3,4]: " << (hashSet.hasDuplicate(noDup) ? "true" : "false") << endl;

    return 0;
}
