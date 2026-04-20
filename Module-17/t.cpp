#include <iostream>
#include <vector>
using namespace std;

int xorBeauty(vector<int> &nums)
{
    int result = 0;

    for (int num : nums)
    {
        result ^= num;
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 4};

    cout << "XOR Beauty: " << xorBeauty(nums) << endl;

    return 0;
}