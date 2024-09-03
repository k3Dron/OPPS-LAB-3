#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

class employee {
private:
    string name;
    char id[10];
    float salary;
    float perk;
    int state;

public:
    void st_salary();
    void get_details();
    void display_details();
};

void employee::st_salary() {
    if(perk == 0) {
        state = 0;
    }
    else if(salary < salary + perk && salary + perk >= 50) {
        state = 1;
    } else {
        state = -1;
    }
}

void employee::get_details() {
    cout<<"Enter the employee name : ";
    cin.ignore();
    getline(cin, name);
    cout<<"Enter the employee id : ";
    cin>>id;
    cout<<"Enter the employee salary (in Rs): ";
    cin>>salary;
    int m = salary/10000;
    if(m%3 == 0) {
        perk = salary*0.3;
        st_salary();
        return;
    } else if(m%2 == 0) {
        perk = -salary*0.2;
        st_salary();
        return;
    } else {
        perk = 0;
        st_salary();
        return;
    }
    
}

void employee::display_details() {
    if(state == 1) {
        cout<<name<<"\t"<<id<<"\t"<<salary<<"\t"<<salary+perk<<"\t\t"<<"Promoted"<<"\t";
    } else if(state == -1) {
        cout<<name<<"\t"<<id<<"\t"<<salary<<"\t"<<salary+perk<<"\t\t"<<"Demoted"<<"\t";
    } else {
        cout<<name<<"\t"<<id<<"\t"<<salary<<"\t"<<salary+perk<<"\t\t"<<"No Change"<<"\t";
    }
}

int main() {
    int n;
    employee e[10];
    cout<<"Enter the number of employees in the record : ";
    cin>>n;
    for(int i = 0; i < n; i++) {
        e[i].get_details();
        cout<<"\n";
    }
    cout<<"\nName\tID\tSalary\tUpdated Salary\tState\n";
    for(int i = 0; i < n; i++) {
        e[i].display_details();
        cout<<"\n";
    }
}
