// Additional Q4: Number of Students Unable to Eat Lunch
// Input: students = [1,1,0,0], sandwiches = [0,1,0,1]   Output: 0
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches) {
    queue<int> q;
    for (int s : students) q.push(s);

    int i = 0;              // index into sandwiches stack (top of stack)
    int rotations = 0;      // number of consecutive students who refused the top sandwich

    while (!q.empty() && rotations < (int)q.size()) {
        if (q.front() == sandwiches[i]) {
            q.pop();
            i++;
            rotations = 0;
        } else {
            q.push(q.front());
            q.pop();
            rotations++;
        }
    }

    return q.size();
}

int main() {
    int n;
    cout << "Enter number of students/sandwiches: ";
    cin >> n;

    vector<int> students(n), sandwiches(n);

    cout << "Enter student preferences (0 = square, 1 = circular): ";
    for (int i = 0; i < n; i++) cin >> students[i];

    cout << "Enter sandwich stack order (top to bottom): ";
    for (int i = 0; i < n; i++) cin >> sandwiches[i];

    int result = countStudents(students, sandwiches);
    cout << "Number of students unable to eat: " << result << endl;

    return 0;
}
