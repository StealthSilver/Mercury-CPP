#include <iostream>
using namespace std;

bool checkAnagrams(string s, string t)
{
    // If lengths differ, not anagrams
    if (s.length() != t.length())
    {
        return false;
    }

    int count[26] = {0};

    // Count characters from first string
    for (char c : s)
    {
        count[c - 'a']++;
    }

    // Decrease count using second string
    for (char c : t)
    {
        count[c - 'a']--;
    }

    // Check if all counts are zero
    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string str1, str2;

    str1 = "abcghi";
    str2 = "ghiabce";

    if (checkAnagrams(str1, str2))
    {
        cout << "The strings are anagrams." << endl;
    }
    else
    {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}