// (b) Addition of two matrices.

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

    // Check if addition is possible
    if (r1 != r2 || c1 != c2) {
        cout << "Matrix addition not possible (different dimensions)!\n";
        return 0;
    }

    int result[t1 + t2][3]; // Maximum possible non-zero elements
    int i = 0, j = 0, k = 0;

    // Add matrices
    while (i < t1 && j < t2) {
        // Compare positions
        if (mat1[i][0] < mat2[j][0] || (mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1])) {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2];
            i++; k++;
        } else if (mat1[i][0] > mat2[j][0] || (mat1[i][0] == mat2[j][0] && mat1[i][1] > mat2[j][1])) {
            result[k][0] = mat2[j][0];
            result[k][1] = mat2[j][1];
            result[k][2] = mat2[j][2];
            j++; k++;
        } else {
            // Same position, add values
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2] + mat2[j][2];
            i++; j++; k++;
        }
    }

    // Copy remaining elements
    while (i < t1) {
        result[k][0] = mat1[i][0];
        result[k][1] = mat1[i][1];
        result[k][2] = mat1[i][2];
        i++; k++;
    }
    while (j < t2) {
        result[k][0] = mat2[j][0];
        result[k][1] = mat2[j][1];
        result[k][2] = mat2[j][2];
        j++; k++;
    }

    // Display result
    cout << "\nResultant Sparse Matrix (Triplet form):\n";
    cout << "Row  Col  Value\n";
    for (int x = 0; x < k; x++) {
        cout << result[x][0] << "    " << result[x][1] << "    " << result[x][2] << endl;
    }

    return 0;
}
