// 8) Write a program to count the total number of distinct elements in an array of length n.

#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int n ;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int arr[n];

    cout<<"Enter the elements of array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int notsame = 0;
    for(int i=0;i<n;i++){
        bool flag = true;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                flag = false;
                break;
            }
        }
        if(flag == true){
            notsame++;
        }
    }

    cout<<"Total number of not same elements are "<<notsame<<endl;
    return 0;
}