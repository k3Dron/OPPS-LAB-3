#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char str[100];

public:
    MyString() {
        str[0] = '\0';
    }

    MyString(const char* s) {
        strcpy(str, s);
    }

    MyString operator+(const MyString& s) {
        MyString temp;
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    int length() const {
        return strlen(str);
    }

    void display() const {
        cout << str;
    }

    friend void compareStrings(const MyString& s1, const MyString& s2);
};

void compareStrings(const MyString& s1, const MyString& s2) {
    if (s1.length() < s2.length()) {
        cout << "String 1 is smaller: ";
        s1.display();
    } else if (s1.length() > s2.length()) {
        cout << "String 2 is smaller: ";
        s2.display();
    } else {
        cout << "Both strings are of equal length.";
    }
    cout << endl;
}

int main() {
    MyString s1("Hello");
    MyString s2("World");
    MyString s3;

    s3 = s1 + s2;
    cout << "Concatenated string: ";
    s3.display();
    cout << endl;

    compareStrings(s1, s2);

    return 0;
}
