// MODULE 35 — Course Schedule I: can finish all courses? (DAG = no cycle)
// Prerequisite [a, b] means: take b before a  =>  edge b -> a

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool canFinish(int numCourses, const vector<pair<int, int>>& prerequisites) {
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

    int taken = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        taken++;
        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return taken == numCourses;
}

int main() {
    cout << "Module 35 — Course Schedule I (d.cpp)\n";
    cout << "=====================================\n\n";

    cout << "Example: 2 courses, [[1,0]] means need course 0 before 1.\n";
    cout << "canFinish = " << (canFinish(2, {{1, 0}}) ? "true" : "false") << "\n\n";

    cout << "Example: 2 courses, [[1,0],[0,1]] cycle — impossible.\n";
    cout << "canFinish = " << (canFinish(2, {{1, 0}, {0, 1}}) ? "true" : "false") << "\n\n";

    cout << "Build graph: prereq -> course; Kahn = count reachable removals.\n";
    cout << "Time: O(V + E)   Space: O(V + E)\n";

    return 0;
}
