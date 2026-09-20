// Q2: Circular Queue (Array Implementation) - Menu Driven Program
#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX == front);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Circular Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = value;
        cout << value << " enqueued to circular queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue Underflow! Queue is empty." << endl;
            return;
        }
        cout << arr[front] << " dequeued from circular queue." << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
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
            cout << "Circular Queue is empty." << endl;
            return;
        }
        cout << "Circular Queue elements (front to rear): ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n===== Circular Queue Menu (Capacity = " << MAX << ") =====" << endl;
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
