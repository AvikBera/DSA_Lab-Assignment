#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int value) {
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

    void insertBefore(int value, int target) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == target) {
            insertBeginning(value);
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != target)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Target node not found.\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int value, int target) {
        Node* temp = head;

        while (temp != nullptr && temp->data != target)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Target node not found.\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    void deleteSpecific(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            deleteBeginning();
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Node not found.\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void search(int value) {
        Node* temp = head;
        int position = 1;

        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Node found at position " << position << " from head.\n";
                return;
            }
            temp = temp->next;
            position++;
        }

        cout << "Node not found.\n";
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, target;

    do {
        cout << "\n===== SINGLY LINKED LIST =====\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a node\n";
        cout << "4. Insert after a node\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search a node\n";
        cout << "9. Display all nodes\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertEnd(value);
                break;

            case 3:
                cout << "Enter new value: ";
                cin >> value;
                cout << "Insert before which value? ";
                cin >> target;
                list.insertBefore(value, target);
                break;

            case 4:
                cout << "Enter new value: ";
                cin >> value;
                cout << "Insert after which value? ";
                cin >> target;
                list.insertAfter(value, target);
                break;

            case 5:
                list.deleteBeginning();
                break;

            case 6:
                list.deleteEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteSpecific(value);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;

            case 9:
                list.display();
                break;

            case 0:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
