#include<iostream>
#include<string.h>
using namespace std;

class Car {
    int wheels;
    string engine;
    public:
    Car() {
        cout << "\nCreating an object of type Car" << endl;
    }
    void setWheels(int a) {
        wheels = a;
    }
    void setEngine(string a) {
        engine = a;
    }
    ~Car() {
        cout << "\nDestroying an object of type Car" << endl;
    }
};

class PassCar : public Car {
    int speed;
    public:
    PassCar() {
        cout << "\nCreating an object of type PassCar" << endl;
    }
    void setSpeed(int a = -1) {
        if(a > 90) {
            cout << "\nThe speed cannot be greater than 90km/h";
            return;
        }
        speed = a;
    }
    ~PassCar() {
        cout << "\nDestroying an object of type PassCar" << endl;
    }
};

class Truck : public Car {
    int number_of_axles;
    double load_capacity;
    public:
    Truck() {
        cout << "\nTruck object is created";
    }
    void setAxles(int a) {
        number_of_axles = a;
    }
    int getAxles() {
        return number_of_axles;
    }
    void setCapacity(double cp = -1) {
        if(cp > 100) {
            cout << "\nThe load cannot be greater than 100kg";
            return;
        }
        load_capacity = cp;
    }
    double getCapacity() {
        return load_capacity;
    }
    void display() {
        cout << number_of_axles << endl;
        cout << load_capacity << endl;
    }
    ~Truck() {
        cout << "\nTruck object is destroyed";
    }
};

int main() {
    Truck myTruck;
    myTruck.setAxles(4);
    myTruck.setCapacity(150); 
    myTruck.display();
    return 0;
}
