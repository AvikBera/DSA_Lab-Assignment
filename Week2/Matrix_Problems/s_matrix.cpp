// (e) Symmetric Matrix
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter size of matrix: ";
    cin >> n;

    int arr[100];
    int k = 0;

    cout << "Enter lower triangular elements:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j <= i; j++) {
            cin >> arr[k];
            k++;
        }
    }

    cout << "Stored elements: ";

    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}