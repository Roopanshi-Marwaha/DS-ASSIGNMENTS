//Tri-diagonal Matrix
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    int mainDiag[n];       // Main diagonal
    int upper[n-1];        // Upper diagonal
    int lower[n-1];        // Lower diagonal

    cout << "Enter elements of the main diagonal (" << n << " elements): ";
    for(int i = 0; i < n; i++) {
        cin >> mainDiag[i];
    }

    cout << "Enter elements of the upper diagonal (" << n-1 << " elements): ";
    for(int i = 0; i < n-1; i++) {
        cin >> upper[i];
    }

    cout << "Enter elements of the lower diagonal (" << n-1 << " elements): ";
    for(int i = 0; i < n-1; i++) {
        cin >> lower[i];
    }

    cout << "\nThe Tridiagonal Matrix is:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j)
                cout << mainDiag[i] << " ";
            else if(i-j == 1)
                cout << lower[i-1] << " ";
            else if(j-i == 1)
                cout << upper[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}
