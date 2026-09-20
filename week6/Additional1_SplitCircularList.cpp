#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    if (head == nullptr) {
        cout << "Empty";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data;
        temp = temp->next;
        if (temp != head) cout << " -> ";
    } while (temp != head);
}

void splitCircularList(Node* head, Node*& head1, Node*& head2) {
    if (head == nullptr || head->next == head) {
        head1 = head;
        head2 = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head)
        fast = fast->next;

    head1 = head;
    head2 = slow->next;

    slow->next = head1;
    fast->next = head2;
}

int main() {
    // Input: 10 -> 4 -> 9
    Node* n1 = new Node{10, nullptr};
    Node* n2 = new Node{4, nullptr};
    Node* n3 = new Node{9, nullptr};

    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    Node* head1 = nullptr;
    Node* head2 = nullptr;

    splitCircularList(n1, head1, head2);

    cout << "First Circular List: ";
    printList(head1);

    cout << "\nSecond Circular List: ";
    printList(head2);

    cout << endl;
    return 0;
}
