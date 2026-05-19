// MODULE 25 — Stack implemented with std::vector (dynamic “bucket”)

#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> data;

public:
    // Number of elements
    size_t size() const { return data.size(); }

    bool empty() const { return data.empty(); }

    void push(int x) { data.push_back(x); }

    // Remove top element; safe no-op if empty
    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }

    // Top element (undefined if empty — we guard for demo)
    int top() const {
        if (data.empty()) {
            cerr << "top() called on empty stack\n";
            return 0;
        }
        return data.back();
    }

    void clear() { data.clear(); }

    void print(const char* label) const {
        cout << label << " | size=" << size() << " | bottom -> top: ";
        for (size_t i = 0; i < data.size(); ++i) {
            cout << data[i];
            if (i + 1 < data.size()) {
                cout << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    s.print("start");

    s.push(1);
    s.push(2);
    s.push(3);
    s.print("after push 1, 2, 3");

    cout << "top(): " << s.top() << "\n";
    cout << "empty()? " << (s.empty() ? "yes" : "no") << "\n\n";

    s.pop();
    s.print("after pop once");

    s.push(100);
    s.push(200);
    s.print("after push 100, 200");

    while (!s.empty()) {
        cout << "pop -> " << s.top() << "\n";
        s.pop();
    }
    s.print("after draining");

    s.push(7);
    s.print("push after drain");
    s.clear();
    s.print("after clear()");

    return 0;
}
