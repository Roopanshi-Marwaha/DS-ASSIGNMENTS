//Develop a menu driven program demonstrating the following operations on a Stack using array:
// (i)push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().

#include<bits/stdc++.h>
using namespace std;

int main() {
    int stack[5], top = -1;
    int choice, x;

    while(true) {
        cout << "-----Stack Menu-----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter the choice : ";
        cin >> choice;

        switch(choice) {
            case 1: // Push
                if(top==4) {
                    cout << "Stack Overflow\n";
                } else {
                    cout << "Enter the element to push : ";
                    cin >> x;
                    stack[++top] = x;
                }
                break;

            case 2: // Pop
                if(top==-1) {
                    cout << "Stack Underflow\n";
                } else {
                    cout << "Popped element: " << stack[top--] << "\n";
                }
                break;

            case 3: // isEmpty
                if(top==-1)
                    cout << "Stack empty\n";
                else
                    cout << "Stack not empty\n";
                break;

            case 4: // isFull
                if(top==4)
                    cout << "Stack is full\n";
                else
                    cout << "Stack not full\n";
                break; // <-- Important!

            case 5: // Display
                if(top==-1) {
                    cout << "Stack is empty\n";
                } else {
                    cout << "Stack Elements: ";
                    for(int i=top; i>=0; i--) {
                        cout << stack[i] << " ";
                    }
                    cout << "\n";
                }
                break;

            case 6: // Peek
                if(top==-1) {
                    cout << "Stack empty\n";
                } else {
                    cout << "Top element is: " << stack[top] << "\n";
                }
                break;

            case 7: // Exit
                cout << "Exit program\n";
                return 0;

            default:
                cout << "Invalid\n";
        }
        cout << "---------------------\n";
    }
}