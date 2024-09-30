/*design a class polar which describes a point in the plane using polar coordinates radius and angle. a point in point coordinates is shown in fig
use the overloaded + operator to add two objects of polar.
note that we cannot add polar values of two points directly. this requires first the convesion of pointsinto rectangle coordinates*/
#include<iostream>
#include<cmath>
using namespace std;

class Polar {
    float radius;
    float angle; 
public:
    Polar(float r = 0.0, float a = 0.0) : radius(r), angle(a) {}

    float getRadius() const {
        return radius;
    }

    float getAngle() const {
        return angle;
    }

    Polar operator+(const Polar& n) const {
        float x1 = radius * cos(angle * M_PI / 180.0);
        float y1 = radius * sin(angle * M_PI / 180.0);
        float x2 = n.getRadius() * cos(n.getAngle() * M_PI / 180.0);
        float y2 = n.getRadius() * sin(n.getAngle() * M_PI / 180.0);
        float x = x1 + x2;
        float y = y1 + y2;
        float rad = sqrt(x * x + y * y);
        float deg = atan2(y, x) * 180.0 / M_PI;
        return Polar(rad, deg);
    }

    void display() const {
        cout << "(" << radius << ", " << angle << " degrees)" << endl;
    }
};

int main() {
    Polar a(4, 60);
    Polar b(5, 30);
    Polar c = a + b;
    c.display();
    return 0;
}
