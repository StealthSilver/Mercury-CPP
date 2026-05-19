// MODULE 29 — BST search + balanced vs skewed (time depends on height)

#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* insertBST(Node* root, int key) {
    if (!root) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insertBST(root->left, key);
    } else if (key > root->data) {
        root->right = insertBST(root->right, key);
    }
    return root;
}

int height(Node* root) {
    if (!root) {
        return -1;
    }
    return 1 + max(height(root->left), height(root->right));
}

Node* buildBalancedBST() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    return root;
}

Node* buildSkewedBST() {
    Node* root = nullptr;
    for (int v : {1, 2, 3, 4, 5, 6, 7, 8}) {
        root = insertBST(root, v);
    }
    return root;
}

Node* searchVerbose(Node* root, int key, int& steps) {
    if (!root) {
        return nullptr;
    }
    ++steps;
    cout << "  step " << steps << ": at " << root->data;
    if (key == root->data) {
        cout << "  -> found\n";
        return root;
    }
    if (key < root->data) {
        cout << ", " << key << " < " << root->data << " -> left\n";
        return searchVerbose(root->left, key, steps);
    }
    cout << ", " << key << " > " << root->data << " -> right\n";
    return searchVerbose(root->right, key, steps);
}

Node* searchIter(Node* root, int key) {
    while (root) {
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
    cout << "BST search — balanced vs skewed\n";
    cout << "===============================\n\n";
    cout << "Time: O(h)   Space: O(h) recursive, O(1) iterative\n\n";

    cout << "--- Balanced BST ---\n\n";
    cout << "        8\n       / \\\n      3   10\n     / \\    \\\n";
    cout << "    1   6    14\n       \\    /\n        7  13\n\n";

    Node* balanced = buildBalancedBST();
    cout << "height = " << height(balanced) << "  (≈ log2(n) for n=8)\n\n";

    int steps = 0;
    cout << "Search key 7:\n";
    searchVerbose(balanced, 7, steps);
    cout << "Total steps: " << steps << "\n\n";

    steps = 0;
    cout << "Search key 13:\n";
    searchVerbose(balanced, 13, steps);
    cout << "Total steps: " << steps << "\n\n";

    cout << "--- Skewed BST (insert 1..8 in order) ---\n\n";
    cout << "    1\n     \\\n      2\n       \\\n        3\n         \\\n";
    cout << "          4\n           \\\n            5\n             \\\n";
    cout << "              6\n               \\\n                7\n                 \\\n                  8\n\n";

    Node* skewed = buildSkewedBST();
    cout << "height = " << height(skewed) << "  (n-1 for n nodes in a chain)\n\n";

    steps = 0;
    cout << "Search key 8:\n";
    searchVerbose(skewed, 8, steps);
    cout << "Total steps: " << steps << "  (visits every node)\n\n";

    steps = 0;
    cout << "Search key 1:\n";
    searchVerbose(skewed, 1, steps);
    cout << "Total steps: " << steps << "\n\n";

    cout << "--- Iterative search (O(1) extra space) ---\n";
    Node* found = searchIter(balanced, 7);
    cout << "searchIter(balanced, 7) -> " << (found ? found->data : -1) << "\n\n";

    cout << "Summary:\n";
    cout << "  Balanced:  few steps O(log n)\n";
    cout << "  Skewed:    many steps O(n)\n";

    freeTree(balanced);
    freeTree(skewed);
    return 0;
}
