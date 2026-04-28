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

    Student s1; // object is created
    s1.name = "John";
    s1.cgpa = 9.5;
    s1.getPercentage();

    return 0;
}