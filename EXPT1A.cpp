#include<iostream> 
#include<stdlib.h>
#include<string>
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

void student:: get_details() {
    cout<<"\nEnter the name : ";
    cin.ignore();
    getline(cin, name);
    cout<<"Enter the roll number : ";
    cin>>roll_no;
    for(int j = 0; j < 6; j++) {
        cout<<"\nEnter marks for "<<j+1<<" subject : ";
        cin>>marks[j];
        if(marks[j] > 100.0) {
            j--;
            cout<<"Entered marks is invalid, reenter marks\n";
        }
    }
}

void student::calc_percentage() {
    int total = marks[0]+marks[1]+marks[2]+marks[3]+marks[4]+marks[5];
    percentage = total/6.0;
}

void student:: display() {
    cout<<name<<" has achieved "<<percentage<<"%.\n";
}

int main() {
    int m;
    cout<<"Enter the number of students : ";
    cin>>m;
    student s[m];
    for(int i = 0; i < m; i++) {
        s[i].get_details();
        s[i].calc_percentage();
    }
    cout<<"\n";
    for(int i = 0; i < m; i++) {
        s[i].display();
    }
}