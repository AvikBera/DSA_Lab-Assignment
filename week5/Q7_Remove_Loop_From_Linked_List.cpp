#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

void removeLoop(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return;

    Node* slow = head;
    Node* fast = head;

    // Floyd's cycle detection algorithm.
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow != fast) {
        cout << "No loop found.\n";
        return;
    }

    slow = head;

    // Special case: loop starts at head.
    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
        fast->next = nullptr;
        cout << "Loop removed.\n";
        return;
    }

    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = nullptr;
    cout << "Loop removed.\n";
}

void display(Node* head) {
    Node* current = head;
    int count = 0;

    while (current != nullptr && count < 100) {
        cout << current->data;
        current = current->next;
        count++;

        if (current != nullptr)
            cout << " -> ";
    }

    cout << " -> NULL\n";
}

int main() {
    // Create: 1 -> 2 -> 3 -> 4 -> 5
    // Loop: 5 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* loopNode = head->next->next;
    head->next->next->next->next->next = loopNode;

    removeLoop(head);

    cout << "Linked List after removing loop: ";
    display(head);

    return 0;
}
