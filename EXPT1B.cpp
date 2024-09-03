#include <iostream>
#include <string>
#include <vector>
using namespace std;

class student {
private:
    string name;
    int roll_no;
    float marks[6];
    float percentage;

public:
    void get_details();
    void calc_percentage();
    void display();
};

void student::get_details() {
    cout << "\nEnter the name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the roll number: ";
    cin >> roll_no;
    for (int j = 0; j < 6; j++) {
        cout << "\nEnter marks for subject " << j + 1 << ": ";
        cin >> marks[j];
        if (marks[j] > 100.0) {
            j--;
            cout << "Entered marks are invalid, reenter marks\n";
        }
    }
}

void student::calc_percentage() {
    int total = marks[0] + marks[1] + marks[2] + marks[3] + marks[4] + marks[5];
    percentage = total / 6.0;
}

void student::display() {
    cout << name << " has achieved " << percentage << "%.\n";
}

int main() {
    int m;
    cout << "Enter the number of students: ";
    cin >> m;
    vector<student> students(m);
    for (int i = 0; i < m; i++) {
        students[i].get_details();
        students[i].calc_percentage();
    }

    cout << "\n";
    for (int i = 0; i < m; i++) {
        students[i].display();
    }

    return 0;
}

