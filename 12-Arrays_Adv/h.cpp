#include <iostream>
using namespace std;

int search(int *nums, int n, int target)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half is sorted
        if (nums[start] <= nums[mid])
        {
            if (nums[start] <= target && target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        // Right half is sorted
        else
        {
            if (nums[mid] < target && target <= nums[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int nums[] = {4, 5, 6, 7, 8, 0, 1, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);

    int res = search(nums, n, 6);
    cout << res << endl;

    return 0;
}