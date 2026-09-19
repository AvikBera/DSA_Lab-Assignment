// (c) Multiplication of Two Sparse Matrices
#include <iostream>
using namespace std;

int main() {
    int A[100][3];
    int B[100][3];
    int C[100][3];

    int r1, c1, n1;
    int r2, c2, n2;

    // Matrix A
    cout << "Enter rows, columns and non-zero elements of A: ";
    cin >> r1 >> c1 >> n1;

    A[0][0] = r1;
    A[0][1] = c1;
    A[0][2] = n1;

    cout << "Enter triplets of A:\n";

    for (int i = 1; i <= n1; i++) {
        cin >> A[i][0]
            >> A[i][1]
            >> A[i][2];
    }

    // Matrix B
    cout << "Enter rows, columns and non-zero elements of B: ";
    cin >> r2 >> c2 >> n2;

    B[0][0] = r2;
    B[0][1] = c2;
    B[0][2] = n2;

    cout << "Enter triplets of B:\n";

    for (int i = 1; i <= n2; i++) {
        cin >> B[i][0]
            >> B[i][1]
            >> B[i][2];
    }

    // Check multiplication condition
    if (c1 != r2) {
        cout << "Multiplication not possible";
        return 0;
    }

    // Normal matrices
    int matA[20][20] = {0};
    int matB[20][20] = {0};
    int matC[20][20] = {0};

    // Convert A triplet to normal matrix
    for (int i = 1; i <= n1; i++) {
        int row = A[i][0];
        int col = A[i][1];
        int value = A[i][2];

        matA[row][col] = value;
    }

    // Convert B triplet to normal matrix
    for (int i = 1; i <= n2; i++) {
        int row = B[i][0];
        int col = B[i][1];
        int value = B[i][2];

        matB[row][col] = value;
    }

    // Matrix multiplication
    for (int i = 0; i < r1; i++) {

        for (int j = 0; j < c2; j++) {

            for (int k = 0; k < c1; k++) {

                matC[i][j] =
                    matC[i][j] +
                    matA[i][k] * matB[k][j];
            }
        }
    }

    // Count non-zero elements
    int count = 0;

    for (int i = 0; i < r1; i++) {

        for (int j = 0; j < c2; j++) {

            if (matC[i][j] != 0) {
                count++;
            }
        }
    }

    // Create result triplet
    C[0][0] = r1;
    C[0][1] = c2;
    C[0][2] = count;

    int k = 1;

    for (int i = 0; i < r1; i++) {

        for (int j = 0; j < c2; j++) {

            if (matC[i][j] != 0) {

                C[k][0] = i;
                C[k][1] = j;
                C[k][2] = matC[i][j];

                k++;
            }
        }
    }

    cout << "\nMultiplication Result:\n";

    for (int i = 0; i < k; i++) {
        cout << C[i][0] << " "
             << C[i][1] << " "
             << C[i][2] << endl;
    }

    return 0;
}