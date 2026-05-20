
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Recursive search: check current node, then trust search on rest of list
// Returns 0-based index if found, else -1
int searchRec(Node* head, int key, int index = 0) {
    if (head == nullptr) {
        return -1;  // base case: reached end — not found
    }

    if (head->data == key) {
        return index;  // base case: found at current index
    }

    return searchRec(head->next, key, index + 1);
}

int main() {
    // Build linked list: 10 -> 20 -> 30 -> 40 -> NULL
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};

    int key = 30;
    int idx = searchRec(head, key);
    if (idx != -1) {
        cout << key << " found at index " << idx << endl;
    } else {
        cout << key << " not found" << endl;
    }

    key = 99;
    idx = searchRec(head, key);
    if (idx != -1) {
        cout << key << " found at index " << idx << endl;
    } else {
        cout << key << " not found" << endl;
    }

    while (head != nullptr) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    return 0;
}
