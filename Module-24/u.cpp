// Question 5 — Merge k sorted linked lists
// Min-heap approach: Time O(N*k*log k), space O(k)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
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
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
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

Node* mergeKSorted(vector<Node*>& lists) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (Node* head : lists) {
        if (head != nullptr) {
            minHeap.push(head);
        }
    }

    Node dummy{0, nullptr};
    Node* tail = &dummy;

    while (!minHeap.empty()) {
        Node* smallest = minHeap.top();
        minHeap.pop();

        tail->next = smallest;
        tail = tail->next;

        if (smallest->next != nullptr) {
            minHeap.push(smallest->next);
        }
    }

    return dummy.next;
}

int main() {
    int a1[] = {1, 4, 7};
    int a2[] = {2, 5, 8};
    int a3[] = {3, 6, 9};

    vector<Node*> lists;
    lists.push_back(buildList(a1, 3));
    lists.push_back(buildList(a2, 3));
    lists.push_back(buildList(a3, 3));

    cout << "List 0: ";
    printList(lists[0]);
    cout << "List 1: ";
    printList(lists[1]);
    cout << "List 2: ";
    printList(lists[2]);

    Node* merged = mergeKSorted(lists);
    cout << "Merged: ";
    printList(merged);

    freeList(merged);
    return 0;
}
