// 1) Implement the binary search algorithm regarded as a fast search algorithm
// with run-time complexity of Ο(log n) in comparison to the Linear Search.
#include <iostream>
using namespace std;

int main() {
    int arr[100], n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int low = 0;
    int high = n - 1;
    bool found = false;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            cout << "Element found at index " << mid;
            found = true;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (found == false) {
        cout << "Element not found";
    }

    return 0;
}