// Additional Q2: Sort a Queue without using extra space
// Allowed ops: enqueue(), dequeue(), isEmpty()
// Input: 11 5 4 21   Output: 4 5 11 21
//
// Idea (selection-sort style, done purely with enqueue/dequeue):
// On each pass, the queue holds `windowSize` still-unsorted "candidate"
// elements at the front, followed by a growing, already-sorted tail at the
// rear. Each pass makes two full trips around the queue:
//   Phase A - find the minimum among the candidates (every element,
//             candidate or tail, is dequeued and immediately re-enqueued,
//             so the queue ends the phase completely unchanged).
//   Phase B - repeat the trip, this time dropping the single occurrence of
//             that minimum instead of re-enqueueing it, then push it onto
//             the back, extending the sorted tail by one and shrinking the
//             candidate window by one.
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

void sortQueue(queue<int> &q) {
    int n = q.size();

    for (int pass = 0; pass < n; pass++) {
        int windowSize = n - pass; // number of unsorted candidates left at the front

        // Phase A: locate the minimum among the candidates without disturbing order.
        int minVal = INT_MAX;
        for (int i = 0; i < n; i++) {
            int val = q.front();
            q.pop();
            if (i < windowSize) minVal = min(minVal, val);
            q.push(val);
        }

        // Phase B: remove exactly one occurrence of that minimum from the candidates.
        bool removed = false;
        for (int i = 0; i < n; i++) {
            int val = q.front();
            q.pop();
            if (!removed && i < windowSize && val == minVal) {
                removed = true; // drop it - do not re-enqueue
                continue;
            }
            q.push(val);
        }

        // Extend the sorted tail with the minimum just found.
        q.push(minVal);
    }
}

int main() {
    queue<int> q;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.push(val);
    }

    sortQueue(q);

    cout << "Sorted queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
