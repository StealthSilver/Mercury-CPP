// MODULE 27 — Indian coin change (greedy, canonical denominations)

#include <iostream>
#include <vector>
using namespace std;

int indianCoins(int V) {
    vector<int> denoms = {2000, 500, 100, 50, 20, 10, 5, 2, 1};
    int count = 0;

    for (int c : denoms) {
        if (V >= c) {
            count += V / c;
            V %= c;
        }
    }
    return count;
}

int main() {
    int V = 590;
    int coins = indianCoins(V);

    cout << "Indian coin change (greedy)\n\n";
    cout << "denominations: 1, 2, 5, 10, 20, 50, 100, 500, 2000\n";
    cout << "V = " << V << "\n";
    cout << "min coins: " << coins << "  (expected 4: 500+50+20+20)\n\n";

    int V2 = 93;
    cout << "V = " << V2 << " -> " << indianCoins(V2) << " coins\n";

    return 0;
}
