// MODULE 29 — Problem 4: Two BST sum to target (LeetCode 653)

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(Node* root, vector<int>& out) {
    if (!root) {
        return;
    }
    inorder(root->left, out);
    out.push_back(root->data);
    inorder(root->right, out);
}

bool findTarget(Node* root1, Node* root2, int target) {
    vector<int> a, b;
    inorder(root1, a);
    inorder(root2, b);

    int i = 0;
    int j = static_cast<int>(b.size()) - 1;

    cout << "  A: ";
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n  B: ";
    for (int x : b) {
        cout << x << " ";
    }
    cout << "\n  Two pointers i=0, j=end:\n";

    while (i < static_cast<int>(a.size()) && j >= 0) {
        int sum = a[i] + b[j];
        cout << "    A[" << i << "]+B[" << j << "] = " << a[i] << "+" << b[j]
             << " = " << sum << "\n";
        if (sum == target) {
            return true;
        }
        if (sum < target) {
            ++i;
        } else {
            --j;
        }
    }
    return false;
}

void freeTree(Node* root) {
    if (!root) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    cout << "Problem 4: Two BST sum to target\n";
    cout << "================================\n\n";

    Node* t1 = nullptr;
    for (int x : {2, 1, 3}) {
        t1 = insert(t1, x);
    }
    Node* t2 = nullptr;
    for (int x : {7, 5, 9}) {
        t2 = insert(t2, x);
    }

    cout << "target = 12:\n";
    bool ok = findTarget(t1, t2, 12);
    cout << "Result: " << (ok ? "true (3+9)" : "false") << "\n\n";

    cout << "target = 4:\n";
    ok = findTarget(t1, t2, 4);
    cout << "Result: " << (ok ? "true" : "false") << "\n\n";

    cout << "Time: O(m+n)   Space: O(m+n)\n";

    freeTree(t1);
    freeTree(t2);
    return 0;
}
