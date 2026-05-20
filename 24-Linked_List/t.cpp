// Question 4 — Odd-even linked list (evens before odds, stable order)
// Time O(n), space O(1)

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
        Node* t = head;
        head = head->next;
        delete t;
    }
}

Node* oddEvenList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node evenDummy{0, nullptr};
    Node oddDummy{0, nullptr};
    Node* evenTail = &evenDummy;
    Node* oddTail = &oddDummy;

    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data % 2 == 0) {
            evenTail->next = curr;
            evenTail = curr;
        } else {
            oddTail->next = curr;
            oddTail = curr;
        }
        curr = curr->next;
    }

    evenTail->next = oddDummy.next;
    oddTail->next = nullptr;

    return evenDummy.next;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* head = buildList(arr, 8);

    cout << "Before: ";
    printList(head);

    head = oddEvenList(head);
    cout << "After:  ";
    printList(head);

    freeList(head);
    return 0;
}
