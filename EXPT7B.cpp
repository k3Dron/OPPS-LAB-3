#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string text, line;
    int numLines = 0, numWords = 0, numChars = 0;

    cout << "Enter text (end input with an empty line):" << endl;
    while (getline(cin, line) && !line.empty()) {
        text += line + '\n';
        numLines++;
        numChars += line.length() + 1; 

        istringstream iss(line);
        string word;
        while (iss >> word) {
            numWords++;
        }
    }

    cout << left << setw(20) << "Number of lines" << right << setw(10) << numLines << endl;
    cout << left << setw(20) << "Number of words" << right << setw(10) << numWords << endl;
    cout << left << setw(20) << "Number of characters" << right << setw(10) << numChars << endl;

    return 0;
}
