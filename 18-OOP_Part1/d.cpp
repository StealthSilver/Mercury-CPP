#include <iostream>
#include <string>
using namespace std;

// Encapsulation: data is private; outside code uses getters/setters only.
class User {
private:
    string name;
    int age;
    string email;
    string password;

public:
    // --- name ---
    string getName() const { return name; }
    void setName(const string& value) { name = value; }

    // --- age ---
    int getAge() const { return age; }
    void setAge(int value) { age = value; }

    // --- email ---
    string getEmail() const { return email; }
    void setEmail(const string& value) { email = value; }

    // --- password (sensitive field: no direct public access) ---
    string getPassword() const { return password; }
    void setPassword(const string& pass) { password = pass; }
};

int main() {
    User u1;

    u1.setName("John");
    u1.setAge(20);
    u1.setEmail("john@example.com");
    u1.setPassword("123456");

    cout << "Name: " << u1.getName() << endl;
    cout << "Age: " << u1.getAge() << endl;
    cout << "Email: " << u1.getEmail() << endl;
    cout << "Password: " << u1.getPassword() << endl;

    return 0;
}
