#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedList {
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at Beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node{val, nullptr, head};
        if (head) head->prev = newNode;
        head = newNode;
    }

    // Insert at End
    void insertAtEnd(int val) {
        Node* newNode = new Node{val, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert Before a Given Key
    void insertBefore(int key, int val) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Key not found!\n";
            return;
        }
        Node* newNode = new Node{val, temp->prev, temp};
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    // Insert After a Given Key
    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Key not found!\n";
            return;
        }
        Node* newNode = new Node{val, temp, temp->next};
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Delete from Beginning
    void deleteBeginning() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    // Delete from End
    void deleteEnd() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }

    // Delete a Specific Node by Key
    void deleteNode(int key) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        if (head->data == key) {
            deleteBeginning();
            return;
        }
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Key not found!\n";
            return;
        }
        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        delete temp;
    }

    // Search for a Node
    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Not found\n";
    }

    // Display the List
    void display() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "List (Forward): ";
        while (temp) {
            cout << temp->data << " ";
            if (!temp->next) break;
            temp = temp->next;
        }
        cout << "\nList (Reverse): ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    DoublyLinkedList list;
    int choice, val, key;

    while (true) {
        cout << "\n===== Doubly Linked List Menu =====\n";
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

        switch (choice) {
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
                list.insertBefore(key, val);
                break;
            case 4:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
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
                cout << "Enter key: ";
                cin >> key;
                list.deleteNode(key);
                break;
            case 8:
                cout << "Enter key: ";
                cin >> key;
                list.search(key);
                break;
            case 9:
                list.display();
                break;
            case 0:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}