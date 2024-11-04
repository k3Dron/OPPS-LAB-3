#include <iostream>
#include <string>
using namespace std;

void innerFunction(string phoneNumber) {
    bool isFloat = false;

    for (int i = 0; i < phoneNumber.length(); ++i) {
        if (phoneNumber[i] == '.') {
            isFloat = true;
            break;
        }
        if (!isdigit(phoneNumber[i])) {
            throw string("Invalid input: Phone number contains non-digit characters.");
        }
    }

    if (isFloat) {
        throw string("Invalid input: Phone number cannot be a float.");
    }

    cout << "Phone number is valid: " << phoneNumber << endl;
}

void outerFunction(string phoneNumber) {
    try {
        innerFunction(phoneNumber);
    } catch (string e) {
        cout << "Caught in outerFunction: " << e << endl;
        throw;
    }
}

int main() {
    string phoneNumber;
    cout << "Enter phone number: ";
    cin >> phoneNumber;

    try {
        outerFunction(phoneNumber);
    } catch (string e) {
        cout << "Caught in main: " << e << endl;
    }

    return 0;
}
