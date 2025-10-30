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

void insert(Node* &head, int val){
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

int main(){
    Node* head = NULL;
    int n, val;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> val;
        insert(head, val);
    }

    if(head == NULL){
        cout << 0;
        return 0;
    }

    int count = 0;
    Node* temp = head;
    do{
        count++;
        temp = temp->next;
    } while(temp != head);

    cout << count;
    return 0;
}