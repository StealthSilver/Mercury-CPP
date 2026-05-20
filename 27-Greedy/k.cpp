// MODULE 27 — Problem 3: Smallest string with numeric value k

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string getSmallestString(int n, int k) {
    if (k < n || k > 26 * n) {
        return "";
    }
    string s(n, 'a');
    int rem = k - n;
    for (int i = n - 1; i >= 0 && rem > 0; --i) {
        int add = min(rem, 25);
        s[i] += add;
        rem -= add;
    }
    return s;
}

int main() {
    cout << "Smallest string with numeric value k\n\n";

    cout << "n=3, k=27 -> \"" << getSmallestString(3, 27) << "\"  (expected aay)\n";
    cout << "n=5, k=73 -> \"" << getSmallestString(5, 73) << "\"\n";
    cout << "n=3, k=5  -> \"" << getSmallestString(3, 5) << "\"  (expected aac, sum 1+1+3=5)\n";

    return 0;
}
