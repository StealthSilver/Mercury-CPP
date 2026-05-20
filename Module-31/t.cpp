// MODULE 31 — Sort string by character frequency (decreasing)

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string sortByFrequency(const string& s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    vector<pair<char, int>> items(freq.begin(), freq.end());
    sort(items.begin(), items.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    string result;
    for (auto& p : items) {
        result.append(p.second, p.first);
    }
    return result;
}

int main() {
    cout << "Module 31 — Sort by Frequency (t.cpp)\n";
    cout << "=====================================\n\n";

    vector<string> tests = {"tree", "cccaaa", "Aabb"};

    for (const string& s : tests) {
        cout << "   \"" << s << "\"  ->  \"" << sortByFrequency(s) << "\"\n";
    }
    cout << "\n";

    cout << "Count with unordered_map, sort (char, freq) pairs, build string.\n";
    cout << "Time: O(n + k log k)   Space: O(k)  (k = distinct chars)\n";
    return 0;
}
