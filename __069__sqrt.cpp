/*
 Implement int sqrt(int x).
 
 Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 
 Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
 */

#include <iostream>
#include <climits>
using namespace std;

// Integer Newton's method
int mySqrt(int x) {
    long long r = x;
    while (r*r > x)
        r = (r + x/r) / 2;
    return r;
}

int main() {
    for (long long x=0; x<=INT_MAX; ++x) {
        long long r = mySqrt(x);
        if (r<0 || r*r > x || (r+1)*(r+1) <= x)
            cout << "false: " << x << " " << r << endl;
        if (x % 10000000 == 0)
            cout << x << endl;
    }
    cout << "all checked" << endl;
}
