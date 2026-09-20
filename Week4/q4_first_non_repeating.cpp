// Q4: First non-repeating character in a string using Queue
// Sample I/P: a a b c   Sample O/P: a -1 b b
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

void firstNonRepeating(const vector<char> &stream) {
    queue<char> q;
    int count[256] = {0};

    for (char ch : stream) {
        count[(unsigned char)ch]++;
        q.push(ch);

        // remove characters from front that are now repeating
        while (!q.empty() && count[(unsigned char)q.front()] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter the character stream (space separated, e.g. a a b c): ";
    string line;
    getline(cin, line);

    stringstream ss(line);
    string token;
    vector<char> stream;
    while (ss >> token) {
        stream.push_back(token[0]);
    }

    cout << "Output: ";
    firstNonRepeating(stream);

    return 0;
}
