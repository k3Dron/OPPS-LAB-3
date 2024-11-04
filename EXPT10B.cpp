#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addUser() {
    ofstream file("directory.txt", ios::app);
    string name, number;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter telephone number: ";
    getline(cin, number);
    file << name << "," << number << endl;
    file.close();
    cout << "User added successfully." << endl;
}

void searchUser() {
    ifstream file("directory.txt");
    string line, name, searchName;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, searchName);
    bool found = false;
    
    while (getline(file, line)) {
        size_t pos = line.find(',');
        if (pos != string::npos) {
            name = line.substr(0, pos);
            if (name == searchName) {
                string number = line.substr(pos + 1);
                cout << "Telephone number: " << number << endl;
                found = true;
                break;
            }
        }
    }
    
    if (!found) {
        cout << "User not found." << endl;
    }

    file.close();
}

void updateUser() {
    ifstream file("directory.txt");
    ofstream temp("temp.txt");
    string line, name, searchName, number;
    cout << "Enter name to update: ";
    cin.ignore();
    getline(cin, searchName);
    bool found = false;

    while (getline(file, line)) {
        size_t pos = line.find(',');
        if (pos != string::npos) {
            name = line.substr(0, pos);
            if (name == searchName) {
                cout << "Enter new telephone number: ";
                getline(cin, number);
                temp << name << "," << number << endl;
                found = true;
            } else {
                temp << line << endl;
            }
        }
    }

    if (!found) {
        cout << "User not found." << endl;
    } else {
        cout << "Telephone number updated successfully." << endl;
    }

    file.close();
    temp.close();

    remove("directory.txt");
    rename("temp.txt", "directory.txt");
}

int main() {
    int choice;
    do {
        cout << "1. Add User" << endl;
        cout << "2. Search User" << endl;
        cout << "3. Update User" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                searchUser();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
