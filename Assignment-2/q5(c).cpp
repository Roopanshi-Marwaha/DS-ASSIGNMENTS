//lower triangular elements

#include <iostream>
using namespace std;

int main() {
    int n; // square matrix
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int a[n][n];

    // Input only for lower triangular elements
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << "Enter element at (" << i << "," << j << "): ";
            cin >> a[i][j];
        }
        // Upper elements are zero
        for(int j = i+1; j < n; j++){
            a[i][j] = 0;
        }
    }

    // Display matrix
    cout << "\nLower Triangular Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}