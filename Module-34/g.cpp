// MODULE 34 — Directed cycle using DFS (three colors: unvisited / in-stack / finished)

#include <iostream>
#include <vector>
using namespace std;

bool dfsDirected(int u, const vector<vector<int>>& adj, vector<int>& state) {
    state[u] = 1;
    for (int v : adj[u]) {
        if (state[v] == 1) {
            return true;
        }
        if (state[v] == 0 && dfsDirected(v, adj, state)) {
            return true;
        }
    }
    state[u] = 2;
    return false;
}

bool hasCycleDirectedDFS(int V, const vector<vector<int>>& adj) {
    vector<int> state(V, 0);
    for (int i = 0; i < V; i++) {
        if (state[i] == 0 && dfsDirected(i, adj, state)) {
            return true;
        }
    }
    return false;
}

int main() {
    cout << "Module 34 — Directed cycle: DFS three colors (g.cpp)\n";
    cout << "====================================================\n\n";

    int V = 4;
    vector<vector<int>> dag(V);
    dag[0].push_back(1);
    dag[1].push_back(2);
    dag[2].push_back(3);
    cout << "DAG 0->1->2->3: hasCycle = " << (hasCycleDirectedDFS(V, dag) ? "true" : "false") << "\n";

    vector<vector<int>> dc(V);
    dc[0].push_back(1);
    dc[1].push_back(2);
    dc[2].push_back(0);
    cout << "Directed triangle: hasCycle = " << (hasCycleDirectedDFS(V, dc) ? "true" : "false") << "\n\n";

    cout << "state 0=white, 1=gray (in current recursion stack), 2=black (done).\n";
    cout << "Edge into gray vertex = back edge along active path = directed cycle.\n";
    cout << "Time: O(V + E)   Space: O(V)\n";

    return 0;
}
