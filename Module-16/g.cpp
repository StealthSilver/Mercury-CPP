#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSumBruteForce(vector<int> &arr, int target)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i, j}; // return indices
            }
        }
    }

    return {-1, -1}; // if no pair found
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = pairSumBruteForce(arr, target);

    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}