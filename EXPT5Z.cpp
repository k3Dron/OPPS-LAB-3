#include<iostream>
#include<string>
using namespace std;

class grandfather {
    protected:
    int age;
    int pace;
    int iq;
    public:
    grandfather() {
        age = 70;
        pace = 5;
        iq = 60;
    }
    void display() {
        cout << "Age: " << age << endl;
        cout << "Pace: " << pace << endl;
        cout << "IQ: " << iq << endl;
    }
};

class father: public grandfather {
    protected:
    int jump;
    public:
    father() {
        age = 50;
        pace = 20;
        iq = 75;
        jump = 10;
    }

    void display() {
        cout << "Age: " << age << endl;
        cout << "Pace: " << pace << endl;
        cout << "IQ: " << iq << endl;
        cout << "Jump: " << jump << endl;
    }
};

class son: public father {
    private:
    int strength;
    public:
    son() {
        age = 20;
        pace = 30;
        iq = 90;
        jump = 15;
        strength = 80;
    }

    void display() {
        cout << "Age: " << age << endl;
        cout << "Pace: " << pace << endl;
        cout << "IQ: " << iq << endl;
        cout << "Jump: " << jump << endl;
        cout << "Strength: " << strength << endl;
    }
};

int main() {
    grandfather g;
    father f;
    son s;
    g.display();
    f.display();
    s.display();
    return 0;
}
