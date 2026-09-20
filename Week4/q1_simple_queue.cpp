// Q1: Simple Queue (Array Implementation) - Menu Driven Program
#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        if (isEmpty())
            front = 0;
        arr[++rear] = value;
        cout << value << " enqueued to queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return;
        }
        cout << arr[front] << " dequeued from queue." << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements (front to rear): ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n===== Simple Queue Menu =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 4:
                cout << (q.isFull() ? "Queue is full." : "Queue is not full.") << endl;
                break;
            case 5:
                q.display();
                break;
            case 6:
                q.peek();
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
