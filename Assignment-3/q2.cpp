//Given a string, reverse it using STACK. For example “DataStructure” should be output as “erutcurtSataD.”

#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main() {
    string str = "DataStructure";
    stack<char> st;

    for(char ch : str) {
        st.push(ch);
    }

    cout << "Original String : " << str << endl;
    string rev;
    rev.reserve(str.size()); // optional optimization

    while(!st.empty()) {
        rev.push_back(st.top());
        st.pop();
    }

    cout << "Reversed String : " << rev << endl;
    return 0;
}
