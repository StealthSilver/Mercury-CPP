// Module 24 — Merge sort on a linked list
// Split with slow/fast, recursively sort halves, merge two sorted lists

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

// Split list into two halves; return head of right half, left stays as head
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

    Node* rightHead = slow->next;
    slow->next = nullptr;
    return rightHead;
}

// Merge two sorted lists into one sorted list
Node* merge(Node* a, Node* b) {
    Node dummy{0, nullptr};
    Node* tail = &dummy;

    while (a != nullptr && b != nullptr) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    tail->next = (a != nullptr) ? a : b;
    return dummy.next;
}

// Merge sort: divide (split), conquer (recurse), combine (merge)
// Time O(n log n), space O(log n) recursion stack
Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* right = split(head);
    head = mergeSort(head);
    right = mergeSort(right);
    return merge(head, right);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = buildList(arr, n);

    cout << "Before: ";
    printList(head);

    head = mergeSort(head);

    cout << "After:  ";
    printList(head);

    freeList(head);
    return 0;
}
