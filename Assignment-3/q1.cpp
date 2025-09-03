#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    int arr[5];   // fixed size stack
    int top;
    int size;

public:
    // constructor
    Stack() {
        top = -1;
        size = 5;
    }

    // push operation
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
        } else {
            arr[++top] = x;
            cout << x << " pushed into stack" << endl;
        }
    }

    // pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop" << endl;
        } else {
            cout << arr[top--] << " popped from stack" << endl;
        }
    }

    // check empty
    bool isEmpty() {
        return top == -1;
    }

    // check full
    bool isFull() {
        return top == size - 1;
    }

    // peek (top element)
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    // display all elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

// main function
int main() {
    Stack st;
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                st.push(value);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                if (st.isEmpty())
                    cout << "Stack is Empty\n";
                else
                    cout << "Stack is NOT Empty\n";
                break;
            case 4:
                if (st.isFull())
                    cout << "Stack is Full\n";
                else
                    cout << "Stack is NOT Full\n";
                break;
            case 5:
                st.display();
                break;
            case 6:
                st.peek();
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}