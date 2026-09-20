// Additional Q3: Check if a Queue can be sorted into another Queue using a Stack
// Input: Queue = {5, 1, 2, 3, 4}   Output: Yes
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSorted(int n, queue<int> q) {
    stack<int> st;
    int expected = 1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        if (front == expected) {
            expected++;
        } else {
            if (!st.empty() && st.top() < front) {
                // can't place front on stack without breaking order
                return false;
            }
            st.push(front);
        }

        // pop elements from stack while they match expected order
        while (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }
    }

    return (st.empty() && expected == n + 1);
}

int main() {
    int n;
    cout << "Enter number of elements (natural numbers 1 to n in random order): ";
    cin >> n;

    queue<int> q;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.push(val);
    }

    if (checkSorted(n, q))
        cout << "Yes, the queue can be sorted using a stack." << endl;
    else
        cout << "No, the queue cannot be sorted using a stack." << endl;

    return 0;
}
