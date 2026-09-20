#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

int getSize(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    Node* n1 = new Node{10, nullptr, nullptr};
    Node* n2 = new Node{20, n1, nullptr};
    Node* n3 = new Node{30, n2, nullptr};

    n1->next = n2;
    n2->next = n3;

    cout << "Size of Doubly Linked List = " << getSize(n1) << endl;

    return 0;
}
