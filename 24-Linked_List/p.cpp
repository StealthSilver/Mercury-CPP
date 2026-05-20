// Module 24 — Doubly linked list (DLL)
// Each node has prev and next — O(1) pop_back vs singly linked a.cpp

#include <iostream>
using namespace std;

// =============================================================================
// Node — data + previous + next
// =============================================================================
class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// =============================================================================
// DoublyList — head and tail (like List in a.cpp, but with prev links)
// =============================================================================
class DoublyList {
    DNode* head;
    DNode* tail;

public:
    DoublyList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyList() {
        while (head != nullptr) {
            DNode* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        tail = nullptr;
    }

    // -------------------------------------------------------------------------
    // push_front — insert before head  |  O(1)
    // -------------------------------------------------------------------------
    void push_front(int val) {
        DNode* newNode = new DNode(val);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // -------------------------------------------------------------------------
    // push_back — insert after tail  |  O(1)
    // -------------------------------------------------------------------------
    void push_back(int val) {
        DNode* newNode = new DNode(val);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // -------------------------------------------------------------------------
    // pop_front — remove head  |  O(1)
    // -------------------------------------------------------------------------
    void pop_front() {
        if (head == nullptr) {
            return;
        }

        DNode* toDelete = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete toDelete;
    }

    // -------------------------------------------------------------------------
    // pop_back — remove tail  |  O(1) using prev (singly linked needs O(n))
    // -------------------------------------------------------------------------
    void pop_back() {
        if (tail == nullptr) {
            return;
        }

        DNode* toDelete = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete toDelete;
    }

    // -------------------------------------------------------------------------
    // insert — at index pos (0-based)  |  O(pos)
    // -------------------------------------------------------------------------
    void insert(int val, int pos) {
        if (pos <= 0) {
            push_front(val);
            return;
        }

        if (head == nullptr) {
            push_front(val);
            return;
        }

        DNode* temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            push_back(val);
            return;
        }

        if (temp->next == nullptr) {
            push_back(val);
            return;
        }

        DNode* newNode = new DNode(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // -------------------------------------------------------------------------
    // removeAt — delete node at index pos (0-based)  |  O(pos)
    // -------------------------------------------------------------------------
    void removeAt(int pos) {
        if (head == nullptr) {
            return;
        }

        if (pos <= 0) {
            pop_front();
            return;
        }

        DNode* temp = head;
        for (int i = 0; i < pos && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            return;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }

        delete temp;
    }

    void displayForward() const {
        cout << "Forward:  ";
        DNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "END" << endl;
    }

    void displayBackward() const {
        cout << "Backward: ";
        DNode* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "END" << endl;
    }
};

// =============================================================================
// main — demo all DLL operations
// =============================================================================
int main() {
    DoublyList list;

    list.push_back(20);
    list.push_back(30);
    list.push_front(10);
    list.displayForward();
    list.displayBackward();

    list.insert(15, 1);
    list.displayForward();

    list.pop_front();
    list.pop_back();
    list.displayForward();

    list.removeAt(1);
    list.displayForward();

    return 0;
}
