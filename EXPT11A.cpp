#include <iostream>
#include <string>

using namespace std;

void stringAssignmentAndConcatenation() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    string str3 = str1 + " " + str2;
    cout << "Concatenated String: " << str3 << endl;
}

void compareStrings() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    if (str1 == str2) {
        cout << "Strings are equal." << endl;
    } else {
        cout << "Strings are not equal." << endl;
    }
}

void findSubstringsAndCharacters() {
    string str, subStr;
    char ch;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Enter substring to find: ";
    getline(cin, subStr);
    size_t found = str.find(subStr);
    if (found != string::npos) {
        cout << "'" << subStr << "' found at: " << found << endl;
    } else {
        cout << "'" << subStr << "' not found." << endl;
    }
    cout << "Enter character to find: ";
    cin >> ch;
    cin.ignore();
    found = str.find(ch);
    if (found != string::npos) {
        cout << "Character '" << ch << "' found at: " << found << endl;
    } else {
        cout << "Character '" << ch << "' not found." << endl;
    }
}

void swapStrings() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    cout << "Before Swap: " << endl;
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    str1.swap(str2);
    cout << "After Swap: " << endl;
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. String Assignment & Concatenation\n";
        cout << "2. Compare Strings\n";
        cout << "3. Find Substrings & Characters\n";
        cout << "4. Swap Strings\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                stringAssignmentAndConcatenation();
                break;
            case 2:
                compareStrings();
                break;
            case 3:
                findSubstringsAndCharacters();
                break;
            case 4:
                swapStrings();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
