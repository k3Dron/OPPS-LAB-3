#include <iostream>
#include <stdexcept>

using namespace std;

void divide(double num1, double num2) {
    try {
        if (num2 == 0) {
            throw runtime_error("Division by zero error");
        } else {
            cout << "Result: " << num1 / num2 << endl;
        }
    } catch (const runtime_error& e) {
        cout << "Caught in divide: " << e.what() << endl;
        throw;
    }
}

int main() {
    double a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    try {
        divide(a, b);
    } catch (const runtime_error& e) {
        cout << "Caught in main: " << e.what() << endl;
    }

    return 0;
}
