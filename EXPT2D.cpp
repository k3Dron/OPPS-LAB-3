/*friend function is defined as the function that can have access to the data members of the class. 
syntax : data_type friend function
what is a class?
what is an object?
what are the components of the class?
when an object is created, whta happens in the memory?
when an object is static, dynamic or both?
can objeccts commmunicate with each other?
what is data hiding in c++?
what is ADT?
*/
#include<iostream>
using namespace std;


class Pair {
    private:
    float first;
    float second;
    public:
    friend void swapValues(class Pair &obj);

    void get_values() {
        cout<<"first = ";
        cin>>first;
        cout<<"second = ";
        cin>>second;
    }

    void display() {
        cout<<first<<"\t"<<second<<"\n";
    }

};

void swapValues(class Pair &obj) {
    float t = obj.first;
    obj.first = obj.second;
    obj.second = t;
}

int main() {
 int n;
 cout<<"Enter the number of swapping to be done : ";
 cin>>n;
 Pair p[100];
 for(int i = 0; i < n; i++) {
    cout<<"Enter the "<<i+1<<"th values: \n";
    p[i].get_values();
    swapValues(p[i]);
    cout<<"\n";
 }
 cout<<"Displaying Updated output\n";
 cout<<"Index\tfirst\tsecond\n";
  cout<<"-------------------------\n";
 for(int i =0 ; i < n; i++) {
    cout<<i+1<<"\t";
    p[i].display();
 }
}
