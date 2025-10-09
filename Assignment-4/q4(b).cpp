#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1;

public:
    // Push: O(n)
    void push(int x) {
        int size = q1.size();
        q1.push(x);

        // Move all previous elements behind the new one
        for (int i = 0; i < size; i++) {
            q1.push(q1.front());
            q1.pop();
        }
    }

    // Pop: O(1)
    void pop() {
        if (q1.empty()) {
            cout << "Stack empty\n";
            return;
        }
        q1.pop();
    }

    // Top: O(1)
    void top() {
        if (q1.empty()) {
            cout << "Stack empty\n";
            return;
        }
        cout << "Top element: " << q1.front() << endl;
    }

    bool isempty() {
        return q1.empty();
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack empty\n";
            return;
        }
        cout << "Stack Elements: ";
        queue<int> temp = q1;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice = -1, val; // ✅ initialized

    while (choice != 0) {
        cout << "\n===== Stack using Single Queue =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            s.push(val);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.top();
            break;
        case 4:
            s.display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}