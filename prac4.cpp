/*define two classes Polar and Rectangle to represent points in the polar and recangle systems. Use conversion routines to convert from one system to the other*/
#include<iostream>
#include<cmath>
using namespace std;
class Rectangle;
class Polar {
    float radius;
    float angle;
    public:
    Polar(float r, float a) : radius(r), angle(a){

    }
    Polar(Rectangle& a) {
        float r = sqrt(radius + a.getx());
        float a = atan(a.gety()/a.getx())*180/M_PI;
        Polar b(r, a);
        return b;
    }
    float getRadius() {return radius;}
    float getAngle() {return angle;}
    void display() const {
        cout << "(" << radius << ", " << angle << " degrees)" << endl;
    }
};

class Rectangle {
    float x;
    float y;
    public:
    Rectangle(float x, float y) : x(x), y(y) {}
    Rectangle(Polar& p) {
        float a = p.getRadius*sin(p.getAngle*M_PI/180);
        float b = p.getRadius*cos(p.getAngle*M_PI/180);
        Rectangle a(a, b);
        return a;
    }
    float getx() {return x;}
    float gety() {return y;}
    
};