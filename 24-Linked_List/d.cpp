// Module 24 — Reverse a singly linked list in place (focused demo)
// Same style as b.cpp / c.cpp: struct Node, list in main, standalone reverseList

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Reverse in place: rewire next pointers only (no new nodes)
// Time O(n), extra space O(1)
void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

int main() {
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};

    cout << "Before: ";
    printList(head);  // 10 -> 20 -> 30 -> 40 -> NULL

    reverseList(head);

    cout << "After:  ";
    printList(head);  // 40 -> 30 -> 20 -> 10 -> NULL

    while (head != nullptr) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    return 0;
}
