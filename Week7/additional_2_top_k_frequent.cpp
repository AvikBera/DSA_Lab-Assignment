#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> topKFrequent(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    for (int x : arr) freq[x]++;

    vector<pair<int, int>> elements(freq.begin(), freq.end()); // {value, frequency}

    // Sort by frequency descending; break ties by the larger value first
    sort(elements.begin(), elements.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first > b.first;
    });

    vector<int> result;
    for (int i = 0; i < k && i < (int)elements.size(); i++)
        result.push_back(elements[i].first);

    return result;
}

void printArray(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> arr1 = {3, 1, 4, 4, 5, 2, 6, 1};
    cout << "Top 2 frequent: ";
    printArray(topKFrequent(arr1, 2));

    vector<int> arr2 = {7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9};
    cout << "Top 4 frequent: ";
    printArray(topKFrequent(arr2, 4));

    return 0;
}
