#include <iostream>
using namespace std;

// bigger problem = smaller problem
// smallest problem to which we already know the answer = base condition

int sumOfFirstN(int n) {
    if (n == 0) return 0;
    else return n + sumOfFirstN(n-1);
}

int main() {
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int result = sumOfFirstN(n);
    cout<<"Sum of first "<<n<<" natural numbers is "<<result<<endl;

    return 0;
}