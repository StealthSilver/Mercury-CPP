// Module 24 — Iterative search on a simple linked list (no List class)
// List is built manually in main; searchItr is a standalone function

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Iterative search from head: return index if found, else -1
int searchItr(Node* head, int key) {
    Node* temp = head;
    int index = 0;

    while (temp != nullptr) {
        if (temp->data == key) {
            return index;
        }
        temp = temp->next;
        index++;
    }

    return -1;
}

int main() {
    // Build linked list: 10 -> 20 -> 30 -> 40 -> NULL
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};

    int key = 30;
    int idx = searchItr(head, key);
    if (idx != -1) {
        cout << key << " found at index " << idx << endl;
    } else {
        cout << key << " not found" << endl;
    }

    key = 99;
    idx = searchItr(head, key);
    if (idx != -1) {
        cout << key << " found at index " << idx << endl;
    } else {
        cout << key << " not found" << endl;
    }

    // Free all nodes
    while (head != nullptr) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    return 0;
}
