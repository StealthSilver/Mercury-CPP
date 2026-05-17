#include <iostream>
#include <string>
using namespace std;

const string keypad[] = {"",    "",    "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};

void findCombinations(const string &digits, int i, string &current) {
    if (i == (int)digits.size()) {
        cout << current << endl;
        return;
    }

    string letters = keypad[digits[i] - '0'];
    for (char ch : letters) {
        current.push_back(ch);
        findCombinations(digits, i + 1, current);
        current.pop_back();
    }
}

int main() {
    string digits = "23";

    cout << "Combinations for \"" << digits << "\":\n";
    string current;
    findCombinations(digits, 0, current);

    return 0;
}
