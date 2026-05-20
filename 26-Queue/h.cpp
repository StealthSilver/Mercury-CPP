// MODULE 26 — Interleave two queues + interleave two halves of even queue

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> interleaveTwoQueues(queue<int> q1, queue<int> q2) {
    vector<int> out;
    while (!q1.empty() || !q2.empty()) {
        if (!q1.empty()) {
            out.push_back(q1.front());
            q1.pop();
        }
        if (!q2.empty()) {
            out.push_back(q2.front());
            q2.pop();
        }
    }
    return out;
}

vector<int> interleaveHalves(queue<int> q) {
    int n = static_cast<int>(q.size());
    queue<int> first, second;
    for (int i = 0; i < n / 2; ++i) {
        first.push(q.front());
        q.pop();
    }
    while (!q.empty()) {
        second.push(q.front());
        q.pop();
    }
    return interleaveTwoQueues(first, second);
}

static void printVec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) {
            cout << " ";
        }
    }
    cout << "\n";
}

int main() {
    cout << "=== Interleave two queues ===\n";
    queue<int> q1, q2;
    for (int x : {1, 2, 3}) {
        q1.push(x);
    }
    for (int x : {4, 5, 6}) {
        q2.push(x);
    }
    vector<int> a = interleaveTwoQueues(q1, q2);
    cout << "q1=[1,2,3] q2=[4,5,6] -> ";
    printVec(a);
    cout << "expected: 1 4 2 5 3 6\n\n";

    cout << "=== Interleave two halves (even size) ===\n";
    queue<int> q;
    for (int x : {11, 12, 13, 14, 15, 16}) {
        q.push(x);
    }
    vector<int> b = interleaveHalves(q);
    cout << "[11..16] -> ";
    printVec(b);
    cout << "expected: 11 14 12 15 13 16\n";

    return 0;
}
