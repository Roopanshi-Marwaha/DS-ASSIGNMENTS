#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void printList(Node* head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int main() {
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* newNode = new Node(x);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    // Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}