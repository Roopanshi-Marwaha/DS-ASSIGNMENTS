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
    Node* head;
    Node* last;
public:
    CircularLinkedList(){
        head = NULL;
        last = NULL;
    }

    void display(){
        if(head==NULL){
            cout<<"List empty\n";
            return;
        }
        Node* temp = head;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        } while(temp != head);
        cout<<endl;
    }

    void insertAtBeginning(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = last = newNode;
            newNode->next = head;
        }
        else{
            newNode->next = head;
            head = newNode;
            last->next = head;
        }
    }

    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = last = newNode;
            newNode->next = head;
        }
        else{
            last->next = newNode;
            last = newNode;
            last->next = head;
        }
    }

    void insertAfter(int key,int val){
        if(head==NULL){
            cout<<"List empty\n";
            return;
        }
        Node* temp = head;
        do {
            if(temp->data==key){
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                if(temp == last)
                    last = newNode;
                return;
            }
            temp = temp->next;
        } while(temp != head);
        cout << "Node " << key << " not found.\n";
    }

    void insertBefore(int key,int val){
        if(head==NULL){
            cout<<"List empty\n";
            return;
        }
        Node* temp = head;
        Node* prev = last;
        do {
            if(temp->data == key){
                Node* newNode = new Node(val);
                newNode->next = temp;
                prev->next = newNode;
                if(temp == head)
                    head = newNode;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while(temp != head);
        cout << "Node " << key << " not found.\n";
    }

    void deleteNode(int key){
        if(head == NULL){
            cout<<"List is empty.\n";
            return;
        }
        Node* temp = head;
        Node* prev = last;
        do {
            if(temp->data == key){
                if (temp == head && temp == last) {
                    head = last = NULL;
                }
                else if (temp == head) {
                    head = head->next;
                    last->next = head;
                }
                else if (temp == last) {
                    prev->next = head;
                    last = prev;
                }
                else {
                    prev->next = temp->next;
                }
                delete temp;
                cout<<"Node "<<key<<" deleted.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    void searchNode(int key){
        if(head==NULL){
            cout<<"List empty\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do{
            if(temp->data == key){
                cout<<"Node "<<key<<" found at position " << pos << ".\n";
                return;
            }
            temp=temp->next;
            pos++;
        }while(temp != head);
        cout << "Node " << key << " not found.\n";
    }
};

int main(){
    CircularLinkedList list;
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
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> val;
            list.insertAfter(key, val);
            break;
        case 4:
            cout << "Enter key: ";
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