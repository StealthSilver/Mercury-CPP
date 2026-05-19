// MODULE 26 — Queue with singly linked list (front + rear, all ops O(1))

#include <iostream>
using namespace std;

class Queue {
    struct Node {
        int data;
        Node* next;
        Node(int d) : data(d), next(nullptr) {}
    };

    Node* frontPtr;
    Node* rearPtr;
    size_t n;

public:
    Queue() : frontPtr(nullptr), rearPtr(nullptr), n(0) {}

    ~Queue() { clear(); }

    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    bool empty() const { return frontPtr == nullptr; }

    size_t size() const { return n; }

    // enqueue / push — add at rear, O(1)
    void enqueue(int x) {
        Node* node = new Node(x);
        if (rearPtr == nullptr) {
            frontPtr = rearPtr = node;
        } else {
            rearPtr->next = node;
            rearPtr = node;
        }
        ++n;
    }

    void push(int x) { enqueue(x); }

    // dequeue / pop — remove from front, O(1)
    void dequeue() {
        if (frontPtr == nullptr) {
            cout << "dequeue() ignored — queue empty\n";
            return;
        }
        Node* t = frontPtr;
        frontPtr = frontPtr->next;
        if (frontPtr == nullptr) {
            rearPtr = nullptr;
        }
        delete t;
        --n;
    }

    void pop() { dequeue(); }

    // front — peek first element, O(1)
    int front() const {
        if (frontPtr == nullptr) {
            cerr << "front() called on empty queue\n";
            return 0;
        }
        return frontPtr->data;
    }

    void clear() {
        while (!empty()) {
            dequeue();
        }
    }

    void printState(const char* label) const {
        cout << label << " | size=" << n << " | front -> rear: ";
        for (Node* p = frontPtr; p != nullptr; p = p->next) {
            cout << p->data;
            if (p->next != nullptr) {
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

    cout << "front(): " << q.front() << "\n";

    q.dequeue();
    q.printState("after dequeue (10 removed; FIFO)");

    q.push(40);
    q.printState("after push(40) — same as enqueue at rear");

    cout << "front(): " << q.front() << "\n";

    q.pop();
    q.printState("after pop() — same as dequeue from front");

    return 0;
}
