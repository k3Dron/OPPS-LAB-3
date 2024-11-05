#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void stringToStream() {
    string str;
    cout << "Enter a string to process: ";
    getline(cin, str);

    stringstream ss(str);
    string word;

    cout << "Words in the string: ";
    while (ss >> word) {
        cout << word << " ";
    }
    cout << endl;
}

void numbersToString() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cin.ignore();

    stringstream ss;
    ss << num1 << " " << num2;

    string str = ss.str();
    cout << "String representation: " << str << endl;
}

void stringToNumber() {
    string str;
    cout << "Enter a string containing numbers: ";
    getline(cin, str);

    stringstream ss(str);
    int num;

    cout << "Numbers extracted from the string: ";
    while (ss >> num) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Convert String to Stream and Output Words\n";
        cout << "2. Convert Numbers to String\n";
        cout << "3. Convert String to Numbers\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                stringToStream();
                break;
            case 2:
                numbersToString();
                break;
            case 3:
                stringToNumber();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
