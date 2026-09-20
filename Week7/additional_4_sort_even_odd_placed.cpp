#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortEvenOddPlaced(vector<int> arr) {
    vector<int> evenPlaced, oddPlaced;

    // index 0 is considered even-placed
    for (int i = 0; i < (int)arr.size(); i++) {
        if (i % 2 == 0) evenPlaced.push_back(arr[i]);
        else oddPlaced.push_back(arr[i]);
    }

    sort(evenPlaced.begin(), evenPlaced.end());                 // increasing
    sort(oddPlaced.begin(), oddPlaced.end(), greater<int>());   // decreasing

    vector<int> result;
    result.insert(result.end(), evenPlaced.begin(), evenPlaced.end());
    result.insert(result.end(), oddPlaced.begin(), oddPlaced.end());

    return result;
}

void printArray(const vector<int>& arr) {
    cout << "{";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
}

int main() {
    vector<int> arr1 = {0, 1, 2, 3, 4, 5, 6, 7};
    cout << "Result: ";
    printArray(sortEvenOddPlaced(arr1));

    vector<int> arr2 = {3, 1, 2, 4, 5, 9, 13, 14, 12};
    cout << "Result: ";
    printArray(sortEvenOddPlaced(arr2));

    return 0;
}
