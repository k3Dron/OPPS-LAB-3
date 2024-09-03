#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void multiplyByScalar(vector<int>& vec, int scalar) {
    for (auto& elem : vec) {
        elem *= scalar;
    }
}

vector<int> addVectors(const vector<int>& vec1, const vector<int>& vec2) {
    vector<int> result(vec1.size());
    transform(vec1.begin(), vec1.end(), vec2.begin(), result.begin(), plus<int>());
    return result;
}

int main() {
    int n, scalar;
    cout << "Enter the number of elements in the vector: ";
    cin >> n;

    vector<int> vec(n);
    cout << "Enter the elements of the vector:\n";
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    cout << "Enter the scalar value to multiply with each element: ";
    cin >> scalar;

    multiplyByScalar(vec, scalar);

    cout << "Vector after multiplication by scalar:\n";
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;

    vector<int> vec2(n);
    cout << "Enter the elements of the second vector for addition:\n";
    for (int i = 0; i < n; ++i) {
        cin >> vec2[i];
    }

    vector<int> result = addVectors(vec, vec2);

    cout << "Resultant vector after addition:\n";
    for (const auto& elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
