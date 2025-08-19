// QUEUE IMPLEMENTATION USING LINKED LIST
#include<iostream>
using namespace std;

// Node class
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

// Global front and rear pointers
Node *front = NULL;
Node *rear = NULL;

// Enqueue (push) operation
void push(int val)
{
    Node *newnode = new Node(val);

    // If queue is empty
    if (!front)
    {
        front = rear = newnode;
        cout << "Inserted element: " << val << endl;
        return;
    }

    // Attach newnode at rear
    rear->next = newnode;
    rear = newnode;
    cout << "Inserted element: " << val << endl;
}

// Dequeue (pop) operation
void pop()
{
    if (!front)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *del = front;
    cout << "Popped element: " << front->data << endl;
    front = front->next;

    // If queue becomes empty
    if (!front)
        rear = NULL;

    delete del;
}

// Display queue elements
void display()
{
    if (!front)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *temp = front;
    cout << "Queue elements: ";
    while (temp)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

// Main menu-driven program
int main()
{
    int c, data;
    do
    {
        cout << "\n1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. Display()" << endl;
        cout << "4. Exit!!" << endl;
        cout << "Enter choice: ";
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
                cout << "Exited!!" << endl;
                break;

            default:
                cout << "Enter valid choice" << endl;
        }
    } while (c != 4);
}
