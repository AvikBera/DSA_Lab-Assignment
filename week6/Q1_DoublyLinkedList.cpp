#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

Node* head = nullptr;

void display() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "DLL: ";
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " <=> ";
        temp = temp->next;
    }
    cout << " <=> NULL\n";
}

void insertFirst(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertLast(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(int key, int value) {
    Node* temp = head;

    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Node " << key << " not found.\n";
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void insertBefore(int key, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == key) {
        insertFirst(value);
        return;
    }

    Node* temp = head;
    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Node " << key << " not found.\n";
        return;
    }

    Node* newNode = new Node(value);
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void deleteNode(int key) {
    Node* temp = head;

    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Node " << key << " not found.\n";
        return;
    }

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Node " << key << " deleted.\n";
}

void searchNode(int key) {
    Node* temp = head;
    int position = 1;

    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << position << ".\n";
            return;
        }
        temp = temp->next;
        position++;
    }

    cout << "Node " << key << " not found.\n";
}

int main() {
    int choice, value, key;

    do {
        cout << "\n--- DOUBLY LINKED LIST ---\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert After a Specific Node\n";
        cout << "4. Insert Before a Specific Node\n";
        cout << "5. Delete a Specific Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertFirst(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertLast(value);
            break;

        case 3:
            cout << "Enter node after which to insert: ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> value;
            insertAfter(key, value);
            break;

        case 4:
            cout << "Enter node before which to insert: ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> value;
            insertBefore(key, value);
            break;

        case 5:
            cout << "Enter node to delete: ";
            cin >> key;
            deleteNode(key);
            break;

        case 6:
            cout << "Enter node to search: ";
            cin >> key;
            searchNode(key);
            break;

        case 7:
            display();
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    return 0;
}
