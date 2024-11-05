#include <iostream>
#include <stdexcept>

using namespace std;

void testExceptions(int value) {
    try {
        if (value == 0) {
            throw runtime_error("Runtime error: Division by zero");
        } else if (value < 0) {
            throw invalid_argument("Invalid argument: Negative value");
        } else {
            cout << "Value is: " << value << endl;
        }
    } catch (const runtime_error& e) {
        cout << "Caught runtime_error: " << e.what() << endl;
    } catch (const invalid_argument& e) {
        cout << "Caught invalid_argument: " << e.what() << endl;
    } catch (...) {
        cout << "Caught an unknown exception" << endl;
    }
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    testExceptions(num);

    return 0;
}
