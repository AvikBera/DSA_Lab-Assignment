#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;

    Node(char value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

bool isPalindrome(Node* head) {
    if (head == nullptr)
        return true;

    Node* left = head;
    Node* right = head;

    while (right->next != nullptr)
        right = right->next;

    while (left != right && left->prev != right) {
        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {
    string str;
    cout << "Enter characters/string: ";
    cin >> str;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (char ch : str) {
        Node* newNode = new Node(ch);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    if (isPalindrome(head))
        cout << "True - The doubly linked list is a palindrome.\n";
    else
        cout << "False - The doubly linked list is not a palindrome.\n";

    return 0;
}
