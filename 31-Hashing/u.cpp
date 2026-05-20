// MODULE 31 — Bulls and Cows (digit frequency map)

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string getHint(const string& secret, const string& guess) {
    int bulls = 0;
    unordered_map<char, int> secretFreq;
    unordered_map<char, int> guessFreq;

    for (size_t i = 0; i < secret.size(); i++) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            secretFreq[secret[i]]++;
            guessFreq[guess[i]]++;
        }
    }

    int cows = 0;
    for (auto& p : guessFreq) {
        if (secretFreq.count(p.first)) {
            cows += min(p.second, secretFreq[p.first]);
        }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main() {
    cout << "Module 31 — Bulls & Cows (u.cpp)\n";
    cout << "================================\n\n";

    auto show = [](const string& secret, const string& guess) {
        cout << "   secret = " << secret << ", guess = " << guess << "\n";
        cout << "   hint   = " << getHint(secret, guess) << "\n\n";
    };

    show("1807", "7810");
    show("1123", "0111");
    show("1234", "1234");

    cout << "Bulls: same position. Cows: matching digits in wrong position.\n";
    cout << "Count non-bull digits with frequency maps, sum min counts.\n";
    cout << "Time: O(n)   Space: O(1) — at most 10 digits\n";
    return 0;
}
