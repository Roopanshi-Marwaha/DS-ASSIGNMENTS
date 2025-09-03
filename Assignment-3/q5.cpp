#include<bits/stdc++.h>
using namespace std;

int evalpostfix(string exp){
    stack<char> st;
    int ans;

    for(int i=0;i<exp.size();i++){
        char c = exp[i];

        if(isdigit(c)){
            st.push(c-'0');
        }
        else{
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            if(c=='+'){
                st.push(val2+val1);
            }
            else if(c=='-'){
                st.push(val2-val1);
            }
            else if(c=='*'){
                st.push(val2*val1);
            }
            else if(c=='/'){
                st.push(val2/val1);
            }

        }
    }
    ans = st.top();
    return ans;

}

int main(){
    string expression;
    cout<<"Enter Postfix : ";
    cin>>expression;

    cout<<"Evaluated answer : "<<evalpostfix(expression)<<endl;

    return 0;
}