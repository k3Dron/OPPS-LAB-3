#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};
class Mammal : public Animal {
public:
    void walk() {
        cout << "This mammal walks on land." << endl;
    }
};
class Bird : public Animal {
public:
    void fly() {
        cout << "This bird flies in the sky." << endl;
    }
};
class Fish : public Animal {
public:
    void swim() {
        cout << "This fish swims in water." << endl;
    }
};

int main() {
    Mammal mammal;
    Bird bird;
    Fish fish;
    cout << "Mammal:" << endl;
    mammal.eat();
    mammal.walk();
    cout << "\nBird:" << endl;
    bird.eat();
    bird.fly();
    cout << "\nFish:" << endl;
    fish.eat();
    fish.swim();
    return 0;
}
