// UCS301 Data Structures - Lab Assignment 3 (Week 3)
// Additional Q5: Stack Sort Check
// Given array A, array B (initially empty) and stack S (initially empty):
//   a) push front element of A onto S, removing it from A
//   b) pop top of S, append it to end of B, removing it from S
// Determine whether it's possible to move all elements of A to B such that
// B ends up sorted in ascending order.
// This is equivalent to LeetCode 946 "Validate Stack Sequences", where the
// "pushed" order is A itself and the "popped" order is the sorted version of A.
// Input:  [2, 4, 1243, 4, 1342]
// Output: Yes

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool canSortUsingStack(vector<int> A) {
    vector<int> popped = A;
    sort(popped.begin(), popped.end());

    stack<int> S;
    size_t j = 0;

    for (int x : A) {
        S.push(x);
        while (!S.empty() && S.top() == popped[j]) {
            S.pop();
            j++;
        }
    }

    return S.empty();
}

int main() {
    vector<int> A = {2, 4, 1243, 4, 1342};

    cout << "Input: [";
    for (size_t i = 0; i < A.size(); i++)
        cout << A[i] << (i < A.size() - 1 ? ", " : "");
    cout << "]" << endl;

    cout << "Can be sorted using stack: " << (canSortUsingStack(A) ? "Yes" : "No") << endl;

    return 0;
}
