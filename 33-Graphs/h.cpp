// MODULE 33 — Building a graph using an adjacency matrix

#include <iostream>
#include <vector>
using namespace std;

class GraphAdjMatrix {
public:
    int V;
    vector<vector<int>> mat;

    explicit GraphAdjMatrix(int vertices) : V(vertices), mat(vertices, vector<int>(vertices, 0)) {}

    void addUndirectedEdge(int u, int v) {
        cout << "   set mat[" << u << "][" << v << "] = mat[" << v << "][" << u << "] = 1\n";
        mat[u][v] = mat[v][u] = 1;
    }

    void print() const {
        cout << "\n   Adjacency matrix (rows = from, cols = to):\n";
        cout << "      ";
        for (int j = 0; j < V; j++) cout << j << " ";
        cout << "\n";
        for (int i = 0; i < V; i++) {
            cout << "   " << i << " ";
            for (int j = 0; j < V; j++) cout << mat[i][j] << " ";
            cout << "\n";
        }
    }
};

int main() {
    cout << "Module 33 — Build graph: adjacency matrix (h.cpp)\n";
    cout << "=================================================\n\n";

    cout << "Steps:\n";
    cout << "  1. Allocate V x V matrix, initialized to 0 (no edge).\n";
    cout << "  2. For edge (u,v): set mat[u][v] (and mat[v][u] if undirected).\n";
    cout << "  3. Weighted: store w instead of 1; use sentinel for 'no edge'.\n\n";

    GraphAdjMatrix g(4);
    g.addUndirectedEdge(0, 1);
    g.addUndirectedEdge(1, 2);
    g.addUndirectedEdge(1, 3);
    g.print();

    cout << "\nSpace: O(V^2)   Add edge: O(1) per cell\n";
    return 0;
}
