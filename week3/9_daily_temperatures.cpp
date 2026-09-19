// UCS301 Data Structures - Lab Assignment 3 (Week 3)
// Additional Q4: Daily Temperatures
// answer[i] = number of days to wait after day i for a warmer temperature (0 if none)
// Input:  [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
            int idx = st.top();
            st.pop();
            answer[idx] = i - idx;
        }
        st.push(i);
    }

    return answer;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> answer = dailyTemperatures(temperatures);

    cout << "Input:  [";
    for (size_t i = 0; i < temperatures.size(); i++)
        cout << temperatures[i] << (i < temperatures.size() - 1 ? ", " : "");
    cout << "]" << endl;

    cout << "Output: [";
    for (size_t i = 0; i < answer.size(); i++)
        cout << answer[i] << (i < answer.size() - 1 ? ", " : "");
    cout << "]" << endl;

    return 0;
}
