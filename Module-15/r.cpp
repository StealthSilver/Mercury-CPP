#include <iostream>
#include <vector>
using namespace std;

bool canBeEqualWithOneSwap(string s1, string s2)
{
    // If lengths differ, impossible
    if (s1.length() != s2.length())
    {
        return false;
    }

    // Store indices where characters differ
    vector<int> diff;

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
        {
            diff.push_back(i);
        }
    }

    // Case 1: already equal
    if (diff.size() == 0)
    {
        return true;
    }

    // Case 2: exactly two mismatches
    if (diff.size() == 2)
    {
        int i = diff[0];
        int j = diff[1];

        // Check if swapping makes them equal
        return (s1[i] == s2[j] && s1[j] == s2[i]);
    }

    return false;
}

int main()
{
    string s1 = "bank";
    string s2 = "kanb";

    if (canBeEqualWithOneSwap(s1, s2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}