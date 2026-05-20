// MODULE 32 — Group Anagrams (hash map: sorted letters as key)

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;

    for (string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(move(s));
    }

    vector<vector<string>> result;
    result.reserve(groups.size());
    for (auto& p : groups) {
        result.push_back(move(p.second));
    }
    return result;
}

int main() {
    cout << "Module 32 — Group Anagrams (i.cpp)\n";
    cout << "==================================\n\n";

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);

    cout << "Input: eat tea tan ate nat bat\n\n";
    cout << "Groups (any order):\n";
    for (const auto& g : ans) {
        cout << "  ";
        for (const string& w : g) cout << w << " ";
        cout << "\n";
    }
    cout << "\n";

    cout << "Key = sorted characters. Anagrams share the same sorted key.\n";
    cout << "Time: O(n * k log k)   n = number of strings, k = max length\n";
    cout << "Space: O(n * k) for keys and output\n";

    return 0;
}
