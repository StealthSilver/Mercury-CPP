#include <iostream>
using namespace std;

// One node: value + link to the next node
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Singly linked list with head and tail pointers
class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the front (new node becomes head)
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

    // Insert at the back (new node becomes tail)
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

    // Insert at index pos (0-based: 0 = front, size = append at end)
    void insert(int val, int pos) {
        if (pos <= 0) {
            push_front(val);
            return;
        }

        if (head == nullptr) {
            push_front(val);
            return;
        }

        // Walk to the node just before the insertion index
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == nullptr) {
                return;  // pos out of range
            }
            temp = temp->next;
        }

        if (temp == nullptr) {
            return;
        }

        // Inserting after the last node — same as push_back
        if (temp->next == nullptr) {
            push_back(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Remove node at index pos (0-based); cannot use name "delete" — C++ keyword
    void removeAt(int pos) {
        if (head == nullptr) {
            return;
        }

        // Case 1: remove the first node
        if (pos <= 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            if (head == nullptr) {
                tail = nullptr;
            }
            return;
        }

        // Case 2: find node before the one to remove
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == nullptr || temp->next == nullptr) {
                return;  // pos out of range
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

    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    List linkedList;

    linkedList.push_front(30);
    linkedList.push_front(20);
    linkedList.push_front(10);
    linkedList.display();  // 10 -> 20 -> 30 -> NULL

    linkedList.push_back(40);
    linkedList.push_back(50);
    linkedList.display();  // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    linkedList.insert(15, 1);  // insert 15 at index 1
    linkedList.display();      // 10 -> 15 -> 20 -> 30 -> 40 -> 50 -> NULL

    linkedList.removeAt(2);    // remove node at index 2 (value 20)
    linkedList.display();      // 10 -> 15 -> 30 -> 40 -> 50 -> NULL

    return 0;
}
