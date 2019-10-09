/*
 7. Reverse Integer
 Given a 32-bit signed integer, reverse digits of an integer.
 
 Example 1:
 Input: 123
 Output: 321
 
 Example 2:
 Input: -123
 Output: -321
 
 Example 3:
 Input: 120
 Output: 21
 
 Note:
 Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^{31},  2^{31} − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */

#include <iostream>
#include <vector>
using namespace std;

int reverseInteger(int num){
    long long res = 0; // prevent overflow!
    
    while(num != 0){
        res = res*10 + num%10;
        num /= 10;
    }
    if(res > INT_MAX || res < INT_MIN) // if the reversed integer overflows!
        return 0;
    else
        return res;
}

int main(){
    vector<int> numList = {123, -123, 120};
    for (int i = 0; i < numList.size(); i++) {
        cout << numList[i] << " -> " << reverseInteger(numList[i]) << endl;
    }
    return 0;
}
