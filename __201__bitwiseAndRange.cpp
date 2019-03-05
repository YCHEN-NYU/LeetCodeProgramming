/*
 201. Bitwise AND of Numbers Range
 Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 
 Example 1:
 Input: [5,7]
 Output: 4
 
 Example 2:
 Input: [0,1]
 Output: 0
 */
#include <iostream>
#include <vector>
using namespace std;

int bitwiseAndRange(int m, int n){
    if(m == 0)  return 0;
    
    int shift = 0;
    while(m != n){
        m >>= 1;
        n >>= 1;
        shift++;
    }
    
    return m << shift;
}


int main(){
    int m = 5, n = 7;
    cout << bitwiseAndRange(m, n) << endl;
}
