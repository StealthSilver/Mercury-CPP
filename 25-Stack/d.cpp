// MODULE 25 — Stack as a class template: element type T is a template parameter

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Stack {
    vector<T> data;

public:
    size_t size() const { return data.size(); }

    bool empty() const { return data.empty(); }

    void push(const T& x) { data.push_back(x); }

    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }

    T top() const {
        if (data.empty()) {
            cerr << "top() called on empty stack\n";
            return T{};
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
    cout << "=== Stack<int> ===\n";
    Stack<int> si;
    si.push(10);
    si.push(20);
    si.print("int stack");
    cout << "top: " << si.top() << "\n";
    si.pop();
    si.print("after pop");
    si.clear();

    cout << "\n=== Stack<string> (same class, different T) ===\n";
    Stack<string> ss;
    ss.push("hello");
    ss.push("world");
    ss.print("string stack");
    cout << "top: \"" << ss.top() << "\"\n";
    while (!ss.empty()) {
        cout << "pop -> \"" << ss.top() << "\"\n";
        ss.pop();
    }
    ss.print("drained");

    return 0;
}
