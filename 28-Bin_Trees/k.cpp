// MODULE 28 — Subtree of another tree (LeetCode 572 style)
// Return true if subRoot exists as an identical subtree inside root

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

bool isSameTree(Node* a, Node* b) {
    if (!a && !b) {
        return true;
    }
    if (!a || !b) {
        return false;
    }
    return a->data == b->data && isSameTree(a->left, b->left) &&
           isSameTree(a->right, b->right);
}

bool isSubtree(Node* root, Node* subRoot) {
    if (!subRoot) {
        return true;
    }
    if (!root) {
        return false;
    }
    if (isSameTree(root, subRoot)) {
        return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

bool isSubtreeVerbose(Node* root, Node* subRoot, int depth) {
    if (!subRoot) {
        return true;
    }
    if (!root) {
        return false;
    }

    string indent(depth * 2, ' ');
    cout << indent << "Try at node " << root->data << ": ";
    if (isSameTree(root, subRoot)) {
        cout << "MATCH (same structure & values)\n";
        return true;
    }
    cout << "no match here\n";

    return isSubtreeVerbose(root->left, subRoot, depth + 1) ||
           isSubtreeVerbose(root->right, subRoot, depth + 1);
}

void freeTree(Node* root) {
    if (!root) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

Node* buildMainTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    return root;
}

Node* buildSubMatch() {
    Node* sub = new Node(2);
    sub->left = new Node(4);
    sub->right = new Node(5);
    return sub;
}

Node* buildSubNoMatch() {
    Node* sub = new Node(2);
    sub->right = new Node(4);
    return sub;
}

void printTree() {
    cout << "        1\n";
    cout << "       / \\\n";
    cout << "      2   3\n";
    cout << "     / \\   \\\n";
    cout << "    4   5   6\n";
}

int main() {
    cout << "Subtree of another tree\n";
    cout << "=======================\n\n";
    cout << "Question: does subRoot appear as a subtree of root?\n";
    cout << "(same structure AND same values)\n\n";

    cout << "Main tree (root):\n";
    printTree();
    cout << "\n";

    Node* root = buildMainTree();

    cout << "--- Test 1: subRoot matches subtree at node 2 ---\n\n";
    cout << "subRoot:\n";
    cout << "    2\n   / \\\n  4   5\n\n";

    Node* sub1 = buildSubMatch();
    cout << "Search:\n";
    bool ans1 = isSubtreeVerbose(root, sub1, 0);
    cout << "\nResult: " << (ans1 ? "true" : "false") << "  (expected true)\n\n";

    cout << "--- Test 2: subRoot does NOT match ---\n\n";
    cout << "subRoot:\n";
    cout << "  2\n   \\\n    4\n\n";

    Node* sub2 = buildSubNoMatch();
    cout << "Search:\n";
    bool ans2 = isSubtreeVerbose(root, sub2, 0);
    cout << "\nResult: " << (ans2 ? "true" : "false") << "  (expected false)\n\n";

    cout << "Time: O(m * n)   Space: O(h)\n";
    cout << "  m = nodes in root, n = nodes in subRoot\n";

    freeTree(root);
    freeTree(sub1);
    freeTree(sub2);
    return 0;
}
