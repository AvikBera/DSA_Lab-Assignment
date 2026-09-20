#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
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
    cout << "CLL: ";

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "HEAD\n";
}

void insertFirst(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* last = head;
    while (last->next != head)
        last = last->next;

    newNode->next = head;
    last->next = newNode;
    head = newNode;
}

void insertLast(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* last = head;
    while (last->next != head)
        last = last->next;

    last->next = newNode;
    newNode->next = head;
}

void insertAfter(int key, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    do {
        if (temp->data == key) {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Node " << key << " not found.\n";
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

    Node* prev = head;
    Node* temp = head->next;

    while (temp != head) {
        if (temp->data == key) {
            Node* newNode = new Node(value);
            newNode->next = temp;
            prev->next = newNode;
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Node " << key << " not found.\n";
}

void deleteNode(int key) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == key) {
        if (head->next == head) {
            delete head;
            head = nullptr;
            cout << "Node " << key << " deleted.\n";
            return;
        }

        Node* last = head;
        while (last->next != head)
            last = last->next;

        Node* temp = head;
        head = head->next;
        last->next = head;
        delete temp;

        cout << "Node " << key << " deleted.\n";
        return;
    }

    Node* prev = head;
    Node* temp = head->next;

    while (temp != head) {
        if (temp->data == key) {
            prev->next = temp->next;
            delete temp;
            cout << "Node " << key << " deleted.\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Node " << key << " not found.\n";
}

void searchNode(int key) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    int position = 1;

    do {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << position << ".\n";
            return;
        }

        temp = temp->next;
        position++;
    } while (temp != head);

    cout << "Node " << key << " not found.\n";
}

int main() {
    int choice, value, key;

    do {
        cout << "\n--- CIRCULAR LINKED LIST ---\n";
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
