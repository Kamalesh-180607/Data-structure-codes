// QUEUE IMPLEMENTATION USING ARRAY
#include<iostream>
using namespace std;

#define SIZE 5

class queue {
    int front, rear;
    int q[SIZE];

public:
    queue() {
        front = rear = -1;
    }

    int isempty() {
        return (front == -1);
    }

    int isfull() {
        return (rear == SIZE - 1);
    }

    void EnQueue(int x) {
        if (!isfull()) {
            if (front == -1)
                front += 1;
            rear += 1;
            q[rear] = x;
            cout << "\nElement " << x << " is successfully inserted";
        }
        else {
            cout << "\nQueue is full can't insert";
        }
    }

    void DeQueue() {
        if (!isempty() && front <= rear) {
            cout << "\nElement " << q[front] << " is successfully deleted";
            front++;
            if (front > rear) {
                front = rear = -1; // Reset queue when empty
            }
        }
        else {
            cout << "\nQueue is empty can't delete";
        }
    }

    void display() {
        if (front != -1 && front <= rear) {
            cout << "\nThe elements in queue: ";
            for (int i = front; i <= rear; i++)
                cout << q[i] << " ";
        }
        else {
            cout << "\nQueue is empty can't display";
        }
    }
};

int main() {
    queue q;
    int k;
    do {
        cout << "\nChoose one option: ";
        cout << "\n1. Insertion";
        cout << "\n2. Deletion";
        cout << "\n3. Display";
        cout << "\n4. Exit\n";
        cin >> k;

        switch (k) {
            case 1: {
                int x;
                cout << "Enter element to insert: ";
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
                cout << "\nChoose the correct option\n";
        }
    } while (k != 4);
}
