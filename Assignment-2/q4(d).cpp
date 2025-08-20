//Write a program to sort the strings in alphabetical order.

#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    char arr[n][100];  

    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(strcmp(arr[j],arr[j+1])>0){
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }

    cout<<"The alphabetical order is: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}