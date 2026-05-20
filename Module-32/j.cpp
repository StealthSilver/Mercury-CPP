// MODULE 32 — Longest word built one character at a time (sort + prefix set)

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

string longestWord(vector<string>& words) {
    sort(words.begin(), words.end());

    unordered_set<string> buildable;
    string ans;

    for (const string& w : words) {
        if (w.size() == 1 || buildable.count(w.substr(0, w.size() - 1))) {
            buildable.insert(w);
            if (w.size() > ans.size() || (w.size() == ans.size() && w < ans)) {
                ans = w;
            }
        }
    }
    return ans;
}

int main() {
    cout << "Module 32 — Longest Word in Dictionary (j.cpp)\n";
    cout << "=============================================\n\n";

    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    cout << "words: ";
    for (const string& w : words) cout << w << " ";
    cout << "\n\n";

    string ans = longestWord(words);
    cout << "Answer: \"" << ans << "\"\n\n";

    cout << "Sort lexicographically so shorter prefixes appear before longer words.\n";
    cout << "A word w is buildable iff |w|==1 or (w without last char) is already buildable.\n";
    cout << "Same condition as: every prefix of w exists in the dictionary chain.\n";
    cout << "Time: O(n log n * L) for sort + O(n * L) for substr checks\n";
    cout << "Space: O(n * L) for buildable set\n";

    return 0;
}
