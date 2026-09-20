#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node* random;
};

void correctRandomPointer(Node* head, int expectedData, int randomData) {
    Node* expected = nullptr;
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == expectedData) {
            expected = temp;
            break;
        }
        temp = temp->next;
    }

    if (expected == nullptr) {
        cout << "Expected node not found.\n";
        return;
    }

    temp = head;

    while (temp != nullptr) {
        if (temp->random != nullptr && temp->random->data == randomData) {
            temp->random = expected;
        }
        temp = temp->next;
    }
}

void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << "Node " << temp->data << " -> Random: ";

        if (temp->random != nullptr)
            cout << temp->random->data;
        else
            cout << "NULL";

        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Demonstration list:
    // 10 <=> 20 <=> 30 <=> 40
    Node* n1 = new Node{10, nullptr, nullptr, nullptr};
    Node* n2 = new Node{20, nullptr, nullptr, nullptr};
    Node* n3 = new Node{30, nullptr, nullptr, nullptr};
    Node* n4 = new Node{40, nullptr, nullptr, nullptr};

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;

    // Suppose the random pointer of node 20 is incorrect.
    n2->random = n4;

    cout << "Before correction:\n";
    display(n1);

    // Correct node 20's random pointer to node 10.
    correctRandomPointer(n1, 10, 40);

    cout << "\nAfter correction:\n";
    display(n1);

    return 0;
}
