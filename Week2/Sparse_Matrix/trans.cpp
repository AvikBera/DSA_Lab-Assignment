// (a) Transpose of a Sparse Matrix
#include <iostream>
using namespace std;

int main() {
    int sparse[100][3];
    int transpose[100][3];

    int rows, cols, nonZero;

    cout << "Enter number of rows, columns and non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = nonZero;

    cout << "Enter row, column and value:\n";

    for (int i = 1; i <= nonZero; i++) {
        cin >> sparse[i][0]
            >> sparse[i][1]
            >> sparse[i][2];
    }

    // Header of transpose
    transpose[0][0] = cols;
    transpose[0][1] = rows;
    transpose[0][2] = nonZero;

    int k = 1;

    // Swap row and column
    for (int col = 0; col < cols; col++) {

        for (int i = 1; i <= nonZero; i++) {

            if (sparse[i][1] == col) {

                transpose[k][0] = sparse[i][1];
                transpose[k][1] = sparse[i][0];
                transpose[k][2] = sparse[i][2];

                k++;
            }
        }
    }

    cout << "\nTranspose in Triplet Form:\n";

    for (int i = 0; i <= nonZero; i++) {
        cout << transpose[i][0] << " "
             << transpose[i][1] << " "
             << transpose[i][2] << endl;
    }

    return 0;
}