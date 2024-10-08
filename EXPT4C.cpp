#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    friend ostream& operator<<(ostream& out, const Complex& c);

    friend istream& operator>>(istream& in, Complex& c);
};

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real << "+i" << c.imag;
    return out;
}

istream& operator>>(istream& in, Complex& c) {
    cout << "Enter Real Part: ";
    in >> c.real;
    cout << "Enter Imaginary Part: ";
    in >> c.imag;
    return in;
}

int main() {
    Complex c1;
    cout << "Enter a complex number:\n";
    cin >> c1;
    cout << "The complex number is: " << c1 << endl;
    return 0;
}
