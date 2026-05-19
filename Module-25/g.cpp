// MODULE 25 — Push at bottom of stack (recursive) + pass-by-reference

#include <iostream>
#include <stack>
using namespace std;

// Must take stack by reference — a copy would not update the caller's stack.
void pushAtBottom(stack<int>& s, int value) {
    if (s.empty()) {
        s.push(value);
        return;
    }
    int topVal = s.top();
    s.pop();
    pushAtBottom(s, value);
    s.push(topVal);
}

// Pass by value: works on a copy so the caller's stack is unchanged.
void printBottomToTop(stack<int> s) {
    stack<int> rev;
    while (!s.empty()) {
        rev.push(s.top());
        s.pop();
    }
    while (!rev.empty()) {
        cout << rev.top();
        rev.pop();
        if (!rev.empty()) {
            cout << " ";
        }
    }
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Before pushAtBottom(s, 0) — bottom -> top: ";
    printBottomToTop(s);
    cout << "\n";
    cout << "top: " << s.top() << " size: " << s.size() << "\n\n";

    pushAtBottom(s, 0);

    cout << "After pushAtBottom(s, 0) — bottom -> top: ";
    printBottomToTop(s);
    cout << "\n";
    cout << "top: " << s.top() << " size: " << s.size() << "\n";

    return 0;
}
