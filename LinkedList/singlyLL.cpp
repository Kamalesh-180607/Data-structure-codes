// LINKEDLIST IMPLEMENTATION
#include<iostream>
using namespace std;

static int count = 0;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertend(Node*& head, int val) {
    Node *newnode = new Node(val);

    if (head == NULL) {
        head = newnode;
    }
    else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    count++;
}

void insertbeg(Node*& head, int val) {
    if (head == NULL) {
        insertend(head, val);
    }
    else {
        Node *newnode = new Node(val);
        newnode->next = head;
        head = newnode;
        count++;
    }
}

void insertpos(Node*& head, int val, int pos) {
    if (pos == 1) {
        insertbeg(head, val);
        return;
    }
    if (pos <= count) {
        int i = 1;
        Node *temp = head;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        Node* newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;
        count++;
    }
    else {
        cout << "Invalid position!!" << endl;
    }
}

void deletebeg(Node*& head) {
    if (head == NULL) {
        cout << "List is empty can't delete" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    count--;
}

void deleteend(Node* head) {
    if (head == NULL) {
        cout << "List is empty can't delete" << endl;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node *tempvar = temp->next;
    temp->next = NULL;
    delete tempvar;
    count--;
}

void deletepos(Node*& head, int pos) {
    if (pos == 1) {
        deletebeg(head);
        return;
    }
    if (head == NULL) {
        cout << "List is empty can't delete" << endl;
        return;
    }
    if (pos > count) {
        cout << "Invalid position to delete" << endl;
        return;
    }
    if (count == pos) {
        deleteend(head);
        return;
    }
    Node *temp = head;
    int i = 1;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    Node *tempvar = temp->next;
    temp->next = temp->next->next;
    delete tempvar;
    count--;
}

void display(Node *head) {
    if (head == NULL) {
        cout << "List is empty can't display" << endl;
        return;
    }
    cout << "The elements are: ";
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << "--->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteel(Node*& head, int val) {
    int ck = 1;
    Node *temp = head;
    while (temp->data != val) {
        temp = temp->next;
        if (temp == NULL) {
            cout << "\nElement not found!!" << endl;
            return;
        }
        ck++;
    }
    if (ck == 1) {
        deletebeg(head);
        return;
    }
    if (ck > 1) {
        deletepos(head, ck);
    }
}

int main() {
    Node *head = NULL;
    int c;
    do {
        cout << "1. Insert at beginning\n2. Insert at ending\n3. Insert at desired position\n";
        cout << "4. Delete from beginning\n5. Delete from ending\n";
        cout << "6. Delete from desired position\n7. Delete desired element\n";
        cout << "8. Display\n9. Exit!!\n";
        cout << "Enter choice: ";
        cin >> c;

        switch (c) {
            case 1: {
                int n;
                cout << "Enter element to insert: ";
                cin >> n;
                insertbeg(head, n);
                break;
            }
            case 2: {
                int k;
                cout << "Enter element to insert: ";
                cin >> k;
                insertend(head, k);
                break;
            }
            case 3: {
                int o;
                cout << "Enter element to insert: ";
                cin >> o;
                cout << "Enter position to insert: ";
                int pos;
                cin >> pos;
                insertpos(head, o, pos);
                break;
            }
            case 4:
                deletebeg(head);
                break;
            case 5:
                deleteend(head);
                break;
            case 6: {
                int x;
                cout << "Enter position to delete: ";
                cin >> x;
                deletepos(head, x);
                break;
            }
            case 7: {
                int el;
                cout << "Enter element to delete: ";
                cin >> el;
                deleteel(head, el);
                break;
            }
            case 8:
                display(head);
                break;
            case 9:
                cout << "Exited!!";
                break;
            default:
                cout << "\nEnter valid choice\n";
        }
    } while (c != 9);
}
