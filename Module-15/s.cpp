#include <bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2)
{
    if (word1.length() != word2.length())
        return false;

    vector<int> freq1(26, 0), freq2(26, 0);

    // Count frequencies
    for (char c : word1)
        freq1[c - 'a']++;
    for (char c : word2)
        freq2[c - 'a']++;

    // Check same set of characters
    for (int i = 0; i < 26; i++)
    {
        if ((freq1[i] == 0 && freq2[i] != 0) ||
            (freq1[i] != 0 && freq2[i] == 0))
        {
            return false;
        }
    }

    // Sort frequencies
    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());

    // Compare frequency arrays
    return freq1 == freq2;
}

int main()
{
    string word1 = "abc";
    string word2 = "bca";

    if (closeStrings(word1, word2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}