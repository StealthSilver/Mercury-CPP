#include <iostream>
using namespace std;

class User {
    private:
    string password;
    public:
    string name;
    int age;
    string email;

    // getters
    string getPassword(){
        return password;
    }

    // setters
    void setPassword(string pass){
        password = pass;
    }
};

int main(){
    User u1; // object is created
    u1.name = "John";
    u1.age = 20;
    u1.email = "john@example.com";
    u1.setPassword("123456");
    cout << "Password: " << u1.getPassword() << endl;
    return 0;
}