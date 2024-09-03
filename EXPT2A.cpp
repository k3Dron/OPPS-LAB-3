#include <iostream>
using namespace std;

int call_by_reference(int & i, int j) {
    i++;
    j++;
    return j;
}

int main() {
    int a = 10;
    int b = 20;
    cout<<"The values of 'a' and 'b' before call_by_reference function is called is "<<a<<" and "<<b<<"\n";
    call_by_reference(a, b);
    cout<<"The values of 'a' and 'b' after call_by_reference function is called is "<<a<<" and "<<b<<"\n";
    cout<<"\nThe value of 'a' has changed cause 'a' was passed by reference, while 'b' was not so it remained the same.";
}