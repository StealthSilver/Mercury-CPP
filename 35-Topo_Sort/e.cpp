// MODULE 35 — Course Schedule II: return an order to take all courses, or empty if impossible
// Prerequisite [a, b] => edge b -> a (finish b before a)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> findOrder(int numCourses, const vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    for (auto [course, prereq] : prerequisites) {
        adj[prereq].push_back(course);
        indegree[course]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (static_cast<int>(order.size()) != numCourses) {
        return {};
    }
    return order;
}

int main() {
    cout << "Module 35 — Course Schedule II (e.cpp)\n";
    cout << "======================================\n\n";

    auto printOrder = [](const vector<int>& o) {
        if (o.empty()) {
            cout << "   (impossible — cycle)\n";
        } else {
            cout << "   ";
            for (int x : o) cout << x << " ";
            cout << "\n";
        }
    };

    cout << "numCourses=4, prereq [[1,0],[2,0],[3,1],[3,2]]\n";
    cout << "Meaning: 0 before 1,2; 1 and 2 before 3.\n";
    vector<int> o1 = findOrder(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}});
    printOrder(o1);

    cout << "\nCycle [[1,0],[0,1]]:\n";
    vector<int> o2 = findOrder(2, {{1, 0}, {0, 1}});
    printOrder(o2);

    cout << "\nKahn output IS a valid take order when full length n.\n";
    cout << "Time: O(V + E)   Space: O(V + E)\n";

    return 0;
}
