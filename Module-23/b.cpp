#include <iostream>
using namespace std;

// Print current subset; empty string is the null set
void printSubset(const string &subset) {
    cout << "\"" << subset << "\"" << endl;
}

// s: input string, subset: choices so far, i: next index to decide (include or skip)
void findSubsets(string &s, string &subset, int i) {
    if (i == s.size()) {
        printSubset(subset);
        return;
    }

    // skip s[i]
    findSubsets(s, subset, i + 1);

    // take s[i]
    subset.push_back(s[i]);
    findSubsets(s, subset, i + 1);
    subset.pop_back(); // backtrack
}

int main() {
    string s = "abc";
    string subset = "";

    findSubsets(s, subset, 0);
    return 0;
}
