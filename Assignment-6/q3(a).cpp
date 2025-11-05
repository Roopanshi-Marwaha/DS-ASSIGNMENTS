
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        data = val;
        prev = next = NULL;
    }
};

void insert(Node* &head, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

int main(){
    Node* head = NULL;
    int n, val;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> val;
        insert(head, val);
    }

    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    cout << count;
    return 0;
}