#include <iostream>
#include <algorithm>
using namespace std;

bool validAnagram(string s, string t)
{
    // If lengths are different, they can't be anagrams
    if (s.length() != t.length())
    {
        return false;
    }

    // Sort both strings
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    // Compare sorted strings
    return s == t;
}

int main()
{
    string str1, str2;

    str1 = "abcghi";
    str2 = "ghiabce";

    if (validAnagram(str1, str2))
    {
        cout << "The strings are anagrams." << endl;
    }
    else
    {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}