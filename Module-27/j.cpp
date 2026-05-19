// MODULE 27 — Problem 2: Largest odd number substring

#include <iostream>
#include <string>
using namespace std;

string largestOddNumber(string num) {
    for (int i = static_cast<int>(num.size()) - 1; i >= 0; --i) {
        if ((num[i] - '0') % 2 == 1) {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

int main() {
    cout << "Largest odd number substring\n\n";

    string a = "52";
    cout << "num=\"" << a << "\" -> \"" << largestOddNumber(a) << "\"  (expected \"5\")\n";

    string b = "4205";
    cout << "num=\"" << b << "\" -> \"" << largestOddNumber(b) << "\"  (expected \"4205\")\n";

    string c = "420";
    cout << "num=\"" << c << "\" -> \"" << largestOddNumber(c) << "\"  (expected \"\")\n";

    return 0;
}
