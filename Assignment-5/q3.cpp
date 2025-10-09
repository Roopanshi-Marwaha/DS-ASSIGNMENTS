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

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
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
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Linked List: ";
    printList(head);

    Node* mid = findMiddle(head);
    if (mid)
        cout << "Middle element: " << mid->data << endl;
    else
        cout << "List is empty!\n";

    return 0;
}
