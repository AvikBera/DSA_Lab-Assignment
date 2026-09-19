// (b) Tri-Diagonal Matrix
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter size of matrix: ";
    cin >> n;

    int arr[300];
    int k = 0;

    cout << "Enter tri-diagonal elements:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (abs(i - j) <= 1) {
                cin >> arr[k];
                k++;
            }
        }
    }

    cout << "Stored elements: ";

    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}