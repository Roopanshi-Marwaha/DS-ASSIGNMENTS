#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insert(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

bool isCircular(Node* head) {
    if (head == NULL) return true;
    Node* temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;
    return temp == head;
}

int main() {
    Node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    // head->next->next->next->next = head; //  circular

    if (isCircular(head))
        cout << "Circular Linked List";
    else
        cout << "Not Circular Linked List";

    return 0;
}
