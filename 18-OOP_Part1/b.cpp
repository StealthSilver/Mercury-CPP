#include <iostream>
#include <string>
using namespace std;

class User {
public:
    // properties
    string name;
    int age;
    string email;
    string password;

    // methods
    void login() {
        cout << "Login successful" << endl;
    }
};

int main() {

    User u1; // object is created
    u1.name = "John";
    u1.age = 20;
    u1.email = "john@example.com";
    u1.password = "123456";
    u1.login();

    return 0;
}