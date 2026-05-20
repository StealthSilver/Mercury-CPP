// Module 24 — Alternate merging of two linked lists (zig-zag weave step)
// Used as Step 3 in n.cpp after split + reverse

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

// Weave: L1 -> L2 -> L1 -> L2 -> ... (not sorted merge — strict alternation)
// first list head is returned; both lists consumed into one chain
// Time O(n + m), extra space O(1)
Node* alternateMerge(Node* first, Node* second) {
    if (first == nullptr) {
        return second;
    }
    if (second == nullptr) {
        return first;
    }

    Node* head = first;

    while (second != nullptr) {
        Node* nextFirst = first->next;
        Node* nextSecond = second->next;

        first->next = second;
        second->next = nextFirst;

        first = nextFirst;
        second = nextSecond;
    }

    return head;
}

int main() {
    // Simulate zig-zag setup: first half + reversed second half
    int half1[] = {1, 2, 3};
    int half2[] = {5, 4};  // already reversed tail half of 1->2->3->4->5

    Node* list1 = buildList(half1, 3);
    Node* list2 = buildList(half2, 2);

    printList(list1, "First half:  ");
    printList(list2, "Second half: ");

    Node* zigzag = alternateMerge(list1, list2);
    printList(zigzag, "After alternate merge: ");

    freeList(zigzag);
    return 0;
}
