#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

vector<int> maxSumCombinations(vector<int> a, vector<int> b, int k) {
    int n = a.size();
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    // Max-heap of {sum, i, j} - a[i] + b[j] is a candidate sum
    priority_queue<vector<int>> pq;
    set<pair<int, int>> visited;

    pq.push({a[0] + b[0], 0, 0});
    visited.insert({0, 0});

    vector<int> result;

    while (k-- > 0 && !pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int sum = top[0], i = top[1], j = top[2];
        result.push_back(sum);

        if (i + 1 < n && !visited.count({i + 1, j})) {
            pq.push({a[i + 1] + b[j], i + 1, j});
            visited.insert({i + 1, j});
        }
        if (j + 1 < n && !visited.count({i, j + 1})) {
            pq.push({a[i] + b[j + 1], i, j + 1});
            visited.insert({i, j + 1});
        }
    }
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
    vector<int> a1 = {3, 2}, b1 = {1, 4};
    cout << "Top 2 sums: ";
    printArray(maxSumCombinations(a1, b1, 2));

    vector<int> a2 = {1, 4, 2, 3}, b2 = {2, 5, 1, 6};
    cout << "Top 3 sums: ";
    printArray(maxSumCombinations(a2, b2, 3));

    return 0;
}
