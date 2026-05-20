// MODULE 39 — Stock with transaction fee (unlimited transactions, one share at a time)

#include <iostream>
#include <vector>
using namespace std;

// State each day: cash (not holding) or hold (own stock)
int maxProfitFee(const vector<int>& prices, int fee) {
    int cash = 0, hold = -prices[0];
    for (int i = 1; i < (int)prices.size(); i++) {
        cash = max(cash, hold + prices[i] - fee);  // sell today (fee on sell)
        hold = max(hold, cash - prices[i]);        // buy today
    }
    return cash;
}

int maxProfitFeeTable(const vector<int>& prices, int fee, bool trace) {
    int n = (int)prices.size();
    vector<int> dpCash(n, 0), dpHold(n, -prices[0]);
    for (int i = 1; i < n; i++) {
        dpCash[i] = max(dpCash[i - 1], dpHold[i - 1] + prices[i] - fee);
        dpHold[i] = max(dpHold[i - 1], dpCash[i - 1] - prices[i]);
    }
    if (trace) {
        cout << "  Day | price | cash  | hold\n";
        for (int i = 0; i < n; i++)
            cout << "  " << i << "  |  " << prices[i] << "   | " << dpCash[i]
                 << " | " << dpHold[i] << "\n";
    }
    return dpCash[n - 1];
}

int main() {
    cout << "Module 39 — Stock with fee (l.cpp)\n";
    cout << "==================================\n\n";

    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << "prices = {1,3,2,8,4,9}, fee = " << fee << "\n";
    cout << "  max profit: " << maxProfitFee(prices, fee) << "\n\n";

    cout << "2D table (cash / hold):\n";
    cout << "  tab profit = " << maxProfitFeeTable(prices, fee, true) << "\n";
    return 0;
}
