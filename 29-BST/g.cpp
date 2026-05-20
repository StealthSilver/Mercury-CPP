// MODULE 29 — Inorder successor in BST (leftmost in right subtree)

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

Node* findNode(Node* root, int key) {
    if (!root) {
        return nullptr;
    }
    if (key == root->data) {
        return root;
    }
    if (key < root->data) {
        return findNode(root->left, key);
    }
    return findNode(root->right, key);
}

Node* inorderSuccessor(Node* node) {
    if (!node || !node->right) {
        return nullptr;
    }
    Node* succ = node->right;
    cout << "  Start at right child: " << succ->data << "\n";
    while (succ->left) {
        cout << "  go left to " << succ->left->data << "\n";
        succ = succ->left;
    }
    return succ;
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
    cout << "Inorder successor in BST\n";
    cout << "========================\n\n";
    cout << "Rule: leftmost node in the RIGHT subtree\n";
    cout << "Successor always has NO left child (0 or 1 right child only)\n\n";

    Node* root = nullptr;
    for (int x : {8, 3, 10, 1, 6, 14, 7, 13}) {
        root = insert(root, x);
    }

    cout << "Tree:\n        8\n       / \\\n      3   10\n     / \\    \\\n";
    cout << "    1   6    14\n       \\    /\n        7  13\n\n";

    for (int key : {3, 6, 8}) {
        Node* n = findNode(root, key);
        cout << "Successor of " << key << ":\n";
        Node* succ = inorderSuccessor(n);
        if (succ) {
            cout << "  -> " << succ->data;
            cout << "  (left child? " << (succ->left ? "yes" : "no");
            cout << ", right child? " << (succ->right ? "yes" : "no") << ")\n\n";
        } else {
            cout << "  -> none (no right subtree)\n\n";
        }
    }

    cout << "Used in f.cpp delete case 3: copy successor value, delete old successor\n";
    cout << "Time: O(h)   Space: O(1)\n";

    freeTree(root);
    return 0;
}
