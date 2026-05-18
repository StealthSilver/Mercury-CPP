// Module 24 — Singly linked list (complete reference implementation)
// Classes : Node, List
// List API  : push_front, push_back, insert, removeAt, display
// Lifecycle : List() constructor, ~List() destructor

#include <iostream>
using namespace std;

// =============================================================================
// Node — one unit of the list (data + link to next)
// =============================================================================
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// =============================================================================
// List — manages head/tail and all operations on the chain
// =============================================================================
class List {
    Node* head;
    Node* tail;

public:
    // -------------------------------------------------------------------------
    // Constructor / destructor
    // -------------------------------------------------------------------------

    List() {
        head = nullptr;
        tail = nullptr;
    }

    // Free every node when the List object is destroyed (end of main, etc.)
    ~List() {
        while (head != nullptr) {
            Node* toDelete = head;
            head = head->next;   // -> : access member through pointer
            delete toDelete;
        }
        tail = nullptr;
    }

    // -------------------------------------------------------------------------
    // push_front — insert at the beginning  |  O(1)
    // -------------------------------------------------------------------------
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // -------------------------------------------------------------------------
    // push_back — insert at the end  |  O(1) with tail pointer
    // -------------------------------------------------------------------------
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // -------------------------------------------------------------------------
    // insert — insert at index pos (0-based)  |  O(pos)
    // pos == 0  → same as push_front
    // pos == size → same as push_back
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

        // Step 2: walk to node at index (pos - 1)
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == nullptr) {
                return;
            }
            temp = temp->next;
        }

        if (temp == nullptr) {
            return;
        }

        if (temp->next == nullptr) {
            push_back(val);
            return;
        }

        // Step 1: create newNode
        // Step 3a & 3b: link new node between temp and temp->next
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // -------------------------------------------------------------------------
    // removeAt — remove node at index pos (0-based)  |  O(pos)
    // Cannot name this "delete" — reserved C++ keyword
    // -------------------------------------------------------------------------
    void removeAt(int pos) {
        if (head == nullptr) {
            return;
        }

        if (pos <= 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            if (head == nullptr) {
                tail = nullptr;
            }
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == nullptr || temp->next == nullptr) {
                return;
            }
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;

        if (toDelete == tail) {
            tail = temp;
        }

        delete toDelete;
    }

    // -------------------------------------------------------------------------
    // display — traverse from head; uses temp->data and temp->next
    // -------------------------------------------------------------------------
    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// =============================================================================
// main — demo every operation (see notes.md for step-by-step traces)
// =============================================================================
int main() {
    List linkedList;  // not List linkedList(); — function declaration, not an object

    linkedList.push_front(30);
    linkedList.push_front(20);
    linkedList.push_front(10);
    linkedList.display();  // 10 -> 20 -> 30 -> NULL

    linkedList.push_back(40);
    linkedList.push_back(50);
    linkedList.display();  // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    linkedList.insert(15, 1);
    linkedList.display();  // 10 -> 15 -> 20 -> 30 -> 40 -> 50 -> NULL

    linkedList.removeAt(2);
    linkedList.display();  // 10 -> 15 -> 30 -> 40 -> 50 -> NULL

    // linkedList goes out of scope here → ~List() deletes all remaining nodes
    return 0;
}
