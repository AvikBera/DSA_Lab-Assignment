#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* getIntersectionNode(Node* headA, Node* headB) {
    Node* p = headA;
    Node* q = headB;

    while (p != q) {
        p = (p == nullptr) ? headB : p->next;
        q = (q == nullptr) ? headA : q->next;
    }

    return p;
}

int main() {
    // Create the common part: 8 -> 5
    Node* common = new Node(8);
    common->next = new Node(5);

    // First list: 4 -> 1 -> 8 -> 5
    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = common;

    // Second list: 5 -> 6 -> 1 -> 8 -> 5
    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = common;

    Node* intersection = getIntersectionNode(headA, headB);

    if (intersection != nullptr)
        cout << "Intersected at " << intersection->data << endl;
    else
        cout << "No intersection." << endl;

    return 0;
}
