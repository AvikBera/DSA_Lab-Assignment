//5.Write a program to find sum of every row and every column in a two-dimensional array
#include <iostream>
using namespace std;

int main() {
    int arr[100][100];
    int rows, cols;

cout << "Enter number of rows: ";
cin >> rows;

cout << "Enter number of columns: ";
cin >> cols;

cout << "Enter array elements:\n";

for (int i = 0; i < rows; i++) {
 for (int j = 0; j < cols; j++) {
     cin >> arr[i][j];
       }
    }

cout << "\nSum of each row:\n";

for (int i = 0; i < rows; i++) {
     int rowSum = 0;

for (int j = 0; j < cols; j++) {
            rowSum += arr[i][j];
     }

    cout << "Row " << i + 1 << " = " << rowSum << endl;
    }

    cout << "\nSum of each column:\n";

for (int j = 0; j < cols; j++) {
        int colSum = 0;

 for (int i = 0; i < rows; i++) {
            colSum += arr[i][j];
        }

        cout << "Column " << j + 1 << " = " << colSum << endl;
    }

    return 0;
}