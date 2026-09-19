// 7) Count the Number of Inversions in an Array
#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    int count = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }

    cout << "Number of inversions = " << count;

    return 0;
}