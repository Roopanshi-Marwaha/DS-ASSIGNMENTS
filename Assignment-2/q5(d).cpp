// (d) Upper triangular Matrix.

#include <iostream>
using namespace std;

int main() {
    int n; // square matrix
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int a[n][n];

    // Input only for upper triangular elements
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cout << "Enter element at (" << i << "," << j << "): ";
            cin >> a[i][j];
        }
        // Lower elements are zero
        for(int j = 0; j < i; j++){
            a[i][j] = 0;
        }
    }

    // Display matrix
    cout << "\nUpper Triangular Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}