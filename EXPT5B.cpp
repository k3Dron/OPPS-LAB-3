#include <iostream>
using namespace std;
class Person {
public:
    void display() {
        cout << "This is a person." << endl;
    }
};
class Student : virtual public Person {
public:
    void study() {
        cout << "This person is studying." << endl;
    }
};
class Employee : virtual public Person {
public:
    void work() {
        cout << "This person is working." << endl;
    }
};
class PartTimeStudentEmployee : public Student, public Employee {
public:
    void display() {
        cout << "This person is a part-time student and employee." << endl;
    }
};

int main() {
    PartTimeStudentEmployee ptse;
    ptse.display();
    ptse.study();
    ptse.work();
    return 0;
}
