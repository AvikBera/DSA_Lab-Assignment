// UCS301 Data Structures - Lab Assignment 3 (Week 3)
// Q4: Convert an Infix expression into a Postfix expression using a stack

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

bool isRightAssociative(char op) {
    return op == '^';
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char ch : infix) {
        if (isspace(ch)) continue;

        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        } else {
            while (!st.empty() && st.top() != '(' &&
                   (precedence(st.top()) > precedence(ch) ||
                    (precedence(st.top()) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
