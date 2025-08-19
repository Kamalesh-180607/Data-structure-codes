// CIRCULAR DOUBLY LINKED LIST
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

Node *head = NULL;
Node *tail = NULL;

void insertbeg(int val) {
    Node *newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        newnode->prev = head;
        newnode->next = head;
        return;
    }
    newnode->next = head;
    newnode->prev = tail;
    head->prev = newnode;
    head = newnode;
    tail->next = head;
}

void insertend(int val) {
    Node *newnode = new Node(val);
    if (head == NULL) {
        insertbeg(val);
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = head;
    tail = newnode;
    head->prev = tail;
}

void insertpos(int val, int pos) {
    if (pos == 1) {
        insertbeg(val);
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }
    if (pos - 1 != count) {
        cout << "Invalid position" << endl;
        return;
    }
    if (temp == tail) {
        insertend(val);
        return;
    }
    Node *newnode = new Node(val);
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

void displayforward() {
    if (head == NULL) {
        cout << "List is empty can't display" << endl;
        return;
    }
    Node *temp = head;
    do {
        cout << temp->data << "-->";
        temp = temp->next;
    } while (temp != head);
}

void displaybackward() {
    if (head == NULL) {
        cout << "List is empty can't display" << endl;
        return;
    }
    Node *temp = tail;
    do {
        cout << temp->data << "-->";
        temp = temp->prev;
    } while (temp != head);
}

void deletebeg() {
    if (head == NULL) {
        cout << "List is empty can't delete" << endl;
        return;
    }
    Node *del = head;
    tail->next = head->next;
    head = head->next;
    head->prev = tail;
    delete del;
}

void deleteend() {
    if (head == NULL) {
        cout << "List is empty can't delete" << endl;
        return;
    }
    Node *del = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete del;
}

void deletepos(int pos) {
    if (head == NULL) {
        cout << "List is empty can't delete" << endl;
        return;
    }
    if (pos == 1) {
        deletebeg();
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count < pos && temp->next != head) {
        temp = temp->next;
        count++;
    }
    if (count != pos) {
        cout << "Invalid postion" << endl;
        return;
    }
    if (temp == tail) {
        deleteend();
        return;
    }
    Node *del = temp;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete del;
}

void deleteel(int val) {
    if (head == NULL) {
        cout << "List is empty can't delete" << endl;
        return;
    }
    if (head->data == val) {
        deletebeg();
        return;
    }
    if (tail->data == val) {
        deleteend();
        return;
    }
    Node *temp = head->next;
    do {
        if (temp->data == val) {
            Node *del = temp;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete del;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Element not found" << endl;
}

int main() {
    int c, data, pos;
    do {
        cout << "\n1. Insert at beginning" << endl;
        cout << "2. Insert at ending" << endl;
        cout << "3. Insert at desired position" << endl;
        cout << "4. Delete at beginning" << endl;
        cout << "5. Delete at ending" << endl;
        cout << "6. Delete at desired postion" << endl;
        cout << "7. Delete particular element" << endl;
        cout << "8. Display Forward" << endl;
        cout << "9. Display Backward" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter choice: ";
        cin >> c;

        switch (c) {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            insertbeg(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            insertend(data);
            break;
        case 3:
            cout << "Enter data: ";
            cin >> data;
            cout << "Ener position: ";
            cin >> pos;
            insertpos(data, pos);
            break;
        case 4:
            deletebeg();
            break;
        case 5:
            deleteend();
            break;
        case 6:
            cout << "Enter positon to delete: ";
            cin >> pos;
            deletepos(pos);
            break;
        case 7:
            cout << "Enter element to delete: ";
            cin >> data;
            deleteel(data);
            break;
        case 8:
            displayforward();
            break;
        case 9:
            displaybackward();
            break;
        case 10:
            cout << "Exited!!" << endl;
            break;
        default:
            cout << "Enter valid choice: " << endl;
        }
    } while (c != 10);
}
