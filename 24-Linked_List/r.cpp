// Question 2 — Delete N nodes after every M nodes
// Time O(nodes), space O(1)

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

Node* deleteAfterM(Node* head, int m, int n) {
    Node dummy{0, head};
    Node* curr = &dummy;

    while (curr->next != nullptr) {
        for (int i = 0; i < m && curr->next != nullptr; i++) {
            curr = curr->next;
        }

        for (int j = 0; j < n && curr->next != nullptr; j++) {
            Node* toDelete = curr->next;
            curr->next = toDelete->next;
            delete toDelete;
        }
    }

    return dummy.next;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Node* head = buildList(arr, 12);

    int M = 2, N = 3;
    cout << "M=" << M << ", N=" << N << endl;
    cout << "Before: ";
    printList(head);

    head = deleteAfterM(head, M, N);
    cout << "After:  ";
    printList(head);

    freeList(head);
    return 0;
}
