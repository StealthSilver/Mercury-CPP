// MODULE 28 — LCA Approach 1: store root-to-node paths — O(n) time, O(n) space

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* buildTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
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

Node* lcaByPath(Node* root, Node* p, Node* q) {
    vector<Node*> pathP, pathQ;
    findPath(root, p->data, pathP);
    findPath(root, q->data, pathQ);

    cout << "Path to " << p->data << ": ";
    for (Node* n : pathP) {
        cout << n->data << " ";
    }
    cout << "\nPath to " << q->data << ": ";
    for (Node* n : pathQ) {
        cout << n->data << " ";
    }
    cout << "\n";

    Node* lca = root;
    size_t i = 0;
    while (i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i]) {
        lca = pathP[i];
        ++i;
    }
  cout << "Last common node on both paths: " << lca->data << "\n";
    return lca;
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
    cout << "LCA — Approach 1 (path vectors)\n";
    cout << "================================\n\n";
    cout << "Store path root -> p and root -> q; last matching node is LCA.\n\n";
    cout << "Tree:\n        1\n       / \\\n      2   3\n     / \\   \\\n    4   5   6\n\n";

    Node* root = buildTree();

    struct Test {
        int a, b;
    };
    Test tests[] = {{4, 5}, {4, 6}, {2, 3}, {5, 6}};

    for (const Test& t : tests) {
        cout << "--- LCA(" << t.a << ", " << t.b << ") ---\n";
        Node* p = findNode(root, t.a);
        Node* q = findNode(root, t.b);
        Node* ans = lcaByPath(root, p, q);
        cout << "Answer: " << ans->data << "\n\n";
    }

    cout << "Time: O(n) — each path scan visits at most n nodes\n";
    cout << "Space: O(n) — two path vectors (worst case store full tree)\n";

    freeTree(root);
    return 0;
}
