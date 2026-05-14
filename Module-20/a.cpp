#include <iostream>
using namespace std;

void func(){
    cout<<"function called"<<endl;
    func();
}

int main(){
    func();
    return 0;
}