/* Using Recursion */
#include <iostream>
using namespace std;

void decimalToBinary(int n) {
    if (n == 0) return;
    
    decimalToBinary(n / 2); // Recursive call
    cout << (n % 2); // Print remainder (binary digit)
}

int main() {
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;

    if (decimal == 0) {
        cout << "0";
    } else {
        decimalToBinary(decimal);
    }

    cout << endl;
    return 0;
}


/* Without Recursion */
// #include <iostream>
// using namespace std;

// void decimalToBinary(int n) {
//     if (n == 0) {
//         cout << "0";
//         return;
//     }

//     string binary = "";
//     while (n > 0) {
//         binary = (n % 2 == 0 ? "0" : "1") + binary;
//         n /= 2;
//     }

//     cout << "Binary representation: " << binary << endl;
// }

// int main() {
//     int decimal;
//     cout << "Enter a decimal number: ";
//     cin >> decimal;

//     decimalToBinary(decimal);

//     return 0;
// }
