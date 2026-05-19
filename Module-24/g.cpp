
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head, int maxNodes = 20) {
    Node* temp = head;
    int count = 0;
    while (temp != nullptr && count < maxNodes) {
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    if (count == maxNodes) {
        cout << "...";
    }
    cout << "NULL" << endl;
}

// Floyd's cycle detection (tortoise and hare)
// Returns true if the list has a cycle
// Time O(n), extra space O(1)
bool hasCycle(Node* head) {
    if (head == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // +1 step
        fast = fast->next->next;     // +2 steps

        if (slow == fast) {
            return true;
        }
    }

    return false;  // fast reached end → no cycle
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

int main() {
    // Acyclic list: 1 -> 2 -> 3 -> NULL
    Node* head1 = new Node{1, nullptr};
    head1->next = new Node{2, nullptr};
    head1->next->next = new Node{3, nullptr};

    cout << "Acyclic list: ";
    printList(head1);
    cout << "Has cycle? " << (hasCycle(head1) ? "true" : "false") << endl << endl;

    freeList(head1);

    // Cyclic list: 1 -> 2 -> 3 -> 4 -> back to 2
    Node* n1 = new Node{1, nullptr};
    Node* n2 = new Node{2, nullptr};
    Node* n3 = new Node{3, nullptr};
    Node* n4 = new Node{4, nullptr};
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;  // cycle

    Node* head2 = n1;
    cout << "Cyclic list (1->2->3->4->2...): ";
    printList(head2, 8);
    cout << "Has cycle? " << (hasCycle(head2) ? "true" : "false") << endl;

    n4->next = nullptr;  // break cycle before freeing
    freeList(head2);

    return 0;
}
