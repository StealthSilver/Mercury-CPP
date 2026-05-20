// MODULE 28 — Kth ancestor of a node

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int v) : data(v), left(nullptr), right(nullptr), parent(nullptr) {}
};

Node* buildTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    root->left->parent = root;
    root->right->parent = root;
    root->left->left->parent = root->left;
    root->left->right->parent = root->left;
    root->right->right->parent = root->right;
    return root;
}

Node* findNode(Node* root, int val) {
    if (!root) {
        return nullptr;
    }
    if (root->data == val) {
        return root;
    }
    Node* left = findNode(root->left, val);
    return left ? left : findNode(root->right, val);
}

bool findPath(Node* root, int target, vector<Node*>& path) {
    if (!root) {
        return false;
    }
    path.push_back(root);
    if (root->data == target) {
        return true;
    }
    if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
        return true;
    }
    path.pop_back();
    return false;
}

int kthAncestorByPath(Node* root, int nodeVal, int k) {
    vector<Node*> path;
    findPath(root, nodeVal, path);

    cout << "  Path to " << nodeVal << ": ";
    for (Node* n : path) {
        cout << n->data << " ";
    }
    cout << "\n";

    if (k <= 0 || k >= static_cast<int>(path.size())) {
        cout << "  K=" << k << " -> no ancestor (out of range)\n";
        return -1;
    }
    Node* anc = path[path.size() - 1 - k];
    cout << "  Kth ancestor (K=" << k << ", 1=parent): " << anc->data << "\n";
    return anc->data;
}

int kthAncestorParent(Node* node, int k) {
    cout << "  Climb parent " << k << " times from " << node->data << ": ";
    while (node && k > 0) {
        node = node->parent;
        --k;
    }
    if (!node) {
        cout << "none\n";
        return -1;
    }
    cout << node->data << "\n";
    return node->data;
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
    cout << "Kth ancestor of a node\n";
    cout << "======================\n\n";
    cout << "K=1 -> parent, K=2 -> grandparent, ...\n\n";
    cout << "Tree:\n        1\n       / \\\n      2   3\n     / \\   \\\n    4   5   6\n\n";

    Node* root = buildTree();
    Node* node4 = findNode(root, 4);

    cout << "--- Node 4 (path method) ---\n";
    for (int k : {1, 2, 3, 4}) {
        kthAncestorByPath(root, 4, k);
    }
    cout << "\n--- Node 4 (parent pointers) ---\n";
    for (int k : {1, 2, 3}) {
        kthAncestorParent(node4, k);
    }
    cout << "\n--- Node 6, K=2 ---\n";
    kthAncestorByPath(root, 6, 2);

    cout << "\nTime: O(n)   Space: O(h) path or O(1) with parent\n";

    freeTree(root);
    return 0;
}
