#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if (n==0) return 0;
    else return (n%10) + sumOfDigits(n/10);
}

int main(){
    int n;
    cout<<"Enter a number to calculate the sum of its digits: ";
    cin>>n;
    cout<<"Sum: "<<sumOfDigits(n);

    return 0;
}