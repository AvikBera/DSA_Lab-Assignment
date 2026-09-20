#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

int countOccurrences(Node* head, int key) {
    int count = 0;

    while (head != nullptr) {
        if (head->data == key)
            count++;
        head = head->next;
    }

    return count;
}

void deleteAllOccurrences(Node*& head, int key) {
    while (head != nullptr && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(head, value);
    }

    cout << "Enter key: ";
    cin >> key;

    int count = countOccurrences(head, key);
    deleteAllOccurrences(head, key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    display(head);

    return 0;
}
