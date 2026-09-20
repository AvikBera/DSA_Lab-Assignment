// Q5: Implement a Stack using (a) Two Queues and (b) One Queue
#include <iostream>
#include <queue>
using namespace std;

// ---------------- (a) Stack using Two Queues ----------------
class StackUsingTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        // push new element to q2, then move all elements of q1 to q2
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2); // q1 now has newest element at front
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << q1.front() << " popped." << endl;
        q1.pop();
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << q1.front() << endl;
    }

    bool empty() {
        return q1.empty();
    }
};

// ---------------- (b) Stack using One Queue ----------------
class StackUsingOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int sizeBefore = q.size();
        q.push(x);
        // rotate the queue to bring the new element to the front
        for (int i = 0; i < sizeBefore; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << q.front() << " popped." << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << q.front() << endl;
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    cout << "===== (a) Stack using Two Queues =====" << endl;
    StackUsingTwoQueues s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.top();   // 30
    s1.pop();   // 30 popped
    s1.top();   // 20
    s1.pop();   // 20 popped
    s1.pop();   // 10 popped

    cout << "\n===== (b) Stack using One Queue =====" << endl;
    StackUsingOneQueue s2;
    s2.push(10);
    s2.push(20);
    s2.push(30);
    s2.top();   // 30
    s2.pop();   // 30 popped
    s2.top();   // 20
    s2.pop();   // 20 popped
    s2.pop();   // 10 popped

    return 0;
}
