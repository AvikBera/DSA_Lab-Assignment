// UCS301 Data Structures - Lab Assignment 3 (Week 3)
// Q2: Given a string, reverse it using a STACK
// Example: "DataStructure" -> "erutcurtSataD"

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str) {
    stack<char> st;

    for (char ch : str)
        st.push(ch);

    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }

    return reversed;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string result = reverseString(str);
    cout << "Reversed string: " << result << endl;

    return 0;
}
