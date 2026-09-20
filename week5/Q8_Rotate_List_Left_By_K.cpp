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

int getLength(Node* head) {
    int length = 0;

    while (head != nullptr) {
        length++;
        head = head->next;
    }

    return length;
}

Node* rotateLeft(Node* head, int k) {
    if (head == nullptr || head->next == nullptr)
        return head;

    int length = getLength(head);
    k = k % length;

    if (k == 0)
        return head;

    Node* current = head;

    for (int i = 1; i < k; i++)
        current = current->next;

    Node* newHead = current->next;
    current->next = nullptr;

    Node* tail = newHead;
    while (tail->next != nullptr)
        tail = tail->next;

    tail->next = head;

    return newHead;
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

    head = rotateLeft(head, k);

    cout << "Updated List: ";
    display(head);

    return 0;
}
