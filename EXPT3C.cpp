
#include<iostream>
using namespace std;

class cylinder {
    private:
    float radius;
    float height;
    public: 
    cylinder(float r, float h) {
        radius = r;
        height = h;
    }

    ~cylinder() {
        cout<<"\nobject deleted";
    }
    void get();

    void display();
};

void cylinder:: display() {
    cout<<"Raduis of cylinder is : "<<radius;
    cout<<"\nHeight of cylinder is : "<<height;
    cout<<"\nArea of cylinder is : "<<3.14*radius*height;
}

void cylinder:: get() {
    
}

int main() {
    float i,j;
    cout<<"Enter the radius :";
    cin>>i;
    cout<<"Enter the height :";
    cin>>j;
    cout<<"\nCreating a constructor of cylinders with the given inputs...\n";
    cylinder c1(i, j);
    cout<<"\nCalling display functions...\n";
    c1.display();
    cout<<"\nCreating a copy of the already created object..\n";
    cylinder c2(c1);
    cout<<"\nCopy of the already created object has been created..\n";
    cout<<"\nCalling display functions...\n";
    c2.display();
    cout<<"\nDestructor called, Deallocating memory for floats variables...\n";
}