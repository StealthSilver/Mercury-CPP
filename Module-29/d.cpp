// MODULE 29 — Insert element in BST

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key, int depth) {
    if (!root) {
        string indent(depth * 2, ' ');
        cout << indent << "nullptr -> create node " << key << "\n";
        return new Node(key);
    }

    string indent(depth * 2, ' ');
    cout << indent << "at " << root->data;
    if (key < root->data) {
        cout << ", " << key << " < " << root->data << " -> left\n";
        root->left = insert(root->left, key, depth + 1);
    } else if (key > root->data) {
        cout << ", " << key << " > " << root->data << " -> right\n";
        root->right = insert(root->right, key, depth + 1);
    } else {
        cout << " (duplicate, skip)\n";
    }
    return root;
}

void inorder(Node* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    cout << "Insert element in BST\n";
    cout << "=====================\n\n";

    Node* root = nullptr;
    for (int x : {8, 3, 10, 1, 6, 14}) {
        root = insert(root, x, 0);
    }

    cout << "\nTree before insert 5:\n";
    cout << "        8\n       / \\\n      3   10\n     / \\    \\\n    1   6    14\n\n";

    cout << "Insert 5:\n";
    root = insert(root, 5, 0);

    cout << "\nAfter insert:\n";
    cout << "        8\n       / \\\n      3   10\n     / \\    \\\n";
    cout << "    1   6    14\n       /\n      5\n\n";

    cout << "Inorder: ";
    inorder(root);
    cout << "\n\nTime: O(h)   Space: O(h)\n";

    freeTree(root);
    return 0;
}
