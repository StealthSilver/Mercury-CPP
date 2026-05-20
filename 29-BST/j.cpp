// MODULE 29 — Validate BST (range check + inorder check)

#include <climits>
#include <iostream>
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

bool isBSTRange(Node* root, long minV, long maxV) {
    if (!root) {
        return true;
    }
    if (root->data <= minV || root->data >= maxV) {
        cout << "  FAIL at " << root->data << " not in (" << minV << ", " << maxV << ")\n";
        return false;
    }
    return isBSTRange(root->left, minV, root->data) &&
           isBSTRange(root->right, root->data, maxV);
}

bool isBSTInorder(Node* root, long& prev) {
    if (!root) {
        return true;
    }
    if (!isBSTInorder(root->left, prev)) {
        return false;
    }
    if (root->data <= prev) {
        cout << "  FAIL inorder: " << root->data << " <= prev " << prev << "\n";
        return false;
    }
    prev = root->data;
    return isBSTInorder(root->right, prev);
}

void freeTree(Node* root) {
    if (!root) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

Node* buildValid() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    return root;
}

Node* buildInvalid() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(9);
    root->right->right = new Node(14);
    return root;
}

int main() {
    cout << "Validate BST\n";
    cout << "============\n\n";

    cout << "--- Valid BST ---\n";
    cout << "        8\n       / \\\n      3   10\n     / \\    \\\n    1   6    14\n\n";
    Node* valid = buildValid();
    cout << "Range method: " << (isBSTRange(valid, LONG_MIN, LONG_MAX) ? "true" : "false") << "\n";
    long prev = LONG_MIN;
    cout << "Inorder method: " << (isBSTInorder(valid, prev) ? "true" : "false") << "\n\n";

    cout << "--- Invalid BST (9 in left subtree of 8) ---\n";
    cout << "        8\n       / \\\n      3   10\n     / \\    \\\n    1   9    14\n\n";
    Node* invalid = buildInvalid();
    cout << "Range method:\n";
    bool r = isBSTRange(invalid, LONG_MIN, LONG_MAX);
    cout << "Result: " << (r ? "true" : "false") << "\n\n";
    prev = LONG_MIN;
    cout << "Inorder method:\n";
    bool i = isBSTInorder(invalid, prev);
    cout << "Result: " << (i ? "true" : "false") << "\n\n";

    cout << "Time: O(n)   Space: O(h)\n";

    freeTree(valid);
    freeTree(invalid);
    return 0;
}
