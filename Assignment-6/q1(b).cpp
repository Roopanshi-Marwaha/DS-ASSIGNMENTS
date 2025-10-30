#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList{
    Node* head;
public:
    DoublyLinkedList(){
        head=NULL;
    }

    void display() {
        if(head==NULL){
            cout<<"List is empty.\n";
            return;
        }
        Node* temp=head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }

    void insertAtBeginning(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head = newNode;
            return;
        }
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }

    void insertAtEnd(int val){
        Node* newNode=new Node(val);
        if(head == NULL){
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next= newNode;
        newNode->prev= temp;
    }

    void insertAfter(int key, int val) {
        Node* temp=head;
        while(temp!= NULL && temp->data != key)
            temp = temp->next;
        if(temp==NULL) {
            cout<<key<<" not found.\n";
            return;
        }
        Node* newNode=new Node(val);
        newNode->next= temp->next;
        newNode->prev= temp;
        if (temp->next!= NULL)
            temp->next->prev = newNode;
        temp->next=newNode;
    }

    void insertBefore(int key, int val) {
        Node* temp = head;
        while(temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout<<key<<" not found.\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != NULL)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        if (temp == head)
            head = head->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        delete temp;
        cout << "Node " << key << " deleted.\n";
    }

    void searchNode(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if(temp->data == key) {
                cout<<"Node "<<key<<" found at position " << pos << ".\n";
                return;
            }
            temp=temp->next;
            pos++;
        }
        cout<<"Node "<<key<<" not found.\n";
    }
};

int main(){
    DoublyLinkedList list;
    int choice, val, key;

    do{
        cout<< "\n1. Insert at Beginning";
        cout<< "\n2. Insert at End";
        cout<< "\n3. Insert After a Node";
        cout<< "\n4. Insert Before a Node";
        cout<< "\n5. Delete a Node";
        cout<< "\n6. Search a Node";
        cout<< "\n7. Display List";
        cout<< "\n8. Exit";
        cout<< "\nEnter your choice: ";
        cin>> choice;

        switch(choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter key (after which to insert): ";
            cin >> key;
            cout << "Enter value: ";
            cin >> val;
            list.insertAfter(key, val);
            break;
        case 4:
            cout << "Enter key (before which to insert): ";
            cin >> key;
            cout << "Enter value: ";
            cin >> val;
            list.insertBefore(key, val);
            break;
        case 5:
            cout << "Enter value to delete: ";
            cin >> val;
            list.deleteNode(val);
            break;
        case 6:
            cout << "Enter value to search: ";
            cin >> val;
            list.searchNode(val);
            break;
        case 7:
            list.display();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 8);

    return 0;
}