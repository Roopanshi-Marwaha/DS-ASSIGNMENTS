//Write a program that checks if an expression has balanced parentheses.

#include <bits/stdc++.h>
using namespace std;

class Stack {
    char arr[100];   // maximum 100 characters
    int top;

public:
    Stack() { 
        top = -1; 
    }

    void push(char x) {
        arr[++top] = x;   
    }

    char pop() {
        return arr[top--]; 
    }

    char peek() {
        return arr[top]; 
    }

    bool isEmpty() {
        return (top == -1);
    }
};

bool isBalanced(string ex) {
    Stack st;
    for (int i = 0; i < ex.length(); i++) {
        char ch = ex[i];

        // opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.isEmpty()) return false;  // kuch open hi nahi tha

            char top = st.pop();  // last opening bracket nikala

            // matching check
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;  // galat pair
            }
        }
    }
    return st.isEmpty();  // sab pair match hue to empty hoga
}

int main() {
    string ex;
    cout << "Enter the expression: ";
    getline(cin, ex); //user se puri line ka input lena (spaces ke sath)

    if (isBalanced(ex))
        cout << "Balanced expression\n";
    else
        cout << "Not balanced\n";

    return 0;
}