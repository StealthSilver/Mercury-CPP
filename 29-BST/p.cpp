// MODULE 29 — AVL Tree: check if tree is height-balanced (|BF| <= 1)

#include <algorithm>
#include <cstdlib>
#include <climits>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int v) : data(v), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* n) { return n ? n->height : 0; }

void updateHeight(Node* n) {
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
}

int balanceFactor(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

struct Check {
    bool isAVL;
    int height;
};

Check checkAVL(Node* root) {
    if (!root) {
        return {true, 0};
    }

    Check left = checkAVL(root->left);
    Check right = checkAVL(root->right);

    updateHeight(root);
    int bf = balanceFactor(root);

    bool balanced = left.isAVL && right.isAVL && abs(bf) <= 1;
    if (!balanced) {
        cout << "  FAIL at node " << root->data << " BF=" << bf << "\n";
    } else {
        cout << "  OK   node " << root->data << " BF=" << bf << "\n";
    }

    return {balanced, root->height};
}

Node* insertBST(Node* root, int key) {
    if (!root) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insertBST(root->left, key);
    } else {
        root->right = insertBST(root->right, key);
    }
    updateHeight(root);
    return root;
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
    cout << "AVL validation — is tree height-balanced?\n";
    cout << "========================================\n\n";

    cout << "--- Skewed BST (NOT AVL) ---\n";
    Node* skewed = nullptr;
    for (int x : {10, 20, 30, 40}) {
        skewed = insertBST(skewed, x);
    }
    Check c1 = checkAVL(skewed);
    cout << "Is AVL? " << (c1.isAVL ? "yes" : "no") << "  height=" << c1.height << "\n\n";
    freeTree(skewed);

    cout << "--- Manually balanced small tree (IS AVL) ---\n";
    Node* avl = new Node(30);
    avl->left = new Node(20);
    avl->right = new Node(40);
    avl->left->left = new Node(10);
    avl->right->right = new Node(50);
    updateHeight(avl->left->left);
    updateHeight(avl->left);
    updateHeight(avl->right->right);
    updateHeight(avl->right);
    updateHeight(avl);

    Check c2 = checkAVL(avl);
    cout << "Is AVL? " << (c2.isAVL ? "yes" : "no") << "  height=" << c2.height << "\n\n";

    cout << "Rule: every node has |balance factor| <= 1\n";
    cout << "Time: O(n) to check   Space: O(h)\n";

    freeTree(avl);
    return 0;
}
