#include <iostream>
#include <string>
using namespace std;

class User {
private:
    int id;
    string password;

public:
    string username;

    // id is set only here (private member).
    User(int id, const string& uname, const string& pwd)
        : id(id), password(pwd), username(uname) {}

    string getPassword() const { return password; }

    void setPassword(const string& newPassword) { password = newPassword; }
};

int main() {
    User u(1, "alice", "secret123");

    cout << "username: " << u.username << ", password: " << u.getPassword() << "\n";

    u.setPassword("newSecret456");
    cout << "After setPassword: " << u.getPassword() << "\n";

    return 0;
}
