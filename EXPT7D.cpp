#include <iostream>
#include <string>
#include <ctime>

using namespace std;

char rest_name[100];
char rest_add[100];
int gstin_no;
int rest_ph_no;

char name[100];
string state;
char add[100]; 
int gstin;
int ph_no;

string menu[] = {"Tea", "Coffee", "Juice", "Vada Pav", "Bhaji Pav", "Puri Bhaji"};
float price[] = {10, 15, 20, 30, 40, 40};
int hsn[] = {123231, 453456, 432345, 889776, 544323, 454222};
int counter;
int order[6][2];

string one[] = { "", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
string ten[] = { "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };

string numToWords(int n, string s) {
    string str = "";
    if (n > 19) {
        str += ten[n / 10] + one[n % 10];
    } else {
        str += one[n];
    }
    if (n) {
        str += s;
    }
    return str;
}

string inwords(int n) {
    string out;

    out += numToWords((n / 10000000), "Crore ");
    out += numToWords(((n / 100000) % 100), "Lakh ");
    out += numToWords(((n / 1000) % 100), "Thousand ");
    out += numToWords(((n / 100) % 10), "Hundred ");

    if (n > 100 && n % 100) {
        out += "and ";
    }
    out += numToWords((n % 100), "");

    return out;
}

int invoice() {
    srand(time(0)); 
    return 100000 + rand() % 900000; 
}

string date() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string date = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday);
    return date;
}

string time() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string currentTime = 
        (ltm->tm_hour < 10 ? "0" : "") + to_string(ltm->tm_hour) + ":" +
        (ltm->tm_min < 10 ? "0" : "") + to_string(ltm->tm_min) + ":" +
        (ltm->tm_sec < 10 ? "0" : "") + to_string(ltm->tm_sec);
    return currentTime;
}


void get_rest_info() {
    cout << "Enter Restaurant Name: ";
    cin.getline(rest_name, 100);
    cout << "Enter Restaurant Address: ";
    cin.getline(rest_add, 100);
    cout << "Enter Restaurant GSTIN No: ";
    cin >> gstin_no;
    cin.ignore();
    cout << "Enter Restaurant Phone Number: ";
    cin >> rest_ph_no;
}

void get_rcvr_info() {
    cin.ignore();
    cout << "Enter Receiver Name: ";
    cin.getline(name, 100);
    cout << "Enter Receiver Address: ";
    cin.getline(add, 100);
    cout << "Enter Receiver State: ";
    cin >> state;
    cin.ignore();
    cout << "Enter Receiver GSTIN: ";
    cin >> gstin;
    cin.ignore();
    cout << "Enter Receiver Phone Number: ";
    cin >> ph_no;
    cin.ignore();
}

void get_menu() {
    counter = 0;
    for (int i = 0; i < 6; i++) {
        cin >> order[i][0];
        if (order[i][0] == -1) break;
        counter++;
        cin >> order[i][1];
        cout << endl;
    }
}

void dis_menu() {
    cout << "Menu" << endl;
    cout.width(5);
    cout << "Ind";
    cout.width(15);
    cout << "Item";
    cout.width(8);
    cout << "Price" << endl;
    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        cout.width(5);
        cout << i;
        cout.width(15);
        cout << menu[i];
        cout.width(8);
        cout << price[i] << endl;
    }
    cout << "Enter the index corresponding to the item you need along with the quantity. Enter -1 to generate bill\n";
}

void display() {
    cout.width(60);
    cout.fill('*');
    cout << "" << endl;
    cout.fill(' ');
    cout.width(35);
    cout << "Restaurant Bill" << endl;
    cout.width(60);
    cout.fill('*');
    cout << "" << endl;
    cout.fill(' ');
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "Restaurant Name: ";
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout<< rest_name << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "GSTIN No: ";
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout<< gstin_no << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "Address: " ;
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout<< rest_add << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "Invoice No: " ;
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout<< invoice() << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "Phone Number: " ;
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout<< rest_ph_no << endl;
    cout.width(60);
    cout.fill('*');
    cout << "" << endl;
    cout.fill(' ');
    cout << "Bill To:" << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "Name: ";
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout<< name << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "GSTIN: " ;
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout << gstin << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "Address: ";
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout  << add << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "State: ";
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout << state << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "Phone No: " ;
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout << ph_no << endl;
    string idate = date();
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "Date: " ;
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout << idate << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "Time: " ;
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout << time() << endl;
    cout.width(60);
    cout.fill('*');
    cout << "" << endl;
    cout.fill(' ');
    cout.width(4);
    cout << "S.No";
    cout.width(20);
    cout << "Goods Description";
    cout.width(10);
    cout << "HSN";
    cout.width(5);
    cout << "QTY";
    cout.width(5);
    cout << "MRP";
    cout.width(16);
    cout << "Amount" << endl;
    float total = 0, s = 0;
    for (int i = 0; i < counter; i++) {
        cout.width(4);
        cout << i + 1;
        cout.width(20);
        cout << menu[order[i][0]];
        cout.width(10);
        cout << hsn[order[i][0]];
        cout.width(5);
        cout << order[i][1];
        cout.width(5);
        cout << price[order[i][0]];
        cout.width(16);
        s = price[order[i][0]] * order[i][1];
        cout << s << endl;
        total += s;
    }
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "Total: " ;
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout << total << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "In Words: " ;
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout << inwords(total) << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "Discount: ";
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout <<"5%" << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "SGST: ";
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout <<"9%" << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "CGST: ";
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout <<"9%" << endl;
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "Grand Total: " ;
    cout.width(30);
    cout.setf(ios::right, ios::adjustfield);
    cout << total + total * 0.18 - total * 0.05 << endl;
    cout.width(35);
    cout << "Happy Meals!\n";
    cout.width(60);
    cout.fill('*');
    cout << "" << endl;
}

int main() {
    get_rest_info();
    get_rcvr_info();
    dis_menu();
    get_menu();
    display();
    return 0;
}
