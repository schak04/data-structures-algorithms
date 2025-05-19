#include <iostream>
using namespace std;

int tworaisedtoN(int N) {
    if (N == 0) return 1;
    return 2 * tworaisedtoN(N-1);
}

int AraisedtoB(int a, int b) {
    if (b == 0) return 1;
    return a * AraisedtoB(a, b-1);
}

int main(){
    int n, a, b;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter the value of a and b: ";
    cin>>a>>b;

    int result2n = tworaisedtoN(n);
    int resultAb = AraisedtoB(a, b);
    cout<<"2^n = 2^"<<n<<" = "<<result2n<<endl;
    cout<<"a^b = "<<a<<"^"<<b<<" = "<<resultAb<<endl;
    return 0;
}