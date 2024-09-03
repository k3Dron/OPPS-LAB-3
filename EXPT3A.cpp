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
    cout<<"Creating a constructor of cylinders with the given inputs...\n";
    cylinder c(i, j);
    cout<<"Calling display functions...\n";
    c.display();
}