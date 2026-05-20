// Module 24 — Remove a cycle from a linked list (Floyd: detect + find entrance)
// Builds on g.cpp cycle detection

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

// Phase 1 + 2: return pointer to cycle entrance, or nullptr if no cycle
// Time O(n), space O(1)
Node* findCycleEntrance(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;  // no cycle
    }

    // Phase 2: entrance is where slow (from head) meets fast (from collision point)
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Break the cycle so the list ends at nullptr
void removeCycle(Node* head) {
    Node* entrance = findCycleEntrance(head);
    if (entrance == nullptr) {
        return;
    }

    Node* curr = entrance;
    while (curr->next != entrance) {
        curr = curr->next;
    }
    curr->next = nullptr;
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

int main() {
    // Cyclic: 1 -> 2 -> 3 -> 4 -> back to 2
    Node* n1 = new Node{1, nullptr};
    Node* n2 = new Node{2, nullptr};
    Node* n3 = new Node{3, nullptr};
    Node* n4 = new Node{4, nullptr};
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    Node* head = n1;

    cout << "Before remove (cycle): ";
    printList(head, 10);
    cout << "Cycle entrance data: " << findCycleEntrance(head)->data << endl;

    removeCycle(head);

    cout << "After remove (acyclic): ";
    printList(head);
    cout << "Has cycle now? " << (findCycleEntrance(head) ? "yes" : "no") << endl;

    freeList(head);
    return 0;
}
