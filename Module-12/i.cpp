#include <iostream>
using namespace std;

int maxProduct(int *nums, int n)
{
    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for (int i = 1; i < n; i++)
    {
        // If current number is negative, swap max and min
        if (nums[i] < 0)
            swap(maxProd, minProd);

        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);

        result = max(result, maxProd);
    }

    return result;
}

int main()
{
    int nums[] = {2, 3, -2, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    int res = maxProduct(nums, n);
    cout << res << endl;

    return 0;
}