// MODULE 28 — Transform to sum tree (node = sum of left + right subtree)

#include <iostream>
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

void printInorder(Node* root) {
    if (!root) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int toSumTree(Node* root) {
    if (!root) {
        return 0;
    }

    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);
    int old = root->data;

    root->data = leftSum + rightSum;

    cout << "  node " << old << " -> " << root->data
         << "  (left subtree sum=" << leftSum
         << ", right subtree sum=" << rightSum << ")\n";

    return old + leftSum + rightSum;
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
    cout << "Transform to sum tree\n";
    cout << "=====================\n\n";
    cout << "New value = sum of ALL nodes in left subtree + right subtree\n";
    cout << "(original node value is NOT included in its own new value)\n";
    cout << "Leaves become 0.\n\n";

    cout << "Original tree:\n";
    cout << "        1\n       / \\\n      2   3\n     / \\   \\\n    4   5   6\n\n";

    Node* root = buildTree();

    cout << "Original inorder: ";
    printInorder(root);
    cout << "\n\nPost-order conversion:\n";
    toSumTree(root);

    cout << "\nSum tree:\n";
    cout << "       20\n      /  \\\n     9    6\n    / \\    \\\n   0   0    0\n";
    cout << "(1->20=11+9, 2->9=4+5, 3->6, leaves->0)\n\n";

    cout << "Sum tree inorder: ";
    printInorder(root);
    cout << "\n\nTime: O(n)   Space: O(h) recursion stack\n";

    freeTree(root);
    return 0;
}
