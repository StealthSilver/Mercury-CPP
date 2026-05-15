#include <iostream>
using namespace std;

// x^n — O(log n): halve n each step (binary / fast exponentiation)
int power(int x, int n) {
    if (n == 0)
        return 1;

    int half = power(x, n / 2);

    if (n % 2 == 0)
        return half * half;

    return x * half * half;
}

int main() {
    int x = 2;
    int n = 10;
    cout << power(x, n) << endl; // 1024
    return 0;
}
