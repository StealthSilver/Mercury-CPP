#include <iostream>
#include <vector>
using namespace std;

// Two pointer function
vector<int> pairSumTwoPointer(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
        {
            return {left, right}; // return indices
        }
        else if (sum < target)
        {
            left++; // increase sum
        }
        else
        {
            right--; // decrease sum
        }
    }

    return {-1, -1}; // if no pair found
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = pairSumTwoPointer(arr, target);

    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}