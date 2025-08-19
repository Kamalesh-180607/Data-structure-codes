// CIRCULAR QUEUE IMPLEMENTATION USING ARRAY
#include<iostream>
using namespace std;

#define MAX 5

class queue {
    int front, rear;
    int q[MAX];

public:
    queue() {
        front = rear = -1;
    }

    int isempty() {
        return (front == -1);
    }

    int isfull() {
        return (front == (rear + 1) % MAX);
    }

    void EnQueue(int x) {
        if (!isfull()) {
            if (front == -1)
                front += 1;
            rear = (rear + 1) % MAX;
            q[rear] = x;
            cout << "\nElement " << x << " is successfully inserted";
        }
        else {
            cout << "\nQueue is full can't insert";
        }
    }

    void DeQueue() {
        if (!isempty()) {
            if (front == rear) {
                cout << "\nElement " << q[front] << " is successfully deleted";
                front = rear = -1;
            }
            else {
                cout << "\nElement " << q[front] << " is successfully deleted";
                front = (front + 1) % MAX;
            }
        }
        else {
            cout << "\nQueue is empty can't delete";
        }
    }

    void display() {
        if (isempty()) {
            cout << "\nQueue is empty can't display";
            return;
        }
        cout << "\nQueue elements are: ";
        int temp = front;
        while (1) {
            if (temp == rear) {
                cout << q[temp] << " ";
                break;
            }
            else {
                cout << q[temp] << " ";
                temp = (temp + 1) % MAX;
            }
        }
    }
};

int main() {
    int k;
    queue q;

    do {
        cout << "\nChoose one option:\n";
        cout << "\n1. Insertion ";
        cout << "\n2. Deletion ";
        cout << "\n3. Display ";
        cout << "\n4. Exit!!\n";
        cin >> k;

        switch (k) {
            case 1: {
                int x;
                cout << "\nEnter element to insert: ";
                cin >> x;
                q.EnQueue(x);
                break;
            }
            case 2:
                q.DeQueue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "\nExited\n";
                break;
            default:
                cout << "\nChoose correct option";
        }
    } while (k != 4);
}
