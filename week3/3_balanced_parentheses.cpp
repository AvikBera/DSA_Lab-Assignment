// UCS301 Data Structures - Lab Assignment 3 (Week 3)
// Q3: Check if an expression has balanced parentheses using a stack

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string expr) {
    stack<char> st;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty())
                return false;

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
        }
    }

    return st.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (isBalanced(expr))
        cout << "The expression has balanced parentheses." << endl;
    else
        cout << "The expression does NOT have balanced parentheses." << endl;

    return 0;
}
