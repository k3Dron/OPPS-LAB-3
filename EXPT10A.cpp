#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void writeFile(const string& filename, int* data, int size) {
    ofstream outFile(filename);
    for (int i = 0; i < size; ++i) {
        outFile << data[i] << " ";
    }
    outFile.close();
}

void readFile(const string& filename, int* data, int& size) {
    ifstream inFile(filename);
    size = 0;
    while (inFile >> data[size]) {
        ++size;
    }
    inFile.close();
}

void displayFile(const string& filename) {
    ifstream inFile(filename);
    int num;
    while (inFile >> num) {
        cout << num << " ";
    }
    cout << endl;
    inFile.close();
}

int main() {
    int firstFileData[5] = {10, 5, 20, 15, 25};
    int secondFileData[3] = {30, 8, 2};
    int mergedData[8];
    int mergedSize = 0;

    writeFile("first.txt", firstFileData, 5);
    writeFile("second.txt", secondFileData, 3);

    readFile("first.txt", mergedData, mergedSize);
    int secondData[3];
    int secondSize = 0;
    readFile("second.txt", secondData, secondSize);
    displayFile("first.txt");
    displayFile("second.txt");
    for (int i = 0; i < secondSize; ++i) {
        mergedData[mergedSize++] = secondData[i];
    }

    sort(mergedData, mergedData + mergedSize);
    writeFile("third.txt", mergedData, mergedSize);

    cout << "Contents merged and written to third.txt in ascending order." << endl;
    cout << "Merged file content: ";
    displayFile("third.txt");

    return 0;
}
