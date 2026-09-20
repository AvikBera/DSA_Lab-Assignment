// Additional Q1: Generate binary numbers from 1 to n using a Queue
// Input: n = 2   Output: 1, 10
#include <iostream>
#include <queue>
using namespace std;

void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1");

    for (int i = 1; i <= n; i++) {
        string curr = q.front();
        q.pop();

        cout << curr;
        if (i != n) cout << ", ";

        q.push(curr + "0");
        q.push(curr + "1");
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Binary numbers from 1 to " << n << ": ";
    generateBinaryNumbers(n);

    return 0;
}
