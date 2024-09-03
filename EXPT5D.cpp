#include<iostream>
#include<string.h>
using namespace std;

class Car {
    int wheels;
    string engine;
    public:
    Car() {
        cout<<"Creating an object of type Car";
    }
    void setWheels(int a) {
        wheels = a;
    }
    void setEngine(string a) {
        engine = a;
    }
};

class PassCar {
    int speed;
    public:
    PassCar() {
        cout<<"Creating an object of type PassCar";
    }
    void setSpeed(int a) {
        speed = a;
    }
};

class Truck : public Car {
    int number_of_axles;
    double load_capacity;
    public:
    void setAxles(int a) {
        number_of_axles = a;
    }
    int getAxis() {
        return number_of_axles;
    }
    void  setCapacity(double cp) {
        load_capacity = cp;
    }
    double getCapacity() {
        return load_capacity;
    }
    void display() {
        cout<<number_of_axles<<end;
        cout<<load_capacity<<endl;
    }
}