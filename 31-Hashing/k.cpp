// MODULE 31 — Majority Element II: values appearing more than n/3 times

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Hash map: count every value, collect those with freq > n/3
vector<int> majorityMoreThanThird(int* nums, int n) {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    vector<int> result;
    for (const auto& p : freq) {
        if (p.second > n / 3) {
            result.push_back(p.first);
        }
    }
    return result;
}

// Boyer–Moore extended: at most two candidates can exceed n/3
vector<int> majorityMoreThanThirdVoting(int* nums, int n) {
    int cand1 = 0, cand2 = 0;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == cand1) {
            count1++;
        } else if (nums[i] == cand2) {
            count2++;
        } else if (count1 == 0) {
            cand1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            cand2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == cand1) count1++;
        if (nums[i] == cand2) count2++;
    }

    vector<int> result;
    if (count1 > n / 3) result.push_back(cand1);
    if (count2 > n / 3 && cand2 != cand1) result.push_back(cand2);
    return result;
}

void printResult(const string& label, const vector<int>& v) {
    cout << label << ": ";
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    cout << "Module 31 — Majority Element (> n/3) (k.cpp)\n";
    cout << "=============================================\n\n";

    int nums1[] = {3, 2, 3};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printResult("   [3,2,3] hash", majorityMoreThanThird(nums1, n1));
    printResult("   [3,2,3] vote", majorityMoreThanThirdVoting(nums1, n1));

    int nums2[] = {1, 1, 1, 3, 3, 2, 2, 2};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printResult("   [1,1,1,3,3,2,2,2] hash", majorityMoreThanThird(nums2, n2));
    printResult("   [1,1,1,3,3,2,2,2] vote", majorityMoreThanThirdVoting(nums2, n2));

    cout << "\nAt most 2 elements can appear more than n/3 times.\n";
    cout << "Hash: O(n) time, O(n) space | Voting: O(n) time, O(1) space\n";
    return 0;
}
