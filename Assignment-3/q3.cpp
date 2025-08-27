//Write a program that checks if an expression has balanced parentheses.

#include <bits/stdc++.h>
using namespace std;

bool isBalanced(const string &ex) {
    stack<char> st;
    for(char ch : ex) {
        if(ch=='(' || ch=='{' || ch=='[') {
            st.push(ch);
        } else if(ch==')' || ch=='}' || ch==']') {
            if(st.empty()) return false;
            char top = st.top();
            st.pop();
            if((ch==')' && top!='(') || 
               (ch=='}' && top!='{') || 
               (ch==']' && top!='['))
                return false;
        }
    }
    return st.empty();
}

int main() {
    string ex;
    cout << "Enter the expression: ";
    getline(cin, ex);

    if(isBalanced(ex))
        cout << "Balanced expression\n";
    else
        cout << "Not balanced\n";

    return 0;
}