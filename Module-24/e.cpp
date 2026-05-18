// Module 24 — Remove the Nth node from the end (two-pointer technique)
// Same style as b/d: struct Node, list built in main, standalone function

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

// Remove the nth node from the end (1-indexed: n=1 means last node)
// Time O(L), extra space O(1) — L = length of list
void removeNthFromEnd(Node*& head, int n) {
    if (head == nullptr) {
        return;
    }

    // Dummy node simplifies removing the head (when n == list length)
    Node dummy{0, head};
    Node* fast = &dummy;
    Node* slow = &dummy;

    // Move fast (n + 1) steps ahead of slow
    for (int i = 0; i <= n; i++) {
        if (fast == nullptr) {
            return;  // n is larger than list length
        }
        fast = fast->next;
    }

    // Move both until fast reaches the end
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    // slow is just before the node to remove
    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    head = dummy.next;
}

int main() {
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};

    cout << "Original: ";
    printList(head);  // 10 -> 20 -> 30 -> 40 -> NULL

    int n = 2;  // remove 2nd from end → node 30
    removeNthFromEnd(head, n);
    cout << "After removing " << n << "th from end: ";
    printList(head);  // 10 -> 20 -> 40 -> NULL

    n = 1;  // remove last node → 40
    removeNthFromEnd(head, n);
    cout << "After removing " << n << "th from end: ";
    printList(head);  // 10 -> 20 -> NULL

    while (head != nullptr) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    return 0;
}
