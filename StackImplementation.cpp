// STACK IMPLEMENTATION USING ARRAY
#include<iostream>
using namespace std;

int top = -1, n;

void disp(int arr[]) {
    for (int i = 0; i <= top; i++)
        cout << arr[i] << endl;
}

int isEmpty() {
    if (top == -1)
        return 1;
    return 0;
}

int isFull() {
    if (top == n - 1)
        return 1;
    return 0;
}

void push(int arr[], int k) {
    if (!isFull()) {
        top++;
        arr[top] = k;
        cout << "Element " << arr[top] << " is successfully pushed" << endl;
    } else
        cout << "Stack is full\n";
}

void pop(int arr[]) {
    if (!isEmpty()) {
        top--;
        cout << "Element " << arr[top + 1] << " is successfully poped\n";
    } else
        cout << "Stack is Empty" << endl;
}

int main() {
    int k;
    cout << "Enter the max size of the stack: ";
    cin >> n;
    int stack[n];

    while (1) {
        cout << "\nEnter character for function\n";
        cout << "p: push" << endl;
        cout << "P: Pop" << endl;
        cout << "d: display" << endl;
        cout << "e: Exit" << endl;

        char ch;
        cin >> ch;

        switch (ch) {
            case 'p': {
                cout << "Enter value of element to push: ";
                cin >> k;
                push(stack, k);
                break;
            }
            case 'P': {
                pop(stack);
                break;
            }
            case 'd':
            case 'D': {
                disp(stack);
                break;
            }
            case 'e':
            case 'E': {
                cout << "Program end!!" << endl;
                return 0;
            }
            default: {
                cout << "Enter valid character!\n";
            }
        }
    }
}
