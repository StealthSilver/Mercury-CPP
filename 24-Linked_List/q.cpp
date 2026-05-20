// Question 1 — Intersection of two linked lists (Y-shaped merge)
// Time O(m + n), space O(1)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int length(Node* head) {
    int len = 0;
    while (head != nullptr) {
        len++;
        head = head->next;
    }
    return len;
}

Node* advance(Node* head, int steps) {
    while (head != nullptr && steps > 0) {
        head = head->next;
        steps--;
    }
    return head;
}

// Return first common node (merge point), or nullptr
Node* getIntersection(Node* headA, Node* headB) {
    int lenA = length(headA);
    int lenB = length(headB);

    Node* a = headA;
    Node* b = headB;

    if (lenA > lenB) {
        a = advance(a, lenA - lenB);
    } else {
        b = advance(b, lenB - lenA);
    }

    while (a != nullptr && b != nullptr) {
        if (a == b) {
            return a;
        }
        a = a->next;
        b = b->next;
    }

    return nullptr;
}

void printFrom(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Shared tail: 10 -> 15
    Node* shared = new Node{10, new Node{15, nullptr}};

    Node* headA = new Node{3, new Node{7, new Node{9, shared}}};
    Node* headB = new Node{99, shared};

    cout << "List A: ";
    printFrom(headA);
    cout << "List B: ";
    printFrom(headB);

    Node* meet = getIntersection(headA, headB);
    if (meet != nullptr) {
        cout << "Intersection at node with value: " << meet->data << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}
