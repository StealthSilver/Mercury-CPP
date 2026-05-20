// MODULE 28 — Problem 1: Uni-valued binary tree (LeetCode 965)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

bool isUniValued(Node* root, int ref) {
    if (!root) {
        return true;
    }
    if (root->data != ref) {
        return false;
    }
    return isUniValued(root->left, ref) && isUniValued(root->right, ref);
}

bool check(Node* root) {
    if (!root) {
        return true;
    }
    return isUniValued(root, root->data);
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
    cout << "Problem 1: Uni-valued binary tree\n";
    cout << "=================================\n\n";

    Node* uni = new Node(5);
    uni->left = new Node(5);
    uni->right = new Node(5);
    uni->left->left = new Node(5);

    Node* notUni = new Node(1);
    notUni->left = new Node(1);
    notUni->right = new Node(2);

    cout << "Tree A (all 5s):     Tree B (has 1 and 2):\n";
    cout << "    5                    1\n";
    cout << "   / \\                  / \\\n";
    cout << "  5   5                1   2\n";
    cout << " /\n";
    cout << "5\n\n";

    cout << "Tree A uni-valued? " << (check(uni) ? "true" : "false") << "\n";
    cout << "Tree B uni-valued? " << (check(notUni) ? "true" : "false") << "\n\n";

    cout << "Time: O(n)   Space: O(h)\n";

    freeTree(uni);
    freeTree(notUni);
    return 0;
}
