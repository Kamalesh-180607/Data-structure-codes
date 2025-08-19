// STACK IMPLEMENTATION USING LINKED LIST
#include<iostream>
using namespace std;

// Node class for linked list
class Node
{
    public:
    int data;       // data part of node
    Node *next;     // pointer to next node

    // Constructor
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Global pointer to top of stack
Node *head = NULL;

// Push operation (Insert element at beginning)
void push(int val)
{
    Node *newnode = new Node(val);
    newnode->next = head;
    head = newnode;
    cout << "Inserted element: " << val << endl;
}

// Pop operation (Delete element from beginning)
void pop()
{
    if (!head)   // if stack is empty
    {
        cout << "Stack is empty can't pop" << endl;
        return;
    }
    cout << "Popped element: " << head->data << endl;
    Node *temp = head;
    head = head->next;
    delete temp;
}

// Display operation (Show elements from top to bottom)
void display()
{
    if (!head)
    {
        cout << "Stack is empty can't display" << endl;  // corrected msg: "can't delete" → "can't display"
        return;
    }
    cout << "Elements in stack: ";
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function with menu-driven program
int main()
{
    int data, c;
    do
    {
        cout << "\n1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose one option: ";
        cin >> c;

        switch (c)
        {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exit" << endl;
                break;

            default:
                cout << "Enter valid choice" << endl;
        }
    } while (c != 4);
}

