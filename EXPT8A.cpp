#include<iostream>
using namespace std;

template <typename T>

void swap_num(T& x, T&y) {
    T t = x;
    x = y;
    y = t;
}

int main() {
    int i = 23;
    int j = 32;
    cout<<"Before swapping we have :  i = "<<i<<" and j = : "<<j<<endl;
    swap_num(i,j);
    cout<<"After swapping we have :  i = "<<i<<" and j = : "<<j<<endl;
    i = 2.3;
    j = 3.2;
    cout<<"Before swapping we have :  i = "<<i<<" and j = : "<<j<<endl;
    swap_num(i,j);
    cout<<"After swapping we have :  i = "<<i<<" and j = : "<<j<<endl;
}