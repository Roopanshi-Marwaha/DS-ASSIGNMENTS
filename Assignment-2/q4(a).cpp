//Write a program to concatenate one string to another string.

#include <iostream>
using namespace std;

int main() {
    char str1[100];
    char str2[100];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    int i = 0;
    while (str1[i] != '\0') i++;  

    int j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++; 
        j++;
    }
    str1[i] = '\0'; 

    cout << "Concatenated String: " << str1 << endl;
    return 0;
}
