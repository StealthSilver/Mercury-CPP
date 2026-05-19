// MODULE 29 — Print values in range [low, high] in BST

#include <iostream>
#include <string>
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

void printInRange(Node* root, int low, int high, int depth) {
    if (!root) {
        return;
    }

    string indent(depth * 2, ' ');
    if (root->data < low) {
        cout << indent << "at " << root->data << " < " << low << " -> only right\n";
        printInRange(root->right, low, high, depth + 1);
        return;
    }
    if (root->data > high) {
        cout << indent << "at " << root->data << " > " << high << " -> only left\n";
        printInRange(root->left, low, high, depth + 1);
        return;
    }

    cout << indent << "at " << root->data << " in range -> print, both sides\n";
    printInRange(root->left, low, high, depth + 1);
    cout << indent << "  PRINT " << root->data << "\n";
    printInRange(root->right, low, high, depth + 1);
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
    cout << "Print in range [low, high]\n";
    cout << "==========================\n\n";

    Node* root = nullptr;
    for (int x : {8, 3, 10, 1, 6, 14, 7, 13}) {
        root = insert(root, x);
    }

    cout << "Tree:\n        8\n       / \\\n      3   10\n     / \\    \\\n";
    cout << "    1   6    14\n       \\    /\n        7  13\n\n";

    int low = 6, high = 10;
    cout << "Range [" << low << ", " << high << "]:\n";
    printInRange(root, low, high, 0);

    cout << "\nOutput order is sorted (inorder with pruning)\n";
    cout << "Time: O(h + k)   Space: O(h)\n";

    freeTree(root);
    return 0;
}
