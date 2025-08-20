// 6) Write a program to implement the following operations on a Sparse Matrix, assuming the matrix is represented using a triplet.
// (a) Transpose of a matrix.

#include <iostream>
using namespace std;

int main() {
    int rows, cols, terms;

    cout << "Enter number of rows, columns, and non-zero elements: ";
    cin >> rows >> cols >> terms;

    int sparse[terms][3];

    cout << "Enter the row, column, and value for each non-zero element:\n";
    for (int i = 0; i < terms; i++) {
        cin >> sparse[i][0] >> sparse[i][1] >> sparse[i][2];
    }

    // Display original sparse matrix
    cout << "\nOriginal Sparse Matrix (Triplet form):\n";
    cout << "Row  Col  Value\n";
    for (int i = 0; i < terms; i++) {
        cout << sparse[i][0] << "    " << sparse[i][1] << "    " << sparse[i][2] << endl;
    }

    // Transpose
    int transpose[terms][3];
    for (int i = 0; i < terms; i++) {
        transpose[i][0] = sparse[i][1];  // swap row and column
        transpose[i][1] = sparse[i][0];
        transpose[i][2] = sparse[i][2];  // value remains same
    }

    // Display transposed matrix
    cout << "\nTransposed Sparse Matrix (Triplet form):\n";
    cout << "Row  Col  Value\n";
    for (int i = 0; i < terms; i++) {
        cout << transpose[i][0] << "    " << transpose[i][1] << "    " << transpose[i][2] << endl;
    }

    return 0;
}
