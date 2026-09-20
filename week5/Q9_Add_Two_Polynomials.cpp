#include <iostream>
using namespace std;

struct Node {
    int coefficient;
    int power;
    Node* next;

    Node(int c, int p) : coefficient(c), power(p), next(nullptr) {}
};

void insertEnd(Node*& head, int coefficient, int power) {
    Node* newNode = new Node(coefficient, power);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

Node* addPolynomials(Node* first, Node* second) {
    Node* result = nullptr;

    while (first != nullptr && second != nullptr) {
        if (first->power == second->power) {
            int sum = first->coefficient + second->coefficient;

            if (sum != 0)
                insertEnd(result, sum, first->power);

            first = first->next;
            second = second->next;
        }
        else if (first->power > second->power) {
            insertEnd(result, first->coefficient, first->power);
            first = first->next;
        }
        else {
            insertEnd(result, second->coefficient, second->power);
            second = second->next;
        }
    }

    while (first != nullptr) {
        insertEnd(result, first->coefficient, first->power);
        first = first->next;
    }

    while (second != nullptr) {
        insertEnd(result, second->coefficient, second->power);
        second = second->next;
    }

    return result;
}

void display(Node* head) {
    cout << "[";
    while (head != nullptr) {
        cout << "[" << head->coefficient << ", " << head->power << "]";
        if (head->next != nullptr)
            cout << ", ";
        head = head->next;
    }
    cout << "]\n";
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    // Input from the assignment:
    // list1: [[5,2], [4,1], [2,0]]
    // list2: [[5,1], [5,0]]
    insertEnd(list1, 5, 2);
    insertEnd(list1, 4, 1);
    insertEnd(list1, 2, 0);

    insertEnd(list2, 5, 1);
    insertEnd(list2, 5, 0);

    Node* result = addPolynomials(list1, list2);

    cout << "List 1: ";
    display(list1);

    cout << "List 2: ";
    display(list2);

    cout << "Sum: ";
    display(result);

    return 0;
}
