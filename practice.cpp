#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

class A {
    int a;
    int b;
    public:
    A(int i, int j): a(i), b(a+j) {

    }
    virtual void display() {
        cout<<a<<" "<<b<<endl;
    }
};

class B: protected A {
    int b;
    public:
    B(int i, int j, int k): A(i, j), b(k) {}
    void getdata(int i) {
        b = i;
    }
    void display1() {
        display();
        cout<<b<<endl;
    }
};

ostream & unit(ostream & output) {
        output << "Rs";
        return output;
}

ostream & currency(ostream & output) {
    output<< unit << setw(10) << setprecision(3) << setfill('*');
}


int main() {
    cout<<currency<<34.12345<<endl;    
}