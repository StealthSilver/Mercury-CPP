#include <iostream>
using namespace std;

/*
 * RECURSION (ties to notes.md)
 *
 * When a function calls itself, that is recursion. The same logic is often
 * doable with loops (iteration), but recursion can match the problem structure
 * (e.g. trees, divide-and-conquer) and read more directly.
 *
 * Call chain: main -> f -> f -> f -> ... until the BASE CASE stops further
 * calls. Then each call "unwinds" and returns to its caller. Without a base
 * case, calls never stop and you get stack overflow.
 */

// Example 1: countdown — shows "deeper calls" then returns in reverse order.
void countdown(int n) {
    if (n <= 0) {
        cout << "  base case: n is " << n << ", stop recursing\n";
        return;
    }
    cout << "  going deeper: n = " << n << "\n";
    countdown(n - 1);
    cout << "  returning: n was " << n << "\n";
}

// Example 2: factorial — classic "problem shrinks toward base case".
int factorial(int n) {
    if (n <= 1)
        return 1; // base case
    return n * factorial(n - 1);
}

// Same factorial idea with a loop (iteration) for comparison.
int factorial_iter(int n) {
    int r = 1;
    for (int i = 2; i <= n; ++i)
        r *= i;
    return r;
}

int main() {
    cout << "--- Example 1: countdown(3) ---\n";
    countdown(3);

    cout << "\n--- Example 2: factorial ---\n";
    int x = 5;
    cout << "factorial(" << x << ") recursive = " << factorial(x) << "\n";
    cout << "factorial(" << x << ") iterative = " << factorial_iter(x) << "\n";

    return 0;
}
