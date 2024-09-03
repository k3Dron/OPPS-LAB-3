#include<iostream>
using namespace std;

int sum = 0;

class first {
    private:
    int a;
    public:
    friend void add(class first i,class second j);
    void get_a() {
        cout<<"This is an inline function. Enter the value of a : ";
        cin>>a;
    }
};

class second {
    private:
    int b;
    public:
    friend void add(class first i,class second j);
    void get_b() {
        cout<<"This is an inline function. Enter the value of b : ";
        cin>>b;
    }
};

void add(class  first i,class second j) {
    cout<<"This is a friend function, the has access of the private members of class 'First' and class 'Second' and calculates the sum of the members.\n";
    sum = i.a + j.b;
}
int main() {
    first obj1;
    second obj2;
    obj1.get_a();
    obj2.get_b();
    add(obj1, obj2);
    cout<<"The value of the sum is "<<sum;
}