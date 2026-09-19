// (c) Delete All Vowels from a String
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    string result = "";

    for (int i = 0; i < str.length(); i++) {

        if (str[i] != 'a' &&
            str[i] != 'e' &&
            str[i] != 'i' &&
            str[i] != 'o' &&
            str[i] != 'u' &&
            str[i] != 'A' &&
            str[i] != 'E' &&
            str[i] != 'I' &&
            str[i] != 'O' &&
            str[i] != 'U') {

            result = result + str[i];
        }
    }

    cout << "String after deleting vowels = " << result;

    return 0;
}