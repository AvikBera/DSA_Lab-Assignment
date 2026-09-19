// UCS301 Data Structures - Lab Assignment 3 (Week 3)
// Q1: Menu driven program demonstrating stack operations using an array
// Operations: push(), pop(), isEmpty(), isFull(), display(), peek()

#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed to stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n----- Stack Menu -----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            case 4:
                cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl;
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.peek();
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
