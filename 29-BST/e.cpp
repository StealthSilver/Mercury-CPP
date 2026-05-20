// MODULE 29 — Search value in BST (recursive + iterative)

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

Node* searchRec(Node* root, int key, int& steps) {
    if (!root) {
        return nullptr;
    }
    ++steps;
    if (key == root->data) {
        return root;
    }
    if (key < root->data) {
        return searchRec(root->left, key, steps);
    }
    return searchRec(root->right, key, steps);
}

Node* searchIter(Node* root, int key, int& steps) {
    while (root) {
        ++steps;
        if (key == root->data) {
            return root;
        }
        root = (key < root->data) ? root->left : root->right;
    }
    return nullptr;
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
    cout << "Search value in BST\n";
    cout << "===================\n\n";

    Node* root = nullptr;
    for (int x : {8, 3, 10, 1, 6, 14, 7, 13}) {
        root = insert(root, x);
    }

    cout << "Tree:\n        8\n       / \\\n      3   10\n     / \\    \\\n";
    cout << "    1   6    14\n       \\    /\n        7  13\n\n";

    struct Q {
        int key;
        bool found;
    };
    Q queries[] = {{7, true}, {13, true}, {99, false}};

    for (const Q& q : queries) {
        int steps = 0;
        Node* r = searchRec(root, q.key, steps);
        cout << "Recursive search " << q.key << ": ";
        cout << (r ? "found" : "not found") << " (" << steps << " steps)\n";

        steps = 0;
        Node* it = searchIter(root, q.key, steps);
        cout << "Iterative search " << q.key << ": ";
        cout << (it ? "found" : "not found") << " (" << steps << " steps)\n\n";
    }

    cout << "Recursive: O(h) time, O(h) space\n";
    cout << "Iterative: O(h) time, O(1) space\n";

    freeTree(root);
    return 0;
}
