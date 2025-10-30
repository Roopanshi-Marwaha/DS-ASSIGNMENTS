
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    Node* prev;
    Node* next;
    Node(char val){
        data = val;
        prev = next = NULL;
    }
};

void insert(Node* &head, char val){
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

bool isPalindrome(Node* head){
    if(head == NULL) return true;
    Node* left = head;
    Node* right = head;
    while(right->next != NULL)
        right = right->next;
    while(left != right && right->next != left){
        if(left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main(){
    Node* head = NULL;
    string s;
    cin >> s;
    for(char ch : s)
        insert(head, ch);

    if(isPalindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
    return 0;
}
