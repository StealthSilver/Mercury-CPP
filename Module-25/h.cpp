// MODULE 25 — Reverse a string using a stack (LIFO)

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseWithStack(const string& s) {
    stack<char> st;
    for (char c : s) {
        st.push(c);
    }

    string out;
    out.reserve(s.size());
    while (!st.empty()) {
        out.push_back(st.top());
        st.pop();
    }
    return out;
}

int main() {
    string s = "hello";
    string rev = reverseWithStack(s);

    cout << "original:  \"" << s << "\"  (n = " << s.size() << ")\n";
    cout << "reversed:  \"" << rev << "\"\n\n";

    cout << "Push left-to-right: h e l l o  ->  top is last pushed ('o')\n";
    cout << "Pop order (LIFO):   o l l e h  ->  \"olleh\"\n";

    return 0;
}
