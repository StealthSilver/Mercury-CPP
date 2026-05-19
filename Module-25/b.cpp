// MODULE 25 — LIFO (Last In, First Out) illustration
// Same stack idea as a.cpp: show that pop order reverses push order.

#include <iostream>
using namespace std;

const int CAP = 16;

struct Stack {
    char a[CAP];
    int n;

    Stack() : n(0) {}

    void push(char ch) {
        if (n >= CAP) {
            return;
        }
        cout << "  push('" << ch << "') — '" << ch << "' is now LAST in (on top)\n";
        a[n++] = ch;
    }

    char pop() {
        if (n <= 0) {
            cout << "  pop() — empty, nothing to remove\n";
            return '\0';
        }
        char ch = a[--n];
        cout << "  pop()  — removed '" << ch << "' (FIRST out among what remains)\n";
        return ch;
    }

    void printTop() const {
        if (n <= 0) {
            cout << "  (stack empty)\n";
        } else {
            cout << "  current top (last pushed): '" << a[n - 1] << "'\n";
        }
    }
};

int main() {
    Stack s;

    cout << "--- Push A, then B, then C (order IN: A -> B -> C) ---\n";
    s.push('A');
    s.push('B');
    s.push('C');
    s.printTop();

    cout << "\n--- Pop three times: watch OUT order (should be C -> B -> A) ---\n";
    cout << "LIFO: last pushed was C, so C leaves first.\n\n";
    s.pop();
    s.printTop();
    s.pop();
    s.printTop();
    s.pop();
    s.printTop();

    cout << "\n--- Compare: FIFO would have given A, then B, then C ---\n";
    cout << "Stack gives reverse order on exit: that is LIFO.\n";

    return 0;
}
