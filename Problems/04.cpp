/*
 * Problem: Group Anagrams
 * ---------------------------------------------------------------------------
 * Given an array of strings strs, group all anagrams together. You may return
 * the answer in any order.
 *
 * An anagram uses the same characters with the same counts (order may differ).
 *
 * Example:
 *   Input:  strs = ["eat","tea","tan","ate","nat","bat"]
 *   Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *           (any order of groups and strings within groups is OK)
 *
 * This file: brute force, hash map (sorted key), hash map (character counts).
 * Related: 02.cpp (valid anagram check).
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void printGroups(const string& label, const vector<vector<string>>& groups) {
    cout << label << ":" << endl;
    for (const auto& group : groups) {
        cout << "  [";
        for (int i = 0; i < (int)group.size(); i++) {
            cout << "\"" << group[i] << "\"";
            if (i + 1 < (int)group.size()) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << endl;
}

// =============================================================================
// Approach 1 — Brute force (compare every string to a group leader)
// =============================================================================
class SolutionBruteForce {
    bool isAnagram(string a, string b) {
        if (a.size() != b.size()) {
            return false;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<bool> used(n, false);
        vector<vector<string>> result;

        for (int i = 0; i < n; i++) {
            if (used[i]) {
                continue;
            }

            vector<string> group;
            group.push_back(strs[i]);
            used[i] = true;

            for (int j = i + 1; j < n; j++) {
                if (!used[j] && isAnagram(strs[i], strs[j])) {
                    group.push_back(strs[j]);
                    used[j] = true;
                }
            }

            result.push_back(group);
        }

        return result;
    }
};

// • Pick each unused string strs[i] as the start of a new group
// • Scan j > i; if strs[j] is an anagram of strs[i], add it to the group
// • isAnagram: sort both copies and compare (same idea as 02.cpp sorting)
// • Mark indices used so each string joins exactly one group
//
// Time:  O(n² · k log k) — n strings, compare pairs; k = max string length for sort
// Space: O(n · k) — result + used array

// =============================================================================
// Approach 2 — Hash map (sorted string as key)
// =============================================================================
class SolutionHashMap {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& entry : mp) {
            result.push_back(entry.second);
        }

        return result;
    }
};

// • Anagrams become the same string when sorted → use sorted form as map key
// • mp[key] holds all original strings that share that key
// • Collect all map values into result
//
// Time:  O(n · k log k) — n strings, sort each for key
// Space: O(n · k) — map stores all strings

// =============================================================================
// Approach 3 — Hash map (character count as key)
// =============================================================================
class SolutionCharacterCount {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const string& s : strs) {
            vector<int> count(26, 0);

            for (char c : s) {
                count[c - 'a']++;
            }

            // Build a unique key from the 26 letter counts
            // "#" avoids ambiguity (e.g. "1" + "11" vs "11" + "1")
            string key;
            for (int x : count) {
                key += to_string(x) + "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& entry : mp) {
            result.push_back(entry.second);
        }

        return result;
    }
};

// • Count how many times each letter a–z appears in s
// • Turn the count array into a string key (same counts → same key → same group)
// • No need to sort s — only O(k) counting per string
// • Same map grouping idea as Approach 2, different key construction
//
// Time:  O(n · k) — n strings, k = length of each string
// Space: O(n · k) — map stores all strings

// =============================================================================
// main
// =============================================================================
int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    SolutionBruteForce brute;
    vector<string> copy1 = strs;
    printGroups("Brute force", brute.groupAnagrams(copy1));

    SolutionHashMap hashMap;
    vector<string> copy2 = strs;
    printGroups("Hash map (sorted key)", hashMap.groupAnagrams(copy2));

    SolutionCharacterCount charCount;
    vector<string> copy3 = strs;
    printGroups("Hash map (char count)", charCount.groupAnagrams(copy3));

    return 0;
}