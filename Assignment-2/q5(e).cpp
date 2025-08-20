// (e) Symmetric Matrix

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int a[n][n];

    // Input only upper triangle
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cout << "Enter element at (" << i << "," << j << "): ";
            cin >> a[i][j];
            a[j][i] = a[i][j]; // copy to lower triangle
        }
    }

    // Display symmetric matrix
    cout << "\nSymmetric Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}