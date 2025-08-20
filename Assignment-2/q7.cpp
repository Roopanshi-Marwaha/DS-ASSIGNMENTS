// 7) Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number of inversions in an array.

#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int n;
	cout<<"Enter the number of elements : ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of the array : ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int count=0;
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			if(arr[i]>arr[j]){
				count++;
			}
		}
	}
	cout<<"The number of inversions are "<<count<<endl;
	return 0;
}