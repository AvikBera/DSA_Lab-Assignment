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

Node* reverseKGroup(Node* head, int k) {
    if (head == nullptr || k <= 1)
        return head;

    Node* current = head;
    int count = 0;

    // Check whether k nodes are available.
    while (current != nullptr && count < k) {
        current = current->next;
        count++;
    }

    // If fewer than k nodes remain, leave them unchanged.
    if (count < k)
        return head;

    Node* previous = nullptr;
    current = head;

    for (int i = 0; i < k; i++) {
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head->next = reverseKGroup(current, k);

    return previous;
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
    int n, value, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(head, value);
    }

    cout << "Enter K: ";
    cin >> k;

    head = reverseKGroup(head, k);

    cout << "Result: ";
    display(head);

    return 0;
}
