#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    ifstream file("example.txt");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    char ch;
    int numChars = 0, numWords = 0, numLines = 0, numTabs = 0, numNewLines = 0;
    bool inWord = false;

    while (file.get(ch)) {
        numChars++;
        
        if (isspace(ch)) {
            if (inWord) {
                numWords++;
                inWord = false;
            }
            if (ch == '\n') numNewLines++;
            if (ch == '\t') numTabs++;
        } else {
            inWord = true;
        }

        if (ch == '\n') numLines++;
    }

    if (inWord) numWords++;

    file.close();

    cout << "Number of characters: " << numChars << endl;
    cout << "Number of words: " << numWords << endl;
    cout << "Number of lines: " << numLines << endl;
    cout << "Number of tabs: " << numTabs << endl;
    cout << "Number of new line characters: " << numNewLines << endl;

    return 0;
}

