// MODULE 27 — Problem 4: Best time to buy and sell stock (one transaction)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }
    int minPrice = prices[0];
    int best = 0;
    for (int p : prices) {
        minPrice = min(minPrice, p);
        best = max(best, p - minPrice);
    }
    return best;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int ans = maxProfit(prices);

    cout << "Best time to buy and sell stock\n\n";
    cout << "prices: ";
    for (int p : prices) {
        cout << p << " ";
    }
    cout << "\nmax profit: " << ans << "  (expected 5)\n";

    return 0;
}
