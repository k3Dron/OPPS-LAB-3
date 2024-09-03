#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    void display() const {
        std::cout << "Value: " << value << std::endl;
    }

    MyClass operator+(int num) const {
        return MyClass(value + num);
    }

    friend MyClass operator+(int num, const MyClass& obj) {
        return MyClass(num + obj.value);
    }

    MyClass operator*(const MyClass& other) const {
        return MyClass(value * other.value);
    }

    MyClass operator-(int num) const {
        return MyClass(value - num);
    }

    friend MyClass operator-(int num, const MyClass& obj) {
        return MyClass(num - obj.value);
    }
};

int main() {
    MyClass x(10), y(2);

    std::cout << "Initial values:" << std::endl;
    x.display();
    y.display();

    x = 5 + y;
    std::cout << "After x = 5 + y:" << std::endl;
    x.display();

    x = x * y;
    std::cout << "After x = x * y:" << std::endl;
    x.display();

    x = y - 5;
    std::cout << "After x = y - 5:" << std::endl;
    x.display();

    return 0;
}