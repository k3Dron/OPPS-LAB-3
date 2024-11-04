#include<iostream>
#include<cmath>
using namespace std;

void squareroot(int a);

void squareroot(int a)
{
    cout<<"Inside function body:"<<endl;
    try
    {
        if(a<0)
        throw a;
        else
        cout<<"Squareroot of number "<<a<<"="<<sqrt(a)<<endl;
    }
    catch(int)
    {
        cout<<"Exception caught inside function body(no. cannot be negative)"<<endl;
        throw;
    }
    cout<<"End of fuction"<<endl;
}

int main()
{
    cout<<"inside main body"<<endl;
    try
    {
        cout<<"Calculating square root of:"<<endl;
        cout<<"1)12"<<endl;
        squareroot(12);
        cout<<"\n2)-5"<<endl;
        squareroot(-5);
    }
    catch(int)
    {
        cout<<"Exception caught inside main function"<<endl;
    }
    cout<<"End of main"<<endl;
}