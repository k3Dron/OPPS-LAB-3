#include <iostream>
##include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

bool startsWithS(const string& word) {
    return !word.empty() && tolower(word[0]) == 's';
}

int main() {
    ifstream file("expt11.txt");
    int sWordCount = 0;

    if (file) {
        string line, word;
        while (getline(file, line)) {
            stringstream ss(line);
            while (ss >> word) {
                if (startsWithS(word)) {
                    ++sWordCount;
                }
            }
        }
    }

    file.close();
    cout << "Number of words starting with 's': " << sWordCount << endl;
    return 0;
}
