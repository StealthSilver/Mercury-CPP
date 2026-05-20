// MODULE 33 — Building a graph using an adjacency list (step by step)

#include <iostream>
#include <vector>
using namespace std;

class GraphAdjList {
public:
    int V;
    vector<vector<int>> adj;

    explicit GraphAdjList(int vertices) : V(vertices), adj(vertices) {}

    void addUndirectedEdge(int u, int v) {
        cout << "   addUndirectedEdge(" << u << ", " << v << "): push " << v << " -> adj[" << u << "], "
             << u << " -> adj[" << v << "]\n";
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void print() const {
        cout << "\n   Final adjacency list:\n";
        for (int u = 0; u < V; u++) {
            cout << "   " << u << " : ";
            for (int v : adj[u]) cout << v << " ";
            cout << "\n";
        }
    }
};

int main() {
    cout << "Module 33 — Build graph: adjacency list (g.cpp)\n";
    cout << "===============================================\n\n";

    cout << "Steps:\n";
    cout << "  1. Choose number of vertices V.\n";
    cout << "  2. Create adj[0..V-1] each an empty vector (or list).\n";
    cout << "  3. For each edge (u,v), append v to adj[u] (and u to adj[v] if undirected).\n\n";

    cout << "Example: undirected house-shaped graph\n";
    cout << "   0---1---2\n";
    cout << "       |\n";
    cout << "       3\n\n";

    GraphAdjList g(4);
    g.addUndirectedEdge(0, 1);
    g.addUndirectedEdge(1, 2);
    g.addUndirectedEdge(1, 3);
    g.print();

    cout << "\nSpace: O(V + E)   Add edge: O(1) amortized push_back\n";
    return 0;
}
