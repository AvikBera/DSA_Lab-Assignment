// 8) Count Total Number of Distinct Elements
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

    for (int i = 0; i < n; i++) {

        bool duplicate = false;

        for (int j = 0; j < i; j++) {

            if (arr[i] == arr[j]) {
                duplicate = true;
                break;
            }
        }

        if (duplicate == false) {
            count++;
        }
    }

    cout << "Total number of distinct elements = " << count;

    return 0;
}