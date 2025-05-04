#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());

    if (str == reversedStr) {
        cout << "\"" << str << "\" is a palindrome.\n";
    } else {
        cout << "\"" << str << "\" is not a palindrome.\n";
    }

    return 0;
}
