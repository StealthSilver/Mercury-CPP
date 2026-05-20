// MODULE 34 — Directed cycle via "BFS on indegree" (Kahn's peeling, queue-based)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool hasCycleDirectedBFS_Kahn(int V, const vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    int processed = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        processed++;
        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return processed != V;
}

int main() {
    cout << "Module 34 — Directed cycle: BFS / indegree queue (f.cpp)\n";
    cout << "========================================================\n\n";

    int V = 4;
    vector<vector<int>> dag(V);
    dag[0].push_back(1);
    dag[1].push_back(2);
    dag[2].push_back(3);
    cout << "DAG 0->1->2->3: hasCycle = " << (hasCycleDirectedBFS_Kahn(V, dag) ? "true" : "false") << "\n";

    vector<vector<int>> dc(V);
    dc[0].push_back(1);
    dc[1].push_back(2);
    dc[2].push_back(0);
    cout << "Directed triangle 0->1->2->0: hasCycle = " << (hasCycleDirectedBFS_Kahn(V, dc) ? "true" : "false") << "\n\n";

    cout << "Peel all indegree-0 vertices layer by layer (queue = BFS order on the DAG of remainders).\n";
    cout << "If some vertices remain (indegree never hits 0), they lie on directed cycle(s).\n";
    cout << "Time: O(V + E)   Space: O(V)\n";

    return 0;
}
