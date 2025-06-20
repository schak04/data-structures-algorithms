// Recursion types:
//   1. head recursion
//   2. tail recursion

#include <iostream>
using namespace std;

// recursion works on LIFO

void seriesN(int n) {
    if (n > 5) return;
    cout<<n<<" ";
    seriesN(n+1);
}

int main(){
    int n = 1;
    seriesN(n);
    return 0;
}