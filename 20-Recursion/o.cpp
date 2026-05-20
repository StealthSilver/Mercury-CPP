#include <iostream>
#include <string>
using namespace std;

// Print all binary strings of length n with no consecutive 1s.
// lastPlace: 0 = last char was '0' (or empty start) → may append '1'
//            1 = last char was '1' → only '0' allowed next
void printBinary(int n, int lastPlace, string s) {
    if (n == 0) {
        cout << s << endl;
        return;
    }

    printBinary(n - 1, 0, s + '0');

    if (lastPlace == 0)
        printBinary(n - 1, 1, s + '1');
}

int main() {
    int n = 3;
    cout << "Binary strings of length " << n << " (no consecutive 1s):\n";
    printBinary(n, 0, "");
    return 0;
}
 