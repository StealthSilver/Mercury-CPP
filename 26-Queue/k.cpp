// MODULE 26 — Queue implemented with std::deque (FIFO)

#include <deque>
#include <iostream>
#include <queue>
using namespace std;

class QueueDeque {
    deque<int> d;

public:
    bool empty() const { return d.empty(); }
    size_t size() const { return d.size(); }

    void enqueue(int x) { d.push_back(x); }
    void dequeue() {
        if (!d.empty()) {
            d.pop_front();
        }
    }
    int front() const { return d.front(); }

    void print(const char* label) const {
        cout << label << " | size=" << d.size() << " | front -> back: ";
        for (size_t i = 0; i < d.size(); ++i) {
            cout << d[i];
            if (i + 1 < d.size()) {
                cout << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    cout << "=== Queue using deque ===\n\n";

    QueueDeque q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print("after enqueue 10, 20, 30");
    cout << "front(): " << q.front() << "\n";

    q.dequeue();
    q.print("after dequeue (FIFO removes 10)");

    q.enqueue(40);
    q.print("after enqueue 40");

    cout << "\n--- STL adapter: queue<int, deque<int>> ---\n";
    queue<int, deque<int>> stlQ;
    stlQ.push(1);
    stlQ.push(2);
    cout << "push 1,2 | front=" << stlQ.front() << " back=" << stlQ.back() << "\n";
    stlQ.pop();
    cout << "after pop | front=" << stlQ.front() << "\n";

    return 0;
}
