// Module 24 — Zig-zag (reorder) linked list
// L1 -> L2 -> ... -> Ln  becomes  L1 -> Ln -> L2 -> L(n-1) -> ...

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

// Split into two halves (same as l.cpp)
Node* split(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* right = slow->next;
    slow->next = nullptr;
    return right;
}

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Reorder in zig-zag form in place
// Time O(n), extra space O(1)
void reorderZigZag(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // Step 1: split into first half and second half
    Node* second = split(head);

    // Step 2: reverse second half (so we can pick from the "end" easily)
    second = reverseList(second);

    // Step 3: merge alternately: first -> second -> first -> second -> ...
    Node* first = head;
    while (second != nullptr) {
        Node* nextFirst = first->next;
        Node* nextSecond = second->next;

        first->next = second;
        second->next = nextFirst;

        first = nextFirst;
        second = nextSecond;
    }
}

int main() {
    int odd[] = {1, 2, 3, 4, 5};
    Node* head1 = buildList(odd, 5);
    cout << "Odd length before:  ";
    printList(head1);
    reorderZigZag(head1);
    cout << "Odd length after:   ";
    printList(head1);
    freeList(head1);

    int even[] = {1, 2, 3, 4};
    Node* head2 = buildList(even, 4);
    cout << "\nEven length before: ";
    printList(head2);
    reorderZigZag(head2);
    cout << "Even length after:  ";
    printList(head2);
    freeList(head2);

    return 0;
}
