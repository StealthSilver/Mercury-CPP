// MODULE 30 — STL priority_queue: push / pop / top, max-heap vs min-heap

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void demoMaxHeap() {
    cout << "MAX-HEAP (priority_queue<int> pq)\n";
    cout << "--------------------------------\n";
    cout << "Rule: parent >= children → largest at top\n\n";

    priority_queue<int> pq;

    cout << "push(5)  push(1)  push(9)  push(3)  push(7)  [each O(log n)]\n";
    for (int x : {5, 1, 9, 3, 7}) {
        pq.push(x);
    }

    cout << "top() = " << pq.top() << "  [O(1)]\n\n";
    cout << "pop order (top + pop each O(log n)):\n   ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n\n";
}

void demoMinHeap() {
    cout << "MIN-HEAP (priority_queue<int, vector<int>, greater<int>>)\n";
    cout << "--------------------------------------------------------\n";
    cout << "Rule: parent <= children → smallest at top\n\n";

    priority_queue<int, vector<int>, greater<int>> pq;

    cout << "push(5)  push(1)  push(9)  push(3)  push(7)\n";
    for (int x : {5, 1, 9, 3, 7}) {
        pq.push(x);
    }

    cout << "top() = " << pq.top() << "  [O(1)]\n\n";
    cout << "pop order:\n   ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n\n";
}

void demoOperations() {
    cout << "STL API recap\n";
    cout << "-------------\n";
    priority_queue<int> pq;
    pq.push(20);
    pq.push(5);
    cout << "size()  = " << pq.size() << "  [O(1)]\n";
    cout << "empty() = " << (pq.empty() ? "true" : "false") << "  [O(1)]\n";
    cout << "top()   = " << pq.top() << "  [O(1)] before pop\n";
    pq.pop();
    cout << "after pop(), top() = " << pq.top() << "\n\n";
}

int main() {
    cout << "Module 30 — PQ in STL (b.cpp)\n";
    cout << "==============================\n\n";

    demoOperations();
    demoMaxHeap();
    demoMinHeap();

    cout << "Remember: default = max-heap | greater<int> = min-heap\n";

    return 0;
}
