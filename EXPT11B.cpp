#include <iostream>
#include <string>
#include <iterator>

using namespace std;

void outputStringWithIterators() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "String output using iterators: ";
    for (string::iterator it = str.begin(); it != str.end(); ++it) {
        cout << *it;
    }
    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Output String with Iterators\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                outputStringWithIterators();
                break;
            case 2:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 2);

    return 0;
}
