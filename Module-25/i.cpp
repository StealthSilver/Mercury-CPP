// MODULE 25 — Reverse a stack in place: recursion + pushAtBottom (no extra container)

#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int>& s, int value) {
    if (s.empty()) {
        s.push(value);
        return;
    }
    int t = s.top();
    s.pop();
    pushAtBottom(s, value);
    s.push(t);
}

void reverseStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    int x = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s, x);
}

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

    cout << "Before reverse — bottom -> top: ";
    printBottomToTop(s);
    cout << "  (top = " << s.top() << ")\n";

    reverseStack(s);

    cout << "After reverse  — bottom -> top: ";
    printBottomToTop(s);
    cout << "  (top = " << s.top() << ")\n";

    return 0;
}
