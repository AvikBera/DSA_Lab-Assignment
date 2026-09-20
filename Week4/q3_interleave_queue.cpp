// Q3: Interleave the first half of the queue with the second half
// Sample I/P: 4 7 11 20 5 9   Sample O/P: 4 20 7 5 11 9
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int> &q) {
    if (q.size() % 2 != 0) {
        cout << "Queue must have an even number of elements to interleave." << endl;
        return;
    }

    stack<int> st;
    int halfSize = q.size() / 2;

    // Step 1: push first half elements into the stack
    for (int i = 0; i < halfSize; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: enqueue back the stack elements (reversed first half goes to back)
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: dequeue first half elements and enqueue them to the back again
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    // Step 4: push first half elements into the stack again
    for (int i = 0; i < halfSize; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 5: interleave elements from stack and queue
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n;

    cout << "Enter number of elements (even number): ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.push(val);
    }

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
