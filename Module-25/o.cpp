// MODULE 25 — Problem 1: Palindrome linked list (slow/fast + reverse half)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* buildList(const int arr[], int n) {
    if (n == 0) {
        return nullptr;
    }
    Node* head = new Node{arr[0], nullptr};
    Node* tail = head;
    for (int i = 1; i < n; ++i) {
        tail->next = new Node{arr[i], nullptr};
        tail = tail->next;
    }
    return head;
}

void freeList(Node* head) {
    while (head) {
        Node* t = head;
        head = head->next;
        delete t;
    }
}

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    while (head) {
        Node* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next) {
        return true;
    }

    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = reverseList(slow->next);
    slow->next = nullptr;

    Node* p1 = head;
    Node* p2 = second;
    bool ok = true;
    while (p2) {
        if (p1->data != p2->data) {
            ok = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    slow->next = reverseList(second);
    return ok;
}

int main() {
    struct Case {
        int arr[8];
        int n;
        bool expect;
    };

    Case tests[] = {
        {{1, 2, 2, 1}, 4, true},
        {{1, 2}, 2, false},
        {{1}, 1, true},
        {{1, 2, 3, 2, 1}, 5, true},
    };

    cout << "Palindrome linked list\n\n";
    for (const Case& t : tests) {
        Node* head = buildList(t.arr, t.n);
        bool got = isPalindrome(head);
        cout << "list: ";
        for (int i = 0; i < t.n; ++i) {
            cout << t.arr[i] << (i + 1 < t.n ? " -> " : "");
        }
        cout << " => " << (got ? "true" : "false");
        cout << (got == t.expect ? "  OK\n" : "  FAIL\n");
        freeList(head);
    }

    return 0;
}
