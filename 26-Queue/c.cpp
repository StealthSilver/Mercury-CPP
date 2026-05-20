// MODULE 26 — Circular queue using a fixed-size array (wrap with modulo)

#include <iostream>
using namespace std;

const int CAPACITY = 5;

class CircularQueue {
    int data[CAPACITY];
    int frontIdx;
    int rearIdx;
    int count;

public:
    CircularQueue() : frontIdx(0), rearIdx(0), count(0) {}

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == CAPACITY; }

    bool enqueue(int x) {
        if (isFull()) {
            cout << "enqueue(" << x << ") failed — queue full\n";
            return false;
        }
        data[rearIdx] = x;
        rearIdx = (rearIdx + 1) % CAPACITY;
        ++count;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) {
            cout << "dequeue() failed — queue empty\n";
            return false;
        }
        frontIdx = (frontIdx + 1) % CAPACITY;
        --count;
        return true;
    }

    int front() const {
        if (isEmpty()) {
            cerr << "front() on empty queue\n";
            return 0;
        }
        return data[frontIdx];
    }

    int size() const { return count; }

    void printLogical(const char* label) const {
        cout << label << " | size=" << count << " | FIFO (front->rear): ";
        for (int i = 0; i < count; ++i) {
            cout << data[(frontIdx + i) % CAPACITY];
            if (i + 1 < count) {
                cout << " ";
            }
        }
        cout << "\n";
    }

    void printPhysical(const char* label) const {
        cout << label << " | physical array [0.." << CAPACITY - 1 << "]: ";
        for (int i = 0; i < CAPACITY; ++i) {
            cout << data[i];
            if (i + 1 < CAPACITY) {
                cout << " ";
            }
        }
        cout << " | frontIdx=" << frontIdx << " rearIdx=" << rearIdx << "\n";
    }
};

int main() {
    CircularQueue q;

    cout << "=== Circular queue (CAPACITY=" << CAPACITY << ") ===\n\n";

    for (int x = 1; x <= 5; ++x) {
        q.enqueue(x);
    }
    q.printLogical("after enqueue 1..5 (full)");
    q.printPhysical("");

    q.dequeue();
    q.dequeue();
    q.printLogical("after dequeue twice (removed 1, 2)");
    q.printPhysical("");

    q.enqueue(6);
    q.enqueue(7);
    q.printLogical("after enqueue 6, 7 (wrap — reuse slots 0, 1)");
    q.printPhysical("");

    cout << "front(): " << q.front() << "\n";

    return 0;
}
