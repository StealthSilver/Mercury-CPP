// MODULE 29 — Problem 2: Closest value to K in BST (LeetCode 270)

#include <cstdlib>
#include <iostream>
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

int closestValue(Node* root, int k) {
    int best = root->data;
    Node* cur = root;

    cout << "  Search for K=" << k << ":\n";
    while (cur) {
        cout << "    at " << cur->data;
        if (abs(cur->data - k) < abs(best - k)) {
            best = cur->data;
            cout << "  (new closest=" << best << ")";
        }
        cout << "\n";

        if (k < cur->data) {
            cur = cur->left;
        } else if (k > cur->data) {
            cur = cur->right;
        } else {
            return cur->data;
        }
    }
    return best;
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
    cout << "Problem 2: Closest value to K in BST\n";
    cout << "===================================\n\n";

    Node* root = nullptr;
    for (int x : {4, 2, 5, 1, 3}) {
        root = insert(root, x);
    }

    cout << "BST inorder: 1 2 3 4 5\n\n";

    for (int k : {3, 4, 0, 6}) {
        cout << "K = " << k << ":\n";
        int ans = closestValue(root, k);
        cout << "  Closest value: " << ans << "\n\n";
    }

    cout << "Time: O(h)   Space: O(1)\n";

    freeTree(root);
    return 0;
}
