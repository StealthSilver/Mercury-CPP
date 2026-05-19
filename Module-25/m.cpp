// MODULE 25 — Duplicate parentheses in an expression (stack)

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool hasDuplicateParentheses(const string& exp) {
    stack<char> st;

    for (char c : exp) {
        if (c == ')') {
            int count = 0;
            while (!st.empty() && st.top() != '(') {
                st.pop();
                ++count;
            }
            if (st.empty()) {
                return false;  // malformed; treat as no duplicate
            }
            st.pop();  // remove '('
            if (count == 0) {
                return true;
            }
        } else {
            st.push(c);
        }
    }
    return false;
}

int main() {
    struct Case {
        string exp;
        bool expectDup;
    };

    Case cases[] = {
        {"(a+b)", false},
        {"((a+b))", true},
        {"(a+(b)/c)", false},
        {"(a+(b+c))", false},
        {"((a+b)+c)", false},
    };

    cout << "Duplicate parentheses\n\n";
    for (const Case& c : cases) {
        bool got = hasDuplicateParentheses(c.exp);
        cout << c.exp << " -> "
             << (got ? "duplicate" : "no duplicate")
             << (got == c.expectDup ? "  OK" : "  FAIL") << "\n";
    }

    return 0;
}
