// DOUBLY LINKEDLIST IMPLEMENTATION
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

Node *head = NULL;
Node *tail = NULL;

void insertbeg(int val) {
    Node *newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        newnode->next = NULL;
        newnode->prev = NULL;
    } else {
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        head = newnode;
    }
}

void insertend(int val) {
    Node *newnode = new Node(val);
    if (head == NULL) {
        insertbeg(val);
        return;
    } else {
        newnode->prev = tail;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }
}

void insertpos(int val, int pos) {
    if (pos == 1) {
        insertbeg(val);
        return;
    }
    int i = 1;
    Node *temp = head;
    while (temp && i < pos - 1) {
        temp = temp->next;
        i++;
    }
    if (!temp) {
        cout << "\nPosition out of range";
        return;
    }
    if (temp == tail) {
        insertend(val);
        return;
    }
    Node *newnode = new Node(val);
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

void deleteend() {
    if (head == NULL) {
        cout << "\nList is empty can't delete";
        return;
    }
    Node *temp = tail;
    tail = temp->prev;
    if (tail) tail->next = NULL;
    else head = NULL;
    delete temp;
}

void deletebeg() {
    if (head == NULL) {
        cout << "\nList is empty can't delete";
        return;
    }
    if (head->next == NULL) {
        deleteend();
        return;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void deletepos(int pos) {
    if (head == NULL) {
        cout << "\nList is empty can't delete";
        return;
    }
    int count = 1;
    Node *temp = head;
    while (temp && pos > count) {
        temp = temp->next;
        count++;
    }
    if (!temp) {
        cout << "\nInvalid position";
        return;
    }
    if (temp == head) {
        deletebeg();
        return;
    } else if (temp == tail) {
        deleteend();
        return;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void deleteel(int val) {
    if (head == NULL) {
        cout << "\nList is empty can't delete";
        return;
    }
    Node *temp = head;
    while (temp && temp->data != val) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "\nElement not found";
        return;
    }
    if (head == temp) {
        deletebeg();
        return;
    }
    if (tail == temp) {
        deleteend();
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void display() {
    if (head == NULL) {
        cout << "\nList is empty can't display";
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << "--->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int c;
    do {
        cout << "\n1. Insert at first\n2. Insert at end\n3. Insert at desired position"
             << "\n4. Delete at first\n5. Delete at end\n6. Delete at desired position"
             << "\n7. Delete element\n8. Display\n9. Exit!!\n";
        cin >> c;
        switch (c) {
            case 1: {
                int x1;
                cout << "\nEnter element to insert: ";
                cin >> x1;
                insertbeg(x1);
                break;
            }
            case 2: {
                int x2;
                cout << "Enter element to insert: ";
                cin >> x2;
                insertend(x2);
                break;
            }
            case 3: {
                int x3;
                cout << "Enter element to insert: ";
                cin >> x3;
                int p;
                cout << "Enter position to insert: ";
                cin >> p;
                insertpos(x3, p);
                break;
            }
            case 4:
                deletebeg();
                break;
            case 5:
                deleteend();
                break;
            case 6: {
                int pos;
                cout << "Enter position to delete: ";
                cin >> pos;
                deletepos(pos);
                break;
            }
            case 7: {
                int el;
                cout << "Enter element to delete: ";
                cin >> el;
                deleteel(el);
                break;
            }
            case 8:
                display();
                break;
            case 9:
                cout << "\nExited!!";
                break;
            default:
                cout << "\nChoose valid option";
        }
    } while (c != 9);
}
