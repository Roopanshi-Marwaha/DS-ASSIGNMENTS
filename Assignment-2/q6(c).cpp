// (c) Multiplication of two matrices.

#include <iostream>
using namespace std;

int main() {
    int r1, c1, t1, r2, c2, t2;

    // Input first sparse matrix
    cout << "Enter rows, columns, and non-zero elements of first matrix: ";
    cin >> r1 >> c1 >> t1;
    int mat1[t1][3];
    cout << "Enter row, column, value for each non-zero element:\n";
    for (int i = 0; i < t1; i++) {
        cin >> mat1[i][0] >> mat1[i][1] >> mat1[i][2];
    }

    // Input second sparse matrix
    cout << "Enter rows, columns, and non-zero elements of second matrix: ";
    cin >> r2 >> c2 >> t2;
    int mat2[t2][3];
    cout << "Enter row, column, value for each non-zero element:\n";
    for (int i = 0; i < t2; i++) {
        cin >> mat2[i][0] >> mat2[i][1] >> mat2[i][2];
    }

    // Check if multiplication is possible
    if (c1 != r2) {
        cout << "Matrix multiplication not possible (columns of first != rows of second)!\n";
        return 0;
    }

    int result[t1 * t2][3]; // Maximum possible non-zero elements
    int k = 0; // Result counter

    // Multiply matrices
    for (int i = 0; i < t1; i++) {
        for (int j = 0; j < t2; j++) {
            if (mat1[i][1] == mat2[j][0]) { // Column of first == row of second
                int r = mat1[i][0];
                int c = mat2[j][1];
                int val = mat1[i][2] * mat2[j][2];

                // Check if this position already exists in result
                bool found = false;
                for (int p = 0; p < k; p++) {
                    if (result[p][0] == r && result[p][1] == c) {
                        result[p][2] += val; // Add to existing value
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result[k][0] = r;
                    result[k][1] = c;
                    result[k][2] = val;
                    k++;
                }
            }
        }
    }

    // Display result
    cout << "\nResultant Sparse Matrix (Triplet form):\n";
    cout << "Row  Col  Value\n";
    for (int i = 0; i < k; i++) {
        cout << result[i][0] << "    " << result[i][1] << "    " << result[i][2] << endl;
    }

    return 0;
}