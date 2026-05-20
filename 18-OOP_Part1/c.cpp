#include <iostream>
using namespace std;

class User {
    private:
    string password;
    public:
    string name;
    int age;
    string email;
};

int main(){
    User u1; // object is created
    u1.name = "John";
    u1.age = 20;
    u1.email = "john@example.com";
    return 0;
}