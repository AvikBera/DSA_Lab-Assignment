//4.c. Find the Transpose of a Matrix
#include <iostream>
using namespace std;

int main() {
 int arr[100][100], rows, cols;

 cout << "Enter number of rows: ";
 cin >> rows;

cout << "Enter number of columns: ";
 cin >> cols;

    cout << "Enter matrix elements: "<<endl;
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        cin >> arr[i][j];
        }
    }

cout << "Transpose of matrix:\n";

 for (int j = 0; j < cols; j++) {
    for (int i = 0; i < rows; i++) {
    cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}