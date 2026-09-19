//4. a. Reverse the elements of an array

#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

 cout << "Enter the number of elements: ";
 cin >> n;

cout << "Enter the array elements: ";
 for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
 for (int i = 0, j = n - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}