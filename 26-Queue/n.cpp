// MODULE 26 — Problem 2: Gas station (circular route)

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
    int total = 0;
    int tank = 0;
    int start = 0;

    for (int i = 0; i < static_cast<int>(gas.size()); ++i) {
        int net = gas[i] - cost[i];
        total += net;
        tank += net;
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    return total < 0 ? -1 : start;
}

int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int start = canCompleteCircuit(gas, cost);

    cout << "Gas station circuit\n\n";
    cout << "gas:  ";
    for (int g : gas) {
        cout << g << " ";
    }
    cout << "\ncost: ";
    for (int c : cost) {
        cout << c << " ";
    }
    cout << "\nstart index: " << start << "  (expected 3)\n";

    vector<int> g2 = {2, 3, 4};
    vector<int> c2 = {3, 4, 3};
    cout << "\ngas [2,3,4] cost [3,4,3] -> " << canCompleteCircuit(g2, c2)
         << "  (expected -1)\n";

    return 0;
}
