// MODULE 27 — Problem 1: Split balanced string (greedy balance counter)

#include <iostream>
#include <string>
using namespace std;

int maxBalancedSplits(string s) {
    int balance = 0;
    int count = 0;
    for (char c : s) {
        balance += (c == 'L') ? 1 : -1;
        if (balance == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    string s = "RLRRLLRLRL";
    int ans = maxBalancedSplits(s);

    cout << "Split balanced string\n\n";
    cout << "s = " << s << "\n";
    cout << "max balanced substrings: " << ans << "  (expected 4)\n";

    return 0;
}
