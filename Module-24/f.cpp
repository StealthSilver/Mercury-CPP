// Module 24 — Practice: check if a linked list is a palindrome
// Approach: find middle, reverse second half, compare halves

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

Node* reverseSegment(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Returns true if values read forward and backward are the same
// Time O(n), extra space O(1)
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    // Step 1: slow/fast to reach middle (start of second half)
    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: reverse from slow->next onward
    Node* secondHalf = reverseSegment(slow->next);
    slow->next = nullptr;

    // Step 3: compare first half vs reversed second half
    Node* p1 = head;
    Node* p2 = secondHalf;
    bool result = true;

    while (p2 != nullptr) {
        if (p1->data != p2->data) {
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    freeList(secondHalf);
    return result;
}

int main() {
    int a1[] = {1, 2, 2, 1};
    Node* head1 = buildList(a1, 4);
    cout << "List: ";
    printList(head1);
    cout << "Is palindrome? " << (isPalindrome(head1) ? "true" : "false") << endl;
    freeList(head1);

    int a2[] = {1, 2};
    Node* head2 = buildList(a2, 2);
    cout << "\nList: ";
    printList(head2);
    cout << "Is palindrome? " << (isPalindrome(head2) ? "true" : "false") << endl;
    freeList(head2);

    return 0;
}
