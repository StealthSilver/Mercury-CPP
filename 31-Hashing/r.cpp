// MODULE 31 — Bottom view of binary tree (BFS + horizontal distance + map)

#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

int buildIdx = 0;

Node* buildFromPreorder(const vector<int>& arr) {
    if (buildIdx >= static_cast<int>(arr.size()) || arr[buildIdx] == -1) {
        ++buildIdx;
        return nullptr;
    }
    Node* root = new Node(arr[buildIdx++]);
    root->left = buildFromPreorder(arr);
    root->right = buildFromPreorder(arr);
    return root;
}

vector<int> bottomView(Node* root) {
    vector<int> result;
    if (!root) {
        return result;
    }

    map<int, int> bottom;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        Node* cur = q.front().first;
        int hd = q.front().second;
        q.pop();

        bottom[hd] = cur->data;

        if (cur->left) q.push({cur->left, hd - 1});
        if (cur->right) q.push({cur->right, hd + 1});
    }

    for (auto& p : bottom) {
        result.push_back(p.second);
    }
    return result;
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    cout << "Module 31 — Bottom View of Binary Tree (r.cpp)\n";
    cout << "==============================================\n\n";

    vector<int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    cout << "Tree (HD labels):\n";
    cout << "           1(0)\n";
    cout << "          /    \\\n";
    cout << "      2(-1)    3(1)\n";
    cout << "      /  \\       \\\n";
    cout << "  4(-2) 5(0)    6(2)\n\n";

    buildIdx = 0;
    Node* root = buildFromPreorder(arr);
    vector<int> view = bottomView(root);

    cout << "Bottom view (left to right by HD): ";
    for (int v : view) cout << v << " ";
    cout << "\n\n";

    cout << "BFS: overwrite map[HD] at each visit — deepest node wins.\n";
    cout << "Top view would keep first visit per HD instead.\n";
    cout << "Time: O(n log n) with map   Space: O(n)\n";

    freeTree(root);
    return 0;
}
