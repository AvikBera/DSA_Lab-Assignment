//(a) Using Linear Time — O(n)
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

    int expectedSum = n * (n + 1) / 2;

    int actualSum = 0;

    for (int i = 0; i < n - 1; i++) {
        actualSum = actualSum + arr[i];
    }

    int missing = expectedSum - actualSum;

    cout << "Missing number = " << missing;

    return 0;
}