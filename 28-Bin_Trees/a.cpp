// MODULE 28 — Build binary tree from preorder (-1 = null child)
// Matches notes: [1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1]

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

int idx = 0;
int buildStep = 0;

Node* buildFromPreorder(const vector<int>& arr, bool verbose) {
    if (idx >= static_cast<int>(arr.size()) || arr[idx] == -1) {
        if (verbose) {
            ++buildStep;
            cout << "  Step " << buildStep << ": read -1  ->  nullptr (null child)\n";
        }
        ++idx;
        return nullptr;
    }

    int val = arr[idx];
    if (verbose) {
        ++buildStep;
        cout << "  Step " << buildStep << ": read " << val
             << "  ->  new node(" << val << ")\n";
    }
    ++idx;

    Node* root = new Node(val);
    root->left = buildFromPreorder(arr, verbose);
    root->right = buildFromPreorder(arr, verbose);
    return root;
}

void preorderSerialize(Node* root, vector<int>& out) {
    if (!root) {
        out.push_back(-1);
        return;
    }
    out.push_back(root->data);
    preorderSerialize(root->left, out);
    preorderSerialize(root->right, out);
}

void printPreorder(Node* root) {
    if (!root) {
        cout << "-1 ";
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printChildren(Node* root, int target) {
    if (!root) {
        return;
    }
    if (root->data == target) {
        cout << "Node " << target << ": ";
        if (!root->left && !root->right) {
            cout << "no children (leaf)\n";
        } else {
            cout << "left = ";
            if (root->left) {
                cout << root->left->data;
            } else {
                cout << "null";
            }
            cout << ", right = ";
            if (root->right) {
                cout << root->right->data;
            } else {
                cout << "null";
            }
            cout << "\n";
        }
    }
    printChildren(root->left, target);
    printChildren(root->right, target);
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
    vector<int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    cout << "Build tree from preorder (-1 = null)\n";
    cout << "===================================\n\n";

    cout << "Input array (preorder with null markers):\n  ";
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        cout << arr[i];
        if (i + 1 < static_cast<int>(arr.size())) {
            cout << ", ";
        }
    }
    cout << "\n\n";

    cout << "Rule: read value -> make node -> build LEFT subtree -> build RIGHT subtree\n";
    cout << "      -1 means no child at that position\n\n";

    cout << "Building (index starts at 0):\n";
    idx = 0;
    buildStep = 0;
    Node* root = buildFromPreorder(arr, true);

    cout << "\nExpected shape:\n\n";
    cout << "        1\n";
    cout << "       / \\\n";
    cout << "      2   3\n";
    cout << "     / \\   \\\n";
    cout << "    4   5   6\n\n";

    cout << "Verify — preorder of rebuilt tree:\n  ";
    printPreorder(root);
    cout << "\n  (should match input)\n\n";

    vector<int> serialized;
    preorderSerialize(root, serialized);
    bool match = serialized.size() == arr.size();
    for (size_t i = 0; i < arr.size() && match; ++i) {
        if (serialized[i] != arr[i]) {
            match = false;
        }
    }
    cout << "Array matches after serialize: " << (match ? "yes" : "no") << "\n\n";

    cout << "Sample lookups on built tree:\n";
    printChildren(root, 4);
    printChildren(root, 2);
    printChildren(root, 3);

    freeTree(root);
    return 0;
}
