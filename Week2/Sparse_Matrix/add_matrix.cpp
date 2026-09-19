// (b) Addition of Two Sparse Matrices
#include <iostream>
using namespace std;

int main() {
    int A[100][3], B[100][3], C[200][3];

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

    // Check dimensions
    if (r1 != r2 || c1 != c2) {
        cout << "Addition not possible";
        return 0;
    }

    int i = 1;
    int j = 1;
    int k = 1;

    C[0][0] = r1;
    C[0][1] = c1;

    while (i <= n1 && j <= n2) {

        // Same position
        if (A[i][0] == B[j][0] &&
            A[i][1] == B[j][1]) {

            int sum = A[i][2] + B[j][2];

            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }

            i++;
            j++;
        }

        // A comes first
        else if (A[i][0] < B[j][0] ||
                (A[i][0] == B[j][0] &&
                 A[i][1] < B[j][1])) {

            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];

            i++;
            k++;
        }

        // B comes first
        else {

            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];

            j++;
            k++;
        }
    }

    // Remaining elements of A
    while (i <= n1) {

        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];

        i++;
        k++;
    }

    // Remaining elements of B
    while (j <= n2) {

        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];

        j++;
        k++;
    }

    C[0][2] = k - 1;

    cout << "\nAddition Result:\n";

    for (int x = 0; x < k; x++) {
        cout << C[x][0] << " "
             << C[x][1] << " "
             << C[x][2] << endl;
    }

    return 0;
}