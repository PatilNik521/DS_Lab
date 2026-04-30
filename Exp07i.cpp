// Code for Operations in Singly Linked List

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {}
    
    void InsertAtPos(int data, int pos) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }
            if (temp != nullptr) {
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                delete newNode; // Position is out of bounds
            }
        }
    }

    void DeleteAtPos(int pos) {
        if (head == nullptr) return;
        Node* temp = head;
        if (pos == 1) {
            head = temp->next;
            delete temp;
            return;
        }
        for (int i = 1; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) return;
        Node* next = temp->next->next;
        delete temp->next;
        temp->next = next;
    }

    void Display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList sll;
    int choice, data, pos;
    do {
        cout << "Menu:\n";
        cout << "1. Insert At Beginning\n";
        cout << "2. Insert At End\n";
        cout << "3. Delete At Beginning\n";
        cout << "4. Delete At End\n";
        cout << "5. Insert At Position\n";
        cout << "6. Delete At Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 5:
                cout << "Enter data and position: ";
                cin >> data >> pos;
                sll.InsertAtPos(data, pos);
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                sll.DeleteAtPos(pos);
                break;
            case 7:
                sll.Display();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 8);
    return 0;
}