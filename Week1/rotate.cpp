//3) Design the logic of a program to rotate a 1-D array by K positions.
#include <iostream>
using namespace std;

int main() {
    int arr[100], temp[100];
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter K: ";
    cin >> k;
    k = k % n;
    int j = 0;

for (int i = k; i < n; i++) {
    temp[j] = arr[i];
    j++;
}

for (int i = 0; i < k; i++) {
    temp[j] = arr[i];
    j++;
    }

cout << "Rotated array: ";
for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }

    return 0;
}