#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (head == nullptr)
        return false;

    Node* temp = head->next;

    while (temp != nullptr && temp != head)
        temp = temp->next;

    return temp == head;
}

int main() {
    Node* n1 = new Node{2, nullptr};
    Node* n2 = new Node{4, nullptr};
    Node* n3 = new Node{6, nullptr};
    Node* n4 = new Node{7, nullptr};
    Node* n5 = new Node{5, nullptr};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // To make this a Circular Linked List:
    n5->next = n1;

    if (isCircular(n1))
        cout << "True - It is a Circular Linked List.\n";
    else
        cout << "False - It is not a Circular Linked List.\n";

    return 0;
}
