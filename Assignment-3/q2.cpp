//Given a string, reverse it using STACK. For example “DataStructure” should be output as “erutcurtSataD.”

#include <iostream>
using namespace std;

class Stack {
private:
    char arr[100]; 
    int top;

public:
    Stack() {
        top = -1; 
    }

    void push(char c) {
        top++;
        arr[top] = c;
    }

    char pop() {
        char c = arr[top];
        top--;
        return c;
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    string str = "DataStructure";
    Stack st;

    // har character ko stack me daalna
    for (int i = 0; i < str.length(); i++) {
        st.push(str[i]);
    }

    cout << "Original String : " << str << endl;

    string rev = "";
    // stack se pop karke reverse banana
    while (!st.isEmpty()) {
        rev += st.pop(); //ek character stack ke top se nikalta hai--> rev ke end me add ho jata hai
    }

    cout << "Reversed String : " << rev << endl;
    return 0;
}