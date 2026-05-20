#include <iostream>
using namespace std;

/*
 * Tiling a 2×n floor with 2×1 tiles (dominoes).
 *
 * Choice at each step (along the width n):
 *   Vertical   — one tile stands in one column  → remaining floor is 2×(n-1)
 *   Horizontal — two tiles lie in two columns    → remaining floor is 2×(n-2)
 *
 * Recurrence: tiling(n) = tiling(n-1) + tiling(n-2)
 * Base: n=0 → 1 way (empty), n=1 → 1 way (single vertical column)
 */

int tiling(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    int vertical = tiling(n - 1);   // place one column vertically
    int horizontal = tiling(n - 2); // place two columns with horizontal pair
    return vertical + horizontal;
}

int main() {
    int n = 4;
    cout << "Ways to tile 2x" << n << " floor: " << tiling(n) << endl;
    // n=1→1, n=2→2, n=3→3, n=4→5 (same growth as Fibonacci)
    return 0;
}
