/*
explain the difference between constructor and destructor
- a constructor is a class member fn that executes automatically when the object is instantiated.
a destructor is a class member fn that executes automatically when the object is out of scope.

explain the differnce between default constructor and other const
-a default constructor assigns memory space for members on creation of object, but does not assign any value to them.
other constructors can be used to assign values to the members when the object has already been created.

*exp diff bet copy and assignment operator
-copy constructor is used to copy 

diff between access and utility fn
-access fn is a public class member functions
utility is aa private class member fn that is used only within the class to perform any fn

diff class vs struct
-same, but only diff is access specifier for struct is private.

what name must const hv
-same as class

wt name must destructor hv?
-same as class, with tylde

how many const can a class hv?
-no limit, but constructor overloading

des can a class hv?
-one

how and why is a scope res operator is used in class op
-to resolve external referances.

which member fn are created automatically by constructor,  if not included (by prop) in the class def
-constructor
copy
destructor
overloaded assignment operator

a copy const called in the following code
widget f(widget u) {
widget v(u);v
widget w = v;
retrun w;
}
main() {
widget x;
widget y = f(f(x));
}
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

int i = 0;

class stg {
    private:
    string s;
    string a;
    string b;

    public:
    stg() {
        i++;
    };

    stg(string s1) {
        i++;
        s = s1;
    }

    stg(string p, string q) {
        i++;
        a = p;
        b = q;
    }

    string access();
    void  get_string();
    void  add_strings();
    void  display();

    ~stg() {
        i--;
    };
};

string stg::access() {
    return s;
}

void stg::get_string() {
    cout<<"Enter the string : ";
    cin>>s;
}

void stg::add_strings() {
        s = a + b;
        cout<<"The added string is : "<<s<<"\n";
    }

void stg::display() {
    cout<<"The string is "<<s<<"\n";
}

int main() {
    stg s1, s2(" done");
    s1.get_string();
    {
        stg s3(s1.access(), s2.access());
        s3.add_strings();
        s3.display();
        cout<<"The total number of live objects is "<<i<<endl;
    }
    s1.display();
    s2.display();
    //s3.display();
    cout<<"The total number of live objects is "<<i<<endl;
    cout<<"s3 could not be printed as it as out of scope!";
}

