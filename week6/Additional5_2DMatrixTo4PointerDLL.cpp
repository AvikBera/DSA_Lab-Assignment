#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
        up = nullptr;
        down = nullptr;
    }
};

Node* create4PointerDLL(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<Node*>> nodes(rows, vector<Node*>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            nodes[i][j] = new Node(matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j + 1 < cols)
                nodes[i][j]->next = nodes[i][j + 1];

            if (j - 1 >= 0)
                nodes[i][j]->prev = nodes[i][j - 1];

            if (i - 1 >= 0)
                nodes[i][j]->up = nodes[i - 1][j];

            if (i + 1 < rows)
                nodes[i][j]->down = nodes[i + 1][j];
        }
    }

    return nodes[0][0];
}

void displayMatrix(Node* head, int rows, int cols) {
    Node* rowStart = head;

    for (int i = 0; i < rows; i++) {
        Node* temp = rowStart;

        for (int j = 0; j < cols; j++) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
        rowStart = rowStart->down;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = create4PointerDLL(matrix);

    cout << "4-pointer doubly linked list:\n";
    displayMatrix(head, 3, 3);

    return 0;
}
