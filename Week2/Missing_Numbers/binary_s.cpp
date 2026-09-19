// (b) Using Binary Search — O(log n)
#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter " << n - 1 << " elements: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    int low = 0;
    int high = n - 2;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == mid + 1) {
            // Missing number is on the right
            low = mid + 1;
        }
        else {
            // Missing number is on the left
            high = mid - 1;
        }
    }

    cout << "Missing number = " << low + 1;

    return 0;
}