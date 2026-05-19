// MODULE 25 — Stack implemented with a singly linked list (head = top)

#include <iostream>
using namespace std;

class Stack {
    struct Node {
        int data;
        Node* next;
        Node(int d, Node* n) : data(d), next(n) {}
    };

    Node* head;  // top of stack
    size_t n;

public:
    Stack() : head(nullptr), n(0) {}

    ~Stack() { clear(); }

    // Demo: no deep copy (would need to duplicate the whole list)
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    size_t size() const { return n; }

    bool empty() const { return head == nullptr; }

    void push(int x) {
        head = new Node(x, head);
        ++n;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* t = head;
        head = head->next;
        delete t;
        --n;
    }

    int top() const {
        if (head == nullptr) {
            cerr << "top() called on empty stack\n";
            return 0;
        }
        return head->data;
    }

    void clear() {
        while (!empty()) {
            pop();
        }
    }

    void print(const char* label) const {
        cout << label << " | size=" << n << " | top -> bottom: ";
        for (Node* p = head; p != nullptr; p = p->next) {
            cout << p->data;
            if (p->next != nullptr) {
                cout << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    s.print("start");

    s.push(1);
    s.push(2);
    s.push(3);
    s.print("after push 1, 2, 3");

    cout << "top(): " << s.top() << "\n\n";

    s.pop();
    s.print("after one pop");

    s.push(100);
    s.print("after push 100");

    while (!s.empty()) {
        cout << "pop -> " << s.top() << "\n";
        s.pop();
    }
    s.print("drained");

    return 0;
}
