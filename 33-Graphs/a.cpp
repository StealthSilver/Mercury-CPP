// MODULE 33 — std::list (doubly linked list) + using lists to build adjacency

#include <iostream>
#include <list>
#include <vector>
using namespace std;

void demoListOperations() {
    cout << "1. std::list — doubly linked list\n";
    cout << "==================================\n";

    list<int> L;

    L.push_back(10);
    L.push_back(20);
    L.push_front(5);
    cout << "   After push_front(5), push_back(10,20): ";
    for (int x : L) cout << x << " ";
    cout << "\n";

    cout << "   front() = " << L.front() << "   back() = " << L.back()
         << "   size() = " << L.size() << "\n";

    L.pop_front();
    cout << "   After pop_front(): ";
    for (int x : L) cout << x << " ";
    cout << "\n";

    L.pop_back();
    cout << "   After pop_back(): ";
    for (int x : L) cout << x << " ";
    cout << "\n\n";
}

void demoAdjacencyWithList() {
    cout << "2. Adjacency as list<int> per vertex\n";
    cout << "====================================\n";

    int V = 5;
    vector<list<int>> adj(V);

    auto addUndirected = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addUndirected(0, 1);
    addUndirected(0, 2);
    addUndirected(1, 3);
    addUndirected(2, 4);

    cout << "   Undirected graph (0-1-3 and 0-2-4):\n";
    for (int u = 0; u < V; u++) {
        cout << "   vertex " << u << " -> ";
        for (int v : adj[u]) cout << v << " ";
        cout << "\n";
    }
    cout << "\n";
    cout << "list: O(1) insert/erase at ends; good when degree varies a lot.\n";
    cout << "vector<vector<int>> is also common for adjacency lists.\n";
}

int main() {
    cout << "Module 33 — std::list & graph building (a.cpp)\n";
    cout << "==============================================\n\n";

    demoListOperations();
    demoAdjacencyWithList();

    return 0;
}
