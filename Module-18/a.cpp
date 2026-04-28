#include <iostream>
using namespace std;

class Student {
   
    // properties 
    string name;
    float cgpa;

    // methods

    void getPercentage(){
        cout << "Percentage: " << cgpa * 10 << endl;
    }
};

int main() {

    return 0;
}