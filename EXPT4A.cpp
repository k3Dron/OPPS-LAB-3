#include<iostream>
#include<stdlib.h>
using namespace std;

class room {
    private: int n;

    public:
    room() {
        n = 0;
    }

    void operator ++() {
        n = n + 1;
    }

    void operator ++(int) {
        n = n + 1;
    }

    void operator --() {
        n = n - 1;
    }

    void operator --(int) {
        n = n - 1;
    }

    void display() {
        cout<<"The number of people in the room is "<<n;
    }
};

int main() {
    room r;
    int i;
    do {
        cout<<"\n1. Enter\n2. Leave\n3. Check\n0. Exit\n";
        cin>>i;
        switch (i) {
            case 1: r++;
            break;
            case 2: r--;
            break;
            case 3: r.display();
            break;
            default: break;
        }
    }
    while(i > 0);
    cout<<"\nThe code has been exited.";
    return 0;
}