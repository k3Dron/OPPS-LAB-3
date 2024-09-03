#include<iostream>

using namespace std;

int add(int a, int b) {
    return a+b;
}

float add(float a, float b) {
    return a+b;
}

string add(string a, string b) {
    return a+b;
}

int main() {
    int i = 2, j = 3;
    float k = 3.14, l = 4.32;
    string m = "Hello ", n = "World!";
    cout<<"The add function taking int as parameters is being called and the adding yields "<<add(i, j);
    cout<<"\nThe add function taking float as parameters is being called and the adding yields "<<add(k, l);
    cout<<"\nThe add function taking string as parameters is being called and the adding yields "<<add(m, n);
}