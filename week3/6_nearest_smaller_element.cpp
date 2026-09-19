// UCS301 Data Structures - Lab Assignment 3 (Week 3)
// Additional Q1: Nearest Smaller Element
// For every A[i], find the nearest smaller element with index < i.
// Input:  [4, 5, 2, 10, 8]
// Output: [-1, 4, -1, 2, 2]

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= arr[i])
            st.pop();

        result[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> result = nearestSmallerElement(arr);

    cout << "Input:  [";
    for (size_t i = 0; i < arr.size(); i++)
        cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    cout << "]" << endl;

    cout << "Output: [";
    for (size_t i = 0; i < result.size(); i++)
        cout << result[i] << (i < result.size() - 1 ? ", " : "");
    cout << "]" << endl;

    return 0;
}
