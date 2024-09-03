#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base class constructor called" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived class constructor called" << endl;
    }
};

class EDerived : public Derived {
    public: 
    EDerived() {
        cout << "EDerived class constructor called" << endl;
    }
};

int main() {
    EDerived obj;
    return 0;
}
