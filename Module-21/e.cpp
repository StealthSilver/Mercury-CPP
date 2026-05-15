#include <iostream>
using namespace std;

// Majority element appears more than floor(n/2) times; guaranteed to exist.
int majorityElement(int *nums, int n) {
    int candidate = nums[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}

int main() {
    int nums[] = {3, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << majorityElement(nums, n) << endl; // 3

    int nums2[] = {2, 2, 1, 1, 1, 2, 2};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    cout << majorityElement(nums2, n2) << endl; // 2

    return 0;
}
