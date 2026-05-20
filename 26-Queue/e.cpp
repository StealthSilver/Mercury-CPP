// MODULE 26 — Queue implemented with two stacks (inStack + outStack)

#include <iostream>
#include <stack>
using namespace std;

class QueueTwoStacks {
    stack<int> inStack;
    stack<int> outStack;

    void pourInToOut() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    bool empty() const { return inStack.empty() && outStack.empty(); }

    size_t size() const { return inStack.size() + outStack.size(); }

    void enqueue(int x) { inStack.push(x); }

    void dequeue() {
        if (empty()) {
            cout << "dequeue() ignored — queue empty\n";
            return;
        }
        if (outStack.empty()) {
            pourInToOut();
        }
        outStack.pop();
    }

    int front() {
        if (empty()) {
            cerr << "front() on empty queue\n";
            return 0;
        }
        if (outStack.empty()) {
            pourInToOut();
        }
        return outStack.top();
    }

    void printState(const char* label) const {
        cout << label << " | size=" << size();
        cout << " | inStack(top first): ";
        stack<int> inCopy = inStack;
        stack<int> inRev;
        while (!inCopy.empty()) {
            inRev.push(inCopy.top());
            inCopy.pop();
        }
        while (!inRev.empty()) {
            cout << inRev.top() << " ";
            inRev.pop();
        }
        cout << "| outStack(top first): ";
        stack<int> outCopy = outStack;
        stack<int> outRev;
        while (!outCopy.empty()) {
            outRev.push(outCopy.top());
            outCopy.pop();
        }
        while (!outRev.empty()) {
            cout << outRev.top() << " ";
            outRev.pop();
        }
        cout << "\n";
    }
};

int main() {
    QueueTwoStacks q;

    cout << "=== Queue using 2 stacks ===\n\n";

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printState("after enqueue 10, 20, 30");

    cout << "front(): " << q.front() << "  (pour in->out if needed)\n";
    q.printState("after front() peek");

    q.dequeue();
    q.printState("after dequeue (10 removed; FIFO)");

    q.enqueue(40);
    q.printState("after enqueue 40");

    cout << "front(): " << q.front() << "\n";

    while (!q.empty()) {
        cout << "dequeue -> " << q.front() << "\n";
        q.dequeue();
    }
    q.printState("drained");

    return 0;
}
