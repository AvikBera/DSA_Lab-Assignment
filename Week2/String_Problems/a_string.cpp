// (d) Sort Strings in Alphabetical Order
#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr[100];
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    cout << "Enter strings:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Strings in alphabetical order:\n";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}