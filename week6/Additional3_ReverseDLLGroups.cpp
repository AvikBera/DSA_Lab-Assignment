#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* reverseGroups(Node* head, int k) {
    if (head == nullptr || k <= 1)
        return head;

    Node* current = head;
    Node* newHead = nullptr;
    Node* groupPrev = nullptr;

    while (current != nullptr) {
        Node* groupStart = current;
        Node* previous = nullptr;
        int count = 0;

        while (current != nullptr && count < k) {
            Node* nextNode = current->next;

            current->next = previous;
            current->prev = nextNode;

            previous = current;
            current = nextNode;
            count++;
        }

        if (newHead == nullptr)
            newHead = previous;

        if (groupPrev != nullptr) {
            groupPrev->next = previous;
            previous->prev = groupPrev;
        }

        groupStart->next = current;

        if (current != nullptr)
            current->prev = groupStart;

        groupPrev = groupStart;
    }

    return newHead;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " <-> ";
        head = head->next;
    }
    cout << " <-> NULL\n";
}

int main() {
    Node* n1 = new Node{1, nullptr, nullptr};
    Node* n2 = new Node{2, nullptr, nullptr};
    Node* n3 = new Node{3, nullptr, nullptr};
    Node* n4 = new Node{4, nullptr, nullptr};
    Node* n5 = new Node{5, nullptr, nullptr};
    Node* n6 = new Node{6, nullptr, nullptr};

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;
    n5->next = n6;
    n6->prev = n5;

    int k;
    cout << "Enter k: ";
    cin >> k;

    Node* head = reverseGroups(n1, k);

    cout << "Reversed DLL in groups of " << k << ": ";
    display(head);

    return 0;
}
