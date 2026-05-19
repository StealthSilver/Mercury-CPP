/*
 * Problem: Valid Anagram
 * ---------------------------------------------------------------------------
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 * An anagram uses the same characters with the same counts, in any order.
 *
 * Examples:
 *   Input:  s = "anagram", t = "nagaram"  →  Output: true
 *   Input:  s = "rat",     t = "car"      →  Output: false
 *   Input:  s = "a",       t = "ab"       →  Output: false  (different lengths)
 *
 * Assume lowercase English letters only (for the frequency-array approach).
 *
 * This file: three approaches — brute force, sorting, frequency count.
 * Related: 01.cpp (contains duplicate).
 */

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// =============================================================================
// Approach 1 — Brute force (match each char in s to a char in t)
// =============================================================================
class SolutionBruteForce {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < (int)s.length(); i++) {
            bool found = false;

            for (int j = 0; j < (int)t.length(); j++) {
                if (s[i] == t[j]) {
                    found = true;
                    t[j] = '#';  // mark as used (mutates t)
                    break;
                }
            }

            if (!found) {
                return false;
            }
        }

        return true;
    }
};

// • If lengths differ → cannot be anagram → false
// • For each character in s, scan t for a matching unused character
// • Mark matched positions in t (here with '#') so they are not reused
// • If any s[i] has no match in t → false
// • If every character in s finds a partner → true
//
// Time:  O(n²) — n = length; nested loops over s and t
// Space: O(1) extra — only indices (t is modified in place)

// =============================================================================
// Approach 2 — Sorting (same letters → same sorted string)
// =============================================================================
class SolutionSorting {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// • Different lengths → false immediately
// • Sort both strings — anagrams become identical when sorted
// • Compare s == t
//
// Time:  O(n log n) — two sorts
// Space: O(1) extra if sort is in-place (or O(n) depending on sort implementation)

// =============================================================================
// Approach 3 — Frequency array (letter counts)
// =============================================================================
class SolutionFrequency {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int count[26] = {0};

        for (char c : s) {
            count[c - 'a']++;
        }

        for (char c : t) {
            count[c - 'a']--;
            if (count[c - 'a'] < 0) {
                return false;  // t has more of this letter than s
            }
        }

        return true;
    }
};

// • count[i] = how many more of letter ('a' + i) we need from t to match s
// • Increment for each char in s, decrement for each char in t
// • If any count goes negative → t has extra letters → not an anagram
// • If lengths are equal and no count is negative → counts are all zero → true
//
// Time:  O(n) — two passes over the strings
// Space: O(1) — fixed array of 26 integers

// =============================================================================
// main — quick test of all three approaches
// =============================================================================
int main() {
    string s1 = "anagram", t1 = "nagaram";
    string s2 = "rat", t2 = "car";
    string s3 = "a", t3 = "ab";

    SolutionBruteForce brute;
    SolutionSorting sorting;
    SolutionFrequency freq;

    cout << "Brute force  (anagram, nagaram): "
         << (brute.isAnagram(s1, t1) ? "true" : "false") << endl;
    cout << "Brute force  (rat, car):         "
         << (brute.isAnagram(s2, t2) ? "true" : "false") << endl;

    cout << "Sorting      (anagram, nagaram): "
         << (sorting.isAnagram(s1, t1) ? "true" : "false") << endl;
    cout << "Sorting      (rat, car):         "
         << (sorting.isAnagram(s2, t2) ? "true" : "false") << endl;

    cout << "Frequency    (anagram, nagaram): "
         << (freq.isAnagram(s1, t1) ? "true" : "false") << endl;
    cout << "Frequency    (rat, car):         "
         << (freq.isAnagram(s2, t2) ? "true" : "false") << endl;
    cout << "Frequency    (a, ab):            "
         << (freq.isAnagram(s3, t3) ? "true" : "false") << endl;

    return 0;
}
