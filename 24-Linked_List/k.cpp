// Module 24 — Find the middle of a linked list (slow / fast pointers)
// Same technique as finding middle in f.cpp (palindrome)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* buildList(int arr[], int n) {
    if (n == 0) {
        return nullptr;
    }
    Node* head = new Node{arr[0], nullptr};
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        tail->next = new Node{arr[i], nullptr};
        tail = tail->next;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

// Slow moves +1, fast moves +2; when fast cannot continue, slow is at middle
// Even length → returns second middle (e.g. 1->2->3->4 → node 3)
// Time O(n), space O(1)
Node* findMiddle(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    int odd[] = {1, 2, 3, 4, 5};
    Node* head1 = buildList(odd, 5);
    cout << "Odd length:  ";
    printList(head1);
    cout << "Middle node: " << findMiddle(head1)->data << endl << endl;

    int even[] = {1, 2, 3, 4};
    Node* head2 = buildList(even, 4);
    cout << "Even length: ";
    printList(head2);
    cout << "Middle node (2nd of two middles): " << findMiddle(head2)->data << endl;

    freeList(head1);
    freeList(head2);
    return 0;
}
