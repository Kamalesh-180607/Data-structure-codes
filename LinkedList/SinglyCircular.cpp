#include<iostream>
using namespace std;

// Node class for Circular Singly Linked List
class Node
{
    public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *head = NULL;

// Insert at end of circular linked list
void insertend(int val)
{
    Node *newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }
    Node *temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

// Insert at beginning
void insertbeg(int val)
{
    if(head == NULL)
    {
        insertend(val);
        return;
    }
    Node *newnode = new Node(val);
    Node *temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
}

// Insert at desired position
void insertpos(int val, int pos)
{
    if(pos <= 0)
    {
        cout << "\nInvalid position";
        return;
    }
    if(pos == 1)
    {
        insertbeg(val);
        return;
    }
    int count = 1;
    Node *temp = head;
    while(count < pos-1 && temp->next != head)
    {
        temp = temp->next;
        count++;
    }
    if(count != pos-1)
    {
        cout << "\nInvalid position";
        return;
    }
    Node *newnode = new Node(val);
    newnode->next = temp->next;
    temp->next = newnode;
}

// Delete from beginning
void deletebeg()
{
    if(head == NULL)
    {
        cout << "\nList is empty can't delete";
        return;
    }
    if(head->next == head) // only one node
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    Node *del = head;
    while(temp->next != head)
        temp = temp->next;
    temp->next = head->next;
    head = head->next;
    delete del;
}

// Delete from end
void deleteend()
{
    if(head == NULL)
    {
        cout << "\nList is empty can't delete";
        return;
    }
    if(head->next == head) // only one node
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    Node *prev = NULL;
    while(temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    delete temp;
}

// Delete from given position
void deletepos(int pos)
{
    if(head == NULL)
    {
        cout << "\nList is empty can't delete ";
        return;
    }
    if(pos <= 0)
    {
        cout << "\nInvalid position";
        return;
    }
    if(pos == 1) // deleting head
    {
        deletebeg();
        return;
    }
    Node *temp = head;
    Node *prev = NULL;
    int count = 1;
    while(count < pos && temp->next != head)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if(count != pos)
    {
        cout << "\nInvalid position";
        return;
    }
    prev->next = temp->next;
    delete temp;
}

// Delete given element
void deleteel(int val)
{
    if(head == NULL)
    {
        cout << "\nList is empty can't delete";
        return;
    }
    if(head->data == val)
    {
        deletebeg();
        return;
    }
    bool check = false;
    Node *prev = NULL;
    Node *temp = head;
    do
    {
        prev = temp;
        temp = temp->next;
        if(temp->data == val)
        {
            check = true;
            break;
        }
    } while(temp != head);

    if(!check)
    {
        cout << "\nElement not found";
        return;
    }
    prev->next = temp->next;
    delete temp;
}

// Display the circular linked list
void display()
{
    if(head == NULL)
    {
        cout << "\nList is empty can't display";
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << "-->";
        temp = temp->next;
    } while(temp != head);
    cout << "(head)" << endl;
}

int main()
{
    int c;
    do
    {
        cout << "\n1. Insert at first\n2. Insert at end\n3. Insert at desired position\n4. Delete at first\n5. Delete at end\n6. Delete at desired position\n7. Delete element\n8. Display\n9. Exit!!\n";
        cin >> c;
        switch(c)
        {
            case 1:
                int x1;
                cout << "\nEnter element to insert: ";
                cin >> x1;
                insertbeg(x1);
                break;

            case 2:
                int x2;
                cout << "Enter element to insert: ";
                cin >> x2;
                insertend(x2);
                break;

            case 3:
                int x3, p1;
                cout << "Enter element to insert: ";
                cin >> x3;
                cout << "Enter position to insert: ";
                cin >> p1;
                insertpos(x3, p1);
                break;

            case 4:
                deletebeg();
                break;

            case 5:
                deleteend();
                break;

            case 6:
                int p2;
                cout << "Enter position to delete: ";
                cin >> p2;
                deletepos(p2);
                break;

            case 7:
                int el;
                cout << "Enter element to delete: ";
                cin >> el;
                deleteel(el);
                break;

            case 8:
                display();
                break;

            case 9:
                cout << "\nExited";
                break;

            default:
                cout << "\nEnter valid choice";
        }
    } while(c != 9);
}
