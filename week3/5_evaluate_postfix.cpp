// UCS301 Data Structures - Lab Assignment 3 (Week 3)
// Q5: Evaluate a Postfix expression using a stack
// Note: assumes single-digit operands (space-separated input also works)

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char ch : postfix) {
        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression (single-digit operands): ";
    getline(cin, postfix);

    cout << "Result: " << evaluatePostfix(postfix) << endl;

    return 0;
}
