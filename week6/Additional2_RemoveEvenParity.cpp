#include <iostream>
using namespace std;

int parity(int x) {
    int count = 0;

    while (x > 0) {
        count += (x & 1);
        x >>= 1;
    }

    return count;
}

// ---------------- DOUBLY LINKED LIST ----------------

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

void removeEvenParityDLL(DNode*& head) {
    DNode* temp = head;

    while (temp != nullptr) {
        DNode* nextNode = temp->next;

        if (parity(temp->data) % 2 == 0) {
            if (temp->prev != nullptr)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != nullptr)
                temp->next->prev = temp->prev;

            delete temp;
        }

        temp = nextNode;
    }
}

void printDLL(DNode* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " <=> ";
        head = head->next;
    }
}

// ---------------- CIRCULAR LINKED LIST ----------------

struct CNode {
    int data;
    CNode* next;
};

void removeEvenParityCLL(CNode*& head) {
    if (head == nullptr)
        return;

    // Find last node.
    CNode* last = head;
    while (last->next != head)
        last = last->next;

    CNode* prev = last;
    CNode* current = head;

    do {
        CNode* nextNode = current->next;

        if (parity(current->data) % 2 == 0) {
            if (current == head)
                head = nextNode;

            prev->next = nextNode;
            delete current;

            if (nextNode == head && prev == nextNode)
                break;
        } else {
            prev = current;
        }

        current = nextNode;

        if (head == nullptr)
            break;

    } while (current != head);
}

void printCLL(CNode* head) {
    if (head == nullptr)
        return;

    CNode* temp = head;

    do {
        cout << temp->data;
        temp = temp->next;
        if (temp != head) cout << " -> ";
    } while (temp != head);
}

int main() {
    // CLL example: 9 -> 11 -> 34 -> 6 -> 13 -> 21
    CNode* c1 = new CNode{9, nullptr};
    CNode* c2 = new CNode{11, nullptr};
    CNode* c3 = new CNode{34, nullptr};
    CNode* c4 = new CNode{6, nullptr};
    CNode* c5 = new CNode{13, nullptr};
    CNode* c6 = new CNode{21, nullptr};

    c1->next = c2;
    c2->next = c3;
    c3->next = c4;
    c4->next = c5;
    c5->next = c6;
    c6->next = c1;

    cout << "CLL after removing even parity nodes: ";
    removeEvenParityCLL(c1);
    printCLL(c1);
    cout << endl;

    // DLL example: 18 <=> 15 <=> 8 <=> 9 <=> 14
    DNode* d1 = new DNode{18, nullptr, nullptr};
    DNode* d2 = new DNode{15, d1, nullptr};
    DNode* d3 = new DNode{8, d2, nullptr};
    DNode* d4 = new DNode{9, d3, nullptr};
    DNode* d5 = new DNode{14, d4, nullptr};

    d1->next = d2;
    d2->next = d3;
    d3->next = d4;
    d4->next = d5;

    removeEvenParityDLL(d1);

    cout << "DLL after removing even parity nodes: ";
    printDLL(d1);
    cout << endl;

    return 0;
}
