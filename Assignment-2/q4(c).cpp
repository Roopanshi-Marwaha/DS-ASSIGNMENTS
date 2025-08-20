//Write a program to delete all the vowels from the string.

#include <bits/stdc++.h>
using namespace std;

int main() {
    char str[100];
    cout << "Enter the string: ";
    cin >> str;

    char result[100];
    int x = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        // Convert uppercase to lowercase for checking vowels
        char lower = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;

        if(lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
            result[x] = str[i]; 
            x++;
        }
    }

    result[x] = '\0'; // important

    cout << "String without vowels: " << result << endl;
    return 0;
}
