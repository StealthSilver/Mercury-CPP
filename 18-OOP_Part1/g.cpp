#include <iostream>
#include <string>
using namespace std;


class Car {
private:
    string brand;
    string model;
    int year;

public:
    // Overload 1: no arguments — default construction.
    Car() : brand("Unknown"), model("Unknown"), year(0) {
        cout << "Called: Car() — no arguments\n";
    }

    // Overload 2: brand, model, and year.
    Car(const string& b, const string& m, int y) : brand(b), model(m), year(y) {
        cout << "Called: Car(brand, model, year)\n";
    }

    // Overload 3: brand and model only — year uses a fixed default in this example.
    Car(const string& b, const string& m) : brand(b), model(m), year(2024) {
        cout << "Called: Car(brand, model) — year defaulted to " << year << "\n";
    }

    void describe() const {
        cout << "  -> " << brand << " " << model << " (" << year << ")\n";
    }
};

int main() {
    cout << "Same class name, different parameter lists — the call site picks the overload:\n\n";

    Car c1; // matches Car()
    Car c2("Ford", "Mustang", 1969); // matches Car(brand, model, year)
    Car c3("Tesla", "Model 3");      // matches Car(brand, model) — not the 3-arg version

    cout << "\nFinal state of each object:\n";
    c1.describe();
    c2.describe();
    c3.describe();

    return 0;
}
