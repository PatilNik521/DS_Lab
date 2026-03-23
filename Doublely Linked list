#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;
};

node* head = NULL;

// Insert at beginning
void insertBeg()
{
    int x;
    cout << "Enter data: ";
    cin >> x;
    
    node* n = new node;
    n->data = x;
    n->next = head;
    n->prev = NULL;
    
    if(head != NULL)
        head->prev = n;
    
    head = n;
    cout << "Inserted at beginning!\n";
}

// Insert at end
void insertEnd()
{
    int x;
    cout << "Enter data: ";
    cin >> x;
    
    node* n = new node;
    n->data = x;
    n->next = NULL;
    n->prev = NULL;
    
    if(head == NULL)
    {
        head = n;
    }
    else
    {
        node* t = head;
        while(t->next != NULL)
            t = t->next;
        
        t->next = n;
        n->prev = t;
    }
    cout << "Inserted at end!\n";
}

// Delete from beginning
void deleteBeg()
{
    if(head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }
    
    node* t = head;
    head = head->next;
    
    if(head != NULL)
        head->prev = NULL;
    
    delete t;
    cout << "Deleted from beginning!\n";
}

// Delete from end
void deleteEnd()
{
    if(head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }
    
    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        cout << "Deleted from end!\n";
        return;
    }
    
    node* t = head;
    while(t->next != NULL)
        t = t->next;
    
    t->prev->next = NULL;
    delete t;
    cout << "Deleted from end!\n";
}

// Display forward
void displayForward()
{
    if(head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }
    
    cout << "Forward: ";
    node* t = head;
    while(t != NULL)
    {
        cout << t->data << " <-> ";
        t = t->next;
    }
    cout << "NULL\n";
}

// Display backward
void displayBackward()
{
    if(head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }
    
    node* t = head;
    while(t->next != NULL)
        t = t->next;
    
    cout << "Backward: ";
    while(t != NULL)
    {
        cout << t->data << " <-> ";
        t = t->prev;
    }
    cout << "NULL\n";
}

int main()
{
    int ch;
    
    while(true)
    {
        cout << "\n===== DOUBLY LINKED LIST MENU =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display Forward\n";
        cout << "6. Display Backward\n";
        cout << "7. Exit\n";
        cout << "===================================\n";
        cout << "Enter your choice: ";
        cin >> ch;
        
        switch(ch)
        {
            case 1:
                insertBeg();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                deleteBeg();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                displayForward();
                break;
            case 6:
                displayBackward();
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    
    return 0;
}
