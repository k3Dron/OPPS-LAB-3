#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
    string content;
    cout << "Enter the content (end with a single line 'END'): " << endl;
    string line;
    while (getline(cin, line) && line != "END") {
        content += line + '\n';
    }

    istringstream file(content);
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

    cout << "Number of characters: " << numChars << endl;
    cout << "Number of words: " << numWords << endl;
    cout << "Number of lines: " << numLines << endl;
    cout << "Number of tabs: " << numTabs << endl;
    cout << "Number of new line characters: " << numNewLines << endl;

    return 0;
}
