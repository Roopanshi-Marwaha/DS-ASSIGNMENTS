#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {
        // Default initial values
        insertAtEnd(10);
        insertAtEnd(20);
        insertAtEnd(30);
    }

    // Insert at Beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << val << " inserted at the beginning.\n";
    }

    // Insert at End
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) { 
            head = newNode; 
            cout << val << " inserted at the end.\n";
            return; 
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        cout << val << " inserted at the end.\n";
    }

    // Insert After a Key
    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { 
            cout << "Key " << key << " not found!\n"; 
            return; 
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << val << " inserted after " << key << ".\n";
    }

    // Insert Before a Key
    void insertBefore(int key, int val) {
        if (!head) { 
            cout << "List empty!\n"; 
            return; 
        }
        if (head->data == key) { 
            insertAtBeginning(val); 
            return; 
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (!temp->next) { 
            cout << "Key " << key << " not found!\n"; 
            return; 
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << val << " inserted before " << key << ".\n";
    }

    // Delete from Beginning
    void deleteBeginning() {
        if (!head) { 
            cout << "List empty!\n"; 
            return; 
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from the beginning.\n";
        delete temp;
    }

    // Delete from End
    void deleteEnd() {
        if (!head) { 
            cout << "List empty!\n"; 
            return; 
        }
        if (!head->next) {
            cout << head->data << " deleted from the end.\n";
            delete head; 
            head = nullptr; 
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        cout << temp->next->data << " deleted from the end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete Specific Node
    void deleteNode(int key) {
        if (!head) { 
            cout << "List empty!\n"; 
            return; 
        }
        if (head->data == key) { 
            deleteBeginning(); 
            return; 
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (!temp->next) { 
            cout << "Key " << key << " not found!\n"; 
            return; 
        }
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        cout << delNode->data << " deleted from the list.\n";
        delete delNode;
    }

    // Search
    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) { 
                cout << key << " found at position " << pos << ".\n"; 
                return; 
            }
            temp = temp->next;
            pos++;
        }
        cout << key << " not found in the list.\n";
    }

    // Display
    void display() {
        if (!head) { 
            cout << "List empty!\n"; 
            return; 
        }
        Node* temp = head;
        cout << "List: ";
        while (temp) { 
            cout << temp->data << " "; 
            temp = temp->next; 
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, key;

    while (true) {
        cout << "\n===== Singly Linked List Menu =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before\n";
        cout << "4. Insert After\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search\n";
        cout << "9. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(cin.fail()){   // handle invalid input
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter key to insert before: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertBefore(key, val);
                break;
            case 4:
                cout << "Enter key to insert after: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertAfter(key, val);
                break;
            case 5:
                list.deleteBeginning();
                break;
            case 6:
                list.deleteEnd();
                break;
            case 7:
                cout << "Enter key to delete: ";
                cin >> key;
                list.deleteNode(key);
                break;
            case 8:
                cout << "Enter key to search: ";
                cin >> key;
                list.search(key);
                break;
            case 9:
                list.display();
                break;
            case 0:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}