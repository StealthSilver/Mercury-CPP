// MODULE 26 — Stack implemented with two queues (mainQ + helperQ)

#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> mainQ;
    queue<int> helperQ;

    void pourMainToHelper() {
        while (!mainQ.empty()) {
            helperQ.push(mainQ.front());
            mainQ.pop();
        }
    }

public:
    bool empty() const { return mainQ.empty() && helperQ.empty(); }

    size_t size() const { return mainQ.size() + helperQ.size(); }

    // O(n) — new element becomes front of mainQ after pour + swap
    void push(int x) {
        helperQ.push(x);
        pourMainToHelper();
        swap(mainQ, helperQ);
    }

    // O(1)
    void pop() {
        if (mainQ.empty()) {
            cout << "pop() ignored — stack empty\n";
            return;
        }
        mainQ.pop();
    }

    // O(1) — top is always at front of mainQ
    int top() const {
        if (mainQ.empty()) {
            cerr << "top() on empty stack\n";
            return 0;
        }
        return mainQ.front();
    }

    void printState(const char* label) const {
        cout << label << " | size=" << size();
        cout << " | mainQ(front=top): ";
        queue<int> copy = mainQ;
        while (!copy.empty()) {
            cout << copy.front() << " ";
            copy.pop();
        }
        cout << "| helperQ: ";
        copy = helperQ;
        while (!copy.empty()) {
            cout << copy.front() << " ";
            copy.pop();
        }
        cout << "\n";
    }
};

int main() {
    StackTwoQueues st;

    cout << "=== Stack using 2 queues ===\n\n";

    st.push(10);
    st.push(20);
    st.push(30);
    st.printState("after push 10, 20, 30");

    cout << "top(): " << st.top() << "  (front of mainQ)\n\n";

    st.pop();
    st.printState("after pop (30 removed; LIFO)");

    st.push(40);
    st.printState("after push 40");

    cout << "top(): " << st.top() << "\n";

    while (!st.empty()) {
        cout << "pop -> " << st.top() << "\n";
        st.pop();
    }
    st.printState("drained");

    return 0;
}
