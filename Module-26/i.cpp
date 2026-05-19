// MODULE 26 — Queue reversal using a stack

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void printQueue(queue<int> q) {
    cout << "front -> rear: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

void reverseQueue(queue<int>& q) {
    stack<int> st;
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

int main() {
    queue<int> q;
    for (int x : {1, 2, 3, 4, 5}) {
        q.push(x);
    }

    cout << "Queue reversal\n\n";
    cout << "Before: ";
    printQueue(q);

    reverseQueue(q);

    cout << "After:  ";
    printQueue(q);
    cout << "expected: 5 4 3 2 1\n";

    return 0;
}
