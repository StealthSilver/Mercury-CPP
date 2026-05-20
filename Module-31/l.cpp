// MODULE 31 — Valid Anagram (same characters, same counts)

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(const string& s, const string& t) {
    if (s.size() != t.size()) {
        return false;
    }

    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    for (char c : t) {
        if (--freq[c] < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Module 31 — Valid Anagram (l.cpp)\n";
    cout << "=================================\n\n";

    auto check = [](const string& a, const string& b) {
        cout << "   \"" << a << "\" vs \"" << b << "\"  →  "
             << (isAnagram(a, b) ? "anagram" : "not anagram") << "\n";
    };

    check("listen", "silent");
    check("abc", "cba");
    check("abc", "abd");
    check("aacc", "ccac");

    cout << "\nunordered_map<char,int> stores character frequencies.\n";
    cout << "Time: O(n)   Space: O(1) — at most 26 letters (or O(k) unique chars)\n";
    return 0;
}
