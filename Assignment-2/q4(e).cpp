//Write a program to convert a character from uppercase to lowercase.

#include<bits/stdc++.h>
using namespace std;
int main(){
    char ch;
    cout<<"Enter the character : ";
    cin>>ch;

    if(ch>='A' && ch<='Z'){
        ch = ch+32;
    }
    cout<<"Character in lowercase is : "<<ch<<endl;

    return 0;
}