// MODULE 25 — Stack illustration (array = "bucket" in memory)
// Operations: Push, Pop, Top — each O(1) with fixed capacity.

#include <iostream>
using namespace std;

// Fixed-size array acts like one bucket: indices 0 .. CAPACITY-1
const int CAPACITY = 8;

struct Stack {
    int data[CAPACITY];
    int top;  // number of elements currently in stack; next push goes at index `top`

    Stack() : top(0) {}

    bool empty() const { return top == 0; }
    bool full() const { return top == CAPACITY; }

    // Push: put value on top (grow toward higher indices)
    void push(int x) {
        if (full()) {
            cout << "push(" << x << ") ignored — stack full\n";
            return;
        }
        data[top] = x;
        ++top;
    }

    // Pop: remove top element (only moves `top`; no per-element delete)
    void pop() {
        if (empty()) {
            cout << "pop() ignored — stack empty\n";
            return;
        }
        --top;
    }

    // Top: read top without removing
    int topValue() const {
        if (empty()) {
            cout << "topValue() error — stack empty\n";
            return 0;
        }
        return data[top - 1];
    }

    void printState(const char* label) const {
        cout << label << " | size=" << top << " | bottom -> top: ";
        for (int i = 0; i < top; ++i) {
            cout << data[i];
            if (i + 1 < top) {
                cout << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    s.printState("start");

    s.push(10);
    s.push(20);
    s.push(30);
    s.printState("after push 10, 20, 30");

    cout << "Top (peek): " << s.topValue() << "\n";

    s.pop();
    s.printState("after one pop (30 removed; LIFO)");

    s.push(40);
    s.printState("after push 40");

    cout << "Top: " << s.topValue() << "\n";

    return 0;
}
