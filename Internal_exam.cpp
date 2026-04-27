#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtPosition(int val, int pos)
{
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid Position\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int choice, val, pos;

    do
    {
        cout << "1.Insert at any position\n";
        cout << "2.Delete at beginning\n";
        cout << "3.Display linked list\n";
        cout << "4.Exit\n";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                insertAtPosition(val, pos);
                break;

            case 2:
                deleteBeginning();
                break;

            case 3:
                display();
                break;

            case 4:
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while (choice != 4);

    return 0;
}
