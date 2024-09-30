//create a class float that contains one float data members. overload all the four arithmetic so that they operate on the objects of float.
#include <iostream>
using namespace std;

class Float {
private:
    float value;

public:
    Float(float v = 0.0) : value(v) {}

    Float operator+(const Float& other) const {
        return Float(value + other.value);
    }

    Float operator-(const Float& other) const {
        return Float(value - other.value);
    }

    Float operator*(const Float& other) const {
        return Float(value * other.value);
    }

    Float operator/(const Float& other) const {
        if (other.value != 0)
            return Float(value / other.value);
        else {
            cout << "Error: Division by zero!" << endl;
            return Float(0);
        }
    }

    friend ostream& operator<<(ostream& os, const Float& f) {
        os << f.value;
        return os;
    }
};

int main() {
    Float f1(10.5), f2(2.5);

    Float sum = f1 + f2;
    Float diff = f1 - f2;
    Float prod = f1 * f2;
    Float quot = f1 / f2;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;
    cout << "Quotient: " << quot << endl;

    return 0;
}
