// MODULE 26 — Stack implemented with std::deque (LIFO)

#include <deque>
#include <iostream>
#include <stack>
using namespace std;

class StackDeque {
    deque<int> d;

public:
    bool empty() const { return d.empty(); }
    size_t size() const { return d.size(); }

    void push(int x) { d.push_back(x); }
    void pop() {
        if (!d.empty()) {
            d.pop_back();
        }
    }
    int top() const { return d.back(); }

    void print(const char* label) const {
        cout << label << " | size=" << d.size() << " | bottom -> top: ";
        for (size_t i = 0; i < d.size(); ++i) {
            cout << d[i];
            if (i + 1 < d.size()) {
                cout << " ";
            }
        }
        cout << " (top=" << (d.empty() ? -1 : d.back()) << ")\n";
    }
};

int main() {
    cout << "=== Stack using deque ===\n\n";

    StackDeque st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.print("after push 10, 20, 30");
    cout << "top(): " << st.top() << "\n";

    st.pop();
    st.print("after pop (LIFO removes 30)");

    st.push(40);
    st.print("after push 40");

    cout << "\n--- STL adapter: stack<int, deque<int>> ---\n";
    stack<int, deque<int>> stlS;
    stlS.push(1);
    stlS.push(2);
    cout << "push 1,2 | top=" << stlS.top() << "\n";
    stlS.pop();
    cout << "after pop | top=" << stlS.top() << "\n";

    return 0;
}
