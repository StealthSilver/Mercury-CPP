// Module 24 — Merge two sorted linked lists
// Same merge step used inside merge sort in l.cpp

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

void printList(Node* head, const string& label) {
    cout << label;
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

// Merge two sorted lists; return head of merged sorted list
// Time O(n + m), space O(1) extra (dummy node on stack)
Node* mergeTwoSorted(Node* a, Node* b) {
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

int main() {
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};

    Node* list1 = buildList(arr1, 3);
    Node* list2 = buildList(arr2, 3);

    printList(list1, "List 1: ");
    printList(list2, "List 2: ");

    Node* merged = mergeTwoSorted(list1, list2);
    printList(merged, "Merged: ");

    freeList(merged);
    return 0;
}
