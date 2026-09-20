#include <iostream>
#include <vector>
using namespace std;

// Improved Selection Sort: in every pass, find BOTH the minimum and the
// maximum and place them at their correct positions from both ends of
// the unsorted region. This roughly halves the number of passes needed.
void improvedSelectionSort(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int minIdx = left, maxIdx = left;

        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIdx]) minIdx = i;
            if (arr[i] > arr[maxIdx]) maxIdx = i;
        }

        // Place minimum at 'left'
        swap(arr[left], arr[minIdx]);

        // If the maximum happened to be sitting at 'left' before that
        // swap, it has now moved to 'minIdx' — track its new location.
        if (maxIdx == left) maxIdx = minIdx;

        // Place maximum at 'right'
        swap(arr[right], arr[maxIdx]);

        left++;
        right--;
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11, 90, 5};

    cout << "Original array: ";
    printArray(arr);

    improvedSelectionSort(arr);

    cout << "Sorted array:   ";
    printArray(arr);
    return 0;
}
