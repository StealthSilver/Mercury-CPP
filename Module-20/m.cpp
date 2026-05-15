#include <iostream>
#include <string>
using namespace std;

// Remove duplicates; keep first occurrence of each letter (order preserved).
string removeDuplicates(string s, int i) {
    if (i == (int)s.length())
        return "";

    string rest = removeDuplicates(s, i + 1);
    char ch = s[i];

    if (rest.find(ch) != string::npos)
        return rest;

    return ch + rest;
}

int main() {
    string s = "abbccd";
    cout << removeDuplicates(s, 0) << endl; // abcd
    return 0;
}
