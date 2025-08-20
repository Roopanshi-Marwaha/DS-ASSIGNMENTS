// Implement the Binary search algorithm regarded as a fast search algorithm with run-time complexity of Ο(log n) in comparison to the Linear Search.

#include <iostream>
using namespace std;

void BinarySearch(int arr[], int m, int s, int e) {
    bool found = false;
    while(s <= e) {
        int mid = s + (e - s) / 2;
        if(arr[mid] == m) {
            cout << "The required number is at position " << mid + 1 << endl;
            found = true;
            break;
        }
        else if(arr[mid] > m) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    if(!found) {
        cout << "Number not found in the array." << endl;
    }
}

int main() {
    int arr[50];
    int m, s = 0, e, n;
    char choice;

    cout << "Enter number of elements: ";
    cin >> n;

    e = n - 1;  // Last index

    cout << "Enter " << n << " elements in sorted order:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Do you wish to perform binary search? (y/n): ";
    cin >> choice;

    if(choice == 'y') {
        cout << "What number do you wish to find? ";
        cin >> m;
        BinarySearch(arr, m, s, e);
    } else {
        cout << "Program ended.\n";
    }

    return 0;
}
