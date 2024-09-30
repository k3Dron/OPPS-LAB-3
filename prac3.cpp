//crete a class MAT of size m x n. Define all possible matrix for MAX type objects.
#include <iostream>
#include <vector>
using namespace std;

class MAT {
    int rows, cols;
    vector<vector<int>> mat;

public:
    MAT(int m, int n, int defaultValue = 0) : rows(m), cols(n), mat(m, vector<int>(n, defaultValue)) {}

    void setValue(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            mat[i][j] = value;
        }
    }

    int getValue(int i, int j) const {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            return mat[i][j];
        }
        return -1; 
    }

    MAT operator+(const MAT& other) const {
        MAT result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    MAT operator-(const MAT& other) const {
        MAT result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }

    MAT operator*(const MAT& other) const {
        MAT result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    void display() const {
        for (const auto& row : mat) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    MAT mat1(2, 2);
    MAT mat2(2, 2);
    mat1.setValue(0, 0, 1);
    mat1.setValue(0, 1, 2);
    mat1.setValue(1, 0, 3);
    mat1.setValue(1, 1, 4);
    mat2.setValue(0, 0, 5);
    mat2.setValue(0, 1, 6);
    mat2.setValue(1, 0, 7);
    mat2.setValue(1, 1, 8);
    MAT mat3 = mat1 + mat2;
    MAT mat4 = mat1 - mat2;
    MAT mat5 = mat1 * mat2;
    cout << "Matrix 1:" << endl;
    mat1.display();
    cout << "Matrix 2:" << endl;
    mat2.display();
    cout << "Matrix 1 + Matrix 2:" << endl;
    mat3.display();
    cout << "Matrix 1 - Matrix 2:" << endl;
    mat4.display();
    cout << "Matrix 1 * Matrix 2:" << endl;
    mat5.display();
    return 0;
}


