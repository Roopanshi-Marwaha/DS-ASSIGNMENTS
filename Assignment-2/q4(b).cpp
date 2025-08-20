//Write a program to reverse a string.

#include<bits/stdc++.h>
using namespace std;
int main(){
    char str[100];
    cout<<"Enter the string : ";
    cin>>str;
    int n = strlen(str);
    
    cout<<"Reversed string is : ";
    for(int i=n-1;i>=0;i--){
        cout<<str[i];
    }
    cout<<endl;
    return 0;
}