#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularLinkedList{
public:
    Node* head;
    CircularLinkedList(){
        head = NULL;
    }

    void insert(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void display(){
        if(head == NULL) return;
        Node* temp = head;
        do{
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);
    }
};

int main(){
    CircularLinkedList cll;
    int n, val;
    cout<<"Enter no of nodes : ";
    cin >> n;
    cout<<"Enter values : ";
    for(int i=0; i<n; i++){
        cin >> val;
        cll.insert(val);
    }
    cll.display();
    return 0;
}
