#include <iostream>
using namespace std;

// s: input string (reordered in place), i: next position to fill
void findPermutations(string &s, int i) {
    if (i == s.size()) {
        cout << "\"" << s << "\"" << endl;
        return;
    }

    for (int j = i; j < s.size(); j++) {
        swap(s[i], s[j]);
        findPermutations(s, i + 1);
        swap(s[i], s[j]); // backtrack
    }
}

int main() {
    string s = "abc";

    findPermutations(s, 0);
    return 0;
}
