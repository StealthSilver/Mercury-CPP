// MODULE 28 — Sum of all node values in binary tree

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

Node* buildFromPreorder(const vector<int>& arr) {
    if (idx >= static_cast<int>(arr.size()) || arr[idx] == -1) {
        ++idx;
        return nullptr;
    }
    Node* root = new Node(arr[idx++]);
    root->left = buildFromPreorder(arr);
    root->right = buildFromPreorder(arr);
    return root;
}

int sumNodes(Node* root) {
    if (!root) {
        return 0;
    }
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int sumVerbose(Node* root) {
    if (!root) {
        return 0;
    }
    int leftS = sumVerbose(root->left);
    int rightS = sumVerbose(root->right);
    int total = root->data + leftS + rightS;
    cout << "  node " << root->data << ": " << root->data << " + sum(left)=" << leftS
         << " + sum(right)=" << rightS << " = " << total << "\n";
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
    vector<int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    cout << "Sum of nodes in binary tree\n";
    cout << "===========================\n\n";
    cout << "Rule: sum = data + sum(left) + sum(right)\n\n";
    cout << "Tree:\n";
    cout << "        1\n       / \\\n      2   3\n     / \\   \\\n    4   5   6\n\n";

    idx = 0;
    Node* root = buildFromPreorder(arr);

    cout << "Combine from leaves upward:\n";
    int s = sumVerbose(root);
    cout << "\nTotal sum: " << s << "  (1+2+3+4+5+6 = 21)\n\n";
    cout << "Time: O(n)   Space: O(h) recursion stack\n";

    freeTree(root);
    return 0;
}
