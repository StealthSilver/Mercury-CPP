// MODULE 26 — Queue illustration (circular array, FIFO)

#include <iostream>
using namespace std;

const int CAPACITY = 8;

struct Queue {
    int data[CAPACITY];
    int front;  // index of first element
    int rear;   // index where next enqueue writes
    int count;

    Queue() : front(0), rear(0), count(0) {}

    bool empty() const { return count == 0; }
    bool full() const { return count == CAPACITY; }

    void enqueue(int x) {
        if (full()) {
            cout << "enqueue(" << x << ") ignored — queue full\n";
            return;
        }
        data[rear] = x;
        rear = (rear + 1) % CAPACITY;
        ++count;
    }

    void dequeue() {
        if (empty()) {
            cout << "dequeue() ignored — queue empty\n";
            return;
        }
        front = (front + 1) % CAPACITY;
        --count;
    }

    int frontValue() const {
        if (empty()) {
            cout << "frontValue() error — queue empty\n";
            return 0;
        }
        return data[front];
    }

    void printState(const char* label) const {
        cout << label << " | size=" << count << " | front -> rear: ";
        for (int i = 0; i < count; ++i) {
            int idx = (front + i) % CAPACITY;
            cout << data[idx];
            if (i + 1 < count) {
                cout << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    q.printState("start");

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printState("after enqueue 10, 20, 30");

    cout << "Front (peek): " << q.frontValue() << "  (first in line)\n";

    q.dequeue();
    q.printState("after one dequeue (10 removed; FIFO)");

    q.enqueue(40);
    q.printState("after enqueue 40");

    cout << "Front: " << q.frontValue() << "\n";

    return 0;
}
