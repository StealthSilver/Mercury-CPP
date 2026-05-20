// MODULE 31 — Itinerary from plane tickets (use every ticket exactly once)

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string findStartCity(const vector<pair<string, string>>& tickets) {
    unordered_map<string, int> balance;
    for (const auto& t : tickets) {
        balance[t.first]--;
        balance[t.second]++;
    }
    for (const auto& t : tickets) {
        if (balance[t.first] < 0) {
            return t.first;
        }
    }
    return tickets[0].first;
}

vector<string> buildItinerary(vector<pair<string, string>> tickets) {
    string start = findStartCity(tickets);

    unordered_map<string, vector<string>> graph;
    for (const auto& t : tickets) {
        graph[t.first].push_back(t.second);
    }
    for (auto& p : graph) {
        sort(p.second.begin(), p.second.end());
    }

    vector<string> route;
    vector<string> stack = {start};

    while (!stack.empty()) {
        string city = stack.back();
        if (graph[city].empty()) {
            route.push_back(city);
            stack.pop_back();
        } else {
            string next = graph[city].back();
            graph[city].pop_back();
            stack.push_back(next);
        }
    }

    reverse(route.begin(), route.end());
    return route;
}

int main() {
    cout << "Module 31 — Itinerary from Tickets (o.cpp)\n";
    cout << "==========================================\n\n";

    vector<pair<string, string>> tickets = {
        {"Chennai", "Bengaluru"},
        {"Mumbai", "Delhi"},
        {"Goa", "Chennai"},
        {"Delhi", "Goa"},
    };

    cout << "   Tickets:\n";
    for (const auto& t : tickets) {
        cout << "     " << t.first << " -> " << t.second << "\n";
    }
    cout << "\n   Route: ";
    vector<string> route = buildItinerary(tickets);
    for (size_t i = 0; i < route.size(); i++) {
        if (i) cout << " -> ";
        cout << route[i];
    }
    cout << "\n\n";

    cout << "Graph + iterative DFS (Hierholzer) uses each edge once.\n";
    cout << "Time: O(E log E) with sorting   Space: O(E)\n";
    return 0;
}
