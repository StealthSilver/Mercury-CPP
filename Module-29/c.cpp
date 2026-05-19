// MODULE 29 — Build BST from an array (insert each element)

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
    vector<int> arr = {8, 3, 10, 1, 6, 14, 7, 13};

    cout << "Build BST from array\n";
    cout << "====================\n\n";
    cout << "Rule: start with empty tree, insert each value in order\n\n";
    cout << "Array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n\n";

    Node* root = nullptr;
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        cout << "After insert " << arr[i] << ": ";
        root = insert(root, arr[i]);
        inorder(root);
        cout << "  (inorder = sorted)\n";
    }

    cout << "\nFinal BST shape:\n";
    cout << "        8\n       / \\\n      3   10\n     / \\    \\\n";
    cout << "    1   6    14\n       \\    /\n        7  13\n\n";

    cout << "Insert order affects shape — sorted array → skewed tree\n";
    cout << "Time: O(n * h) per build   Space: O(h)\n";

    freeTree(root);
    return 0;
}
