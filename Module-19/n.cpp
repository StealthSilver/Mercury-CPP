// Practice: Person base class; Student derived with studentID and displayStudentInfo.

#include <iostream>
#include <string>

class Person {
   protected:
    std::string name_;
    int age_;

   public:
    Person(std::string name, int age)
        : name_(std::move(name)), age_(age) {}

    virtual ~Person() = default;
};

class Student : public Person {
   public:
    Student(std::string name, int age, std::string student_id)
        : Person(std::move(name), age), student_id_(std::move(student_id)) {}

    void displayStudentInfo() const {
        std::cout << "Name: " << name_ << "\n";
        std::cout << "Age: " << age_ << "\n";
        std::cout << "Student ID: " << student_id_ << "\n";
    }

   private:
    std::string student_id_;
};

int main() {
    Student student("Alice", 20, "S12345");
    student.displayStudentInfo();
    return 0;
}
