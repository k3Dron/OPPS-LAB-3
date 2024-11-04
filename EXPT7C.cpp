#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setw(40) << setfill('-') << " "<<endl;
    cout << left << setw(15) << setfill(' ') << "Name"
         << right << setw(10) << "Age"
         << right << setw(15) << "Occupation" << endl;
    cout << setw(40) << setfill('-') << ""<<endl;
    cout << left << setw(15) << setfill(' ') << "Alice"
         << right << setw(10) << 25
         << right << setw(15) << "Engineer" << endl;

    cout << left << setw(15) << "Bob"
         << right << setw(10) << 30
         << right << setw(15) << "Doctor" << endl;

    cout << left << setw(15) << "Charlie"
         << right << setw(10) << 28
         << right << setw(15) << "Artist" << endl;

    return 0;

}