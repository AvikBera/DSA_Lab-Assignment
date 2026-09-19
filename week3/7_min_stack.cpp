// UCS301 Data Structures - Lab Assignment 3 (Week 3)
// Additional Q2: Design a stack that supports getMin() in O(1) time
// and O(1) extra space.
// Trick: when pushing a new minimum, store an "encoded" value
// (2*x - oldMin) instead of x, so the old minimum can be recovered on pop.
// Input:  [push(2), push(3), peek(), pop(), getMin(), push(1), getMin()]
// Output: [3, 2, 1]

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<long long> st;
    long long minElement;

public:
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            minElement = x;
        } else if (x < minElement) {
            st.push(2LL * x - minElement); // encoded value
            minElement = x;
        } else {
            st.push(x);
        }
    }

    void pop() {
        if (st.empty()) return;

        long long top = st.top();
        st.pop();

        if (top < minElement) {
            // top was an encoded value; recover the previous minimum
            minElement = 2 * minElement - top;
        }
    }

    int peek() {
        long long top = st.top();
        return (top < minElement) ? (int)minElement : (int)top;
    }

    int getMin() {
        return (int)minElement;
    }
};

int main() {
    MinStack s;

    s.push(2);
    s.push(3);
    cout << "peek(): " << s.peek() << endl;
    s.pop();
    cout << "getMin(): " << s.getMin() << endl;
    s.push(1);
    cout << "getMin(): " << s.getMin() << endl;

    return 0;
}
