// MODULE 28 — Diameter of tree — Approach 2: O(n)
// One post-order DFS: return height, update global ans

#include <algorithm>
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

int solve(Node* root, int& ans) {
    if (!root) {
        return -1;
    }

    int leftH = solve(root->left, ans);
    int rightH = solve(root->right, ans);
    int through = leftH + rightH + 2;

    cout << "  node " << root->data << ": L=" << leftH << ", R=" << rightH
         << "  =>  through=" << through;
    if (through > ans) {
        ans = through;
        cout << "  (new max)";
    }
    cout << "\n";

    return 1 + max(leftH, rightH);
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

    cout << "Diameter — Approach 2 (O(n))\n";
    cout << "===========================\n\n";
    cout << "One DFS: at each node, ans = max(ans, L + R + 2)\n";
    cout << "Return height upward (no repeated height scans)\n\n";
    cout << "Tree:\n";
    cout << "        1\n       / \\\n      2   3\n     / \\   \\\n    4   5   6\n\n";

    idx = 0;
    Node* root = buildFromPreorder(arr);

    int ans = 0;
    cout << "Post-order combine:\n";
    int treeHeight = solve(root, ans);

    cout << "\nTree height (root): " << treeHeight << " edges\n";
    cout << "Maximum diameter: " << ans << " edges\n";
    cout << "Nodes on longest path: " << ans + 1 << "  (4-2-1-3-6)\n\n";
    cout << "Time: O(n)   Space: O(h)\n";

    freeTree(root);
    return 0;
}
