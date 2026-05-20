#include <iostream>
#include <string>
using namespace std;


class Car {
private:
    string brand;
    string model;
    int year;

public:
    // Default constructor — used when you create a Car without passing values.
    Car() : brand("Unknown"), model("Unknown"), year(0) {
        cout << "[Car] Default constructor ran (no arguments).\n";
    }

    // Parameterized constructor — same name, different parameters; compiler picks by call.
    Car(const string& b, const string& m, int y) : brand(b), model(m), year(y) {
        cout << "[Car] Parameterized constructor ran: " << brand << " " << model
             << " (" << year << ")\n";
    }

    void describe() const {
        cout << "  -> " << brand << " " << model << ", year " << year << endl;
    }
};

int main() {
    cout << "1) Object created with no parentheses arguments — default constructor:\n";
    Car parkingLot; // same as: Car parkingLot{};

    cout << "\n2) Object created with (brand, model, year) — parameterized constructor:\n";
    Car dailyDriver("Honda", "Civic", 2022);

    cout << "\n3) Both objects are fully constructed; use them like any other Car:\n";
    parkingLot.describe();
    dailyDriver.describe();

    return 0;
}
