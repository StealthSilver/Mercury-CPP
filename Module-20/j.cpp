#include <iostream>
using namespace std;

// x^n — O(n): one recursive call per decrement of n
int power(int x, int n) {
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}

int main() {
    int x = 2;
    int n = 10;
    cout << power(x, n) << endl; // 1024
    return 0;
}
