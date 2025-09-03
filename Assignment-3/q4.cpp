#include<bits/stdc++.h>
using namespace std;

int priority(char c){
    if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

string inftopostfix(string exp){
    stack<char> st;
    string ans;

    for(int i=0;i<exp.length();i++){
        char c = exp[i];

        if((c>='a' && c<='z') || (c>='A' && c<='B') || (c>='0' && c<='9')){
            ans += c;
        }

        else if(c=='('){
            st.push(c);
        }

        else if(c==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }

        else{
            while(!st.empty() && priority(st.top()) > priority(c)){
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }

    }
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main(){
    string expression;
    cout<<"Enter the Infix Expression : ";
    cin>>expression;

    cout<<"Postfix Expression : "<<inftopostfix(expression)<<endl;
    return 0;
}