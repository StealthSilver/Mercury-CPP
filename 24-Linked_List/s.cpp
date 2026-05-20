// Question 3 — Swap two nodes by changing links (keys are distinct)
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

void swapNodes(Node*& head, int key1, int key2) {
    if (key1 == key2) {
        return;
    }

    Node* prev1 = nullptr;
    Node* node1 = head;
    while (node1 != nullptr && node1->data != key1) {
        prev1 = node1;
        node1 = node1->next;
    }

    Node* prev2 = nullptr;
    Node* node2 = head;
    while (node2 != nullptr && node2->data != key2) {
        prev2 = node2;
        node2 = node2->next;
    }

    if (node1 == nullptr || node2 == nullptr) {
        return;
    }

    if (prev1 != nullptr) {
        prev1->next = node2;
    } else {
        head = node2;
    }

    if (prev2 != nullptr) {
        prev2->next = node1;
    } else {
        head = node1;
    }

    if (node1->next == node2) {
        node1->next = node2->next;
        node2->next = node1;
    } else if (node2->next == node1) {
        node2->next = node1->next;
        node1->next = node2;
    } else {
        Node* temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    Node* head = buildList(arr, 4);

    cout << "Before swap(1, 4): ";
    printList(head);
    swapNodes(head, 1, 4);
    cout << "After:  ";
    printList(head);

    freeList(head);
    return 0;
}
