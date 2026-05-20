#include <iostream>
#include <climits>
using namespace std;

void buyAndSell(int *prices, int n)
{
    int bestBuy[100000]; // we can manually init for now later we use a vector (dynamic size) for this

    bestBuy[0] = INT_MAX;

    // Store best buying price before each day
    for (int i = 1; i < n; i++)
    {
        bestBuy[i] = min(bestBuy[i - 1], prices[i - 1]);
    }

    int maxProfit = 0;

    // Calculate max profit
    for (int i = 0; i < n; i++)
    {
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }

    cout << "Max Profit = " << maxProfit << endl;
}

int main()
{
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(int);

    buyAndSell(prices, n);

    return 0;
}