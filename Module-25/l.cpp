// MODULE 25 — Valid parentheses (stack)

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

bool isValid(const string& s) {
    stack<char> st;
    unordered_map<char, char> closeToOpen = {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty() || st.top() != closeToOpen[c]) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string tests[] = {"()", "()[]{}", "(]", "([)]", "{[]}", "((("};

    cout << "Valid parentheses\n\n";
    for (const string& t : tests) {
        cout << "\"" << t << "\" -> " << (isValid(t) ? "valid" : "invalid") << "\n";
    }

    return 0;
}
