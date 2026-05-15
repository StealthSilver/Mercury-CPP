#include <iostream>
using namespace std;

/*
 * Friends pairing: n friends; each is either alone or in exactly one pair.
 * f(n) = f(n-1) + (n-1) * f(n-2)
 *   alone: first friend single → arrange remaining n-1
 *   pair:  first friend with one of (n-1) others → arrange remaining n-2
 */

int friendsPairing(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    int alone = friendsPairing(n - 1);
    int paired = (n - 1) * friendsPairing(n - 2);
    return alone + paired;
}

int main() {
    int n = 3;
    cout << "Ways to pair " << n << " friends: " << friendsPairing(n) << endl;
    // n=1→1, n=2→2, n=3→4, n=4→10
    return 0;
}
