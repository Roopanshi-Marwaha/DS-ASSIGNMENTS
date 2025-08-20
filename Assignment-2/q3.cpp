//Design the Logic to Find a Missing Number in a Sorted Array.

#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of Array : ";
    cin>>n;
    int arr[n];

    cout<<"Enter the elements of array : ";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    bool found = false;
    for(int i=0;i<n-1;i++){
        if(arr[i+1]-arr[i] != 1){
             cout<<"Missing element is " <<arr[i]+1<< " found at index : "<<i+1<<endl;
             found = true;
             break;
        }
    }
       
    if(!found){
        cout<<"Element not found."<<endl;
    }
    return 0;
}