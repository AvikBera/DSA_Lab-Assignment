// (a) Diagonal Matrix
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter size of matrix: ";
    cin >> n;

    int arr[100];

    cout << "Enter diagonal elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Stored elements: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}