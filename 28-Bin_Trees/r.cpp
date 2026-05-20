// MODULE 28 — Minimum distance between two nodes

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

int minDistance(Node* root, int a, int b) {
    vector<Node*> pathA, pathB;
    findPath(root, a, pathA);
    findPath(root, b, pathB);

    cout << "  Path " << a << ": ";
    for (Node* n : pathA) {
        cout << n->data << " ";
    }
    cout << "\n  Path " << b << ": ";
    for (Node* n : pathB) {
        cout << n->data << " ";
    }
    cout << "\n";

    size_t i = 0;
    while (i < pathA.size() && i < pathB.size() && pathA[i] == pathB[i]) {
        ++i;
    }
    Node* lca = pathA[i - 1];
    int distA = static_cast<int>(pathA.size() - i);
    int distB = static_cast<int>(pathB.size() - i);
    int total = distA + distB;

    cout << "  LCA = " << lca->data << " at path index " << (i - 1) << "\n";
    cout << "  distance(" << a << " -> LCA) = " << distA << " edges\n";
    cout << "  distance(" << b << " -> LCA) = " << distB << " edges\n";
    cout << "  min distance = " << distA << " + " << distB << " = " << total << "\n";

    return total;
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
    cout << "Minimum distance between two nodes\n";
    cout << "==================================\n\n";
    cout << "Formula: dist(p,q) = dist(root,p) + dist(root,q) - 2*dist(root,LCA)\n";
    cout << "        = edges from p up to LCA + edges from q up to LCA\n\n";
    cout << "Tree:\n        1\n       / \\\n      2   3\n     / \\   \\\n    4   5   6\n\n";

    Node* root = buildTree();

    struct Test {
        int a, b;
    };
    Test tests[] = {{4, 5}, {4, 6}, {5, 6}, {2, 4}};

    for (const Test& t : tests) {
        cout << "--- distance(" << t.a << ", " << t.b << ") ---\n";
        int d = minDistance(root, t.a, t.b);
        cout << "Answer: " << d << " edges\n\n";
    }

    cout << "Time: O(n)   Space: O(n) for paths\n";

    freeTree(root);
    return 0;
}
