#include <iostream>
#include <string>
using namespace std;

// Count substrings s[i..j] where s[i] == s[j] (try all start i, end j >= i).
int countSubstrings(string s, int i, int j) {
    if (i >= (int)s.length())
        return 0;
    if (j >= (int)s.length())
        return countSubstrings(s, i + 1, i + 1);

    int add = (s[i] == s[j]) ? 1 : 0;
    return add + countSubstrings(s, i, j + 1);
}

int main() {
    string s1 = "abcab";
    string s2 = "aba";
    cout << countSubstrings(s1, 0, 0) << endl; // 7
    cout << countSubstrings(s2, 0, 0) << endl; // 4
    return 0;
}
