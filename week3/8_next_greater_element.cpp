// UCS301 Data Structures - Lab Assignment 3 (Week 3)
// Additional Q3: Next Greater Element (NGE) for every element in the array
// Input:  [1, 3, 2, 4]
// Output: [3, 4, 4, -1]

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, 2, 4};

    vector<int> result = nextGreaterElement(arr);

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
