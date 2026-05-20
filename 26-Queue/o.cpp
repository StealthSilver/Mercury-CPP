// MODULE 26 — Problem 3: Reverse first K elements of a queue (stack helper)

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void reverseFirstK(queue<int>& q, int k) {
    if (k <= 0 || q.empty()) {
        return;
    }
    k = min(k, static_cast<int>(q.size()));

    stack<int> st;
    queue<int> rest;

    for (int i = 0; i < k; ++i) {
        st.push(q.front());
        q.pop();
    }
    while (!q.empty()) {
        rest.push(q.front());
        q.pop();
    }
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    while (!rest.empty()) {
        q.push(rest.front());
        rest.pop();
    }
}

static void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

int main() {
    queue<int> q;
    for (int x : {1, 2, 3, 4, 5}) {
        q.push(x);
    }
    int k = 3;

    cout << "Reverse first K in queue\n\n";
    cout << "before (K=" << k << "): ";
    queue<int> copy = q;
    printQueue(copy);

    reverseFirstK(q, k);

    cout << "after:  ";
    printQueue(q);
    cout << "expected: 3 2 1 4 5\n";

    return 0;
}
