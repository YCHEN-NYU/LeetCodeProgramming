/*
 89. Gray Code
 The gray code is a binary numeral system where two successive values differ in only one bit.
 Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 
 Example 1:
 Input: 2
 Output: [0,1,3,2]
 Explanation:
 00 - 0
 01 - 1
 11 - 3
 10 - 2
 
 For a given n, a gray code sequence may not be uniquely defined.
 For example, [0,2,3,1] is also a valid gray code sequence.
 
 00 - 0
 10 - 2
 11 - 3
 01 - 1
 
 Example 2:
 Input: 0
 Output: [0]
 Explanation: We define the gray code sequence to begin with 0.
 A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
 Therefore, for n = 0 the gray code sequence is [0].

 Say the example input is 3.

0 000
1 001
3 011
2 010

6 110
7 111
5 101
4 100

 */

#include <iostream>
#include <vector>
#include <bitset>
//#include "printMatrix1D.h"
using namespace std;

vector<int> grayCode(int n) {
    vector<int> res;
    res.push_back(0);
    for(int i = 0; i < n; i++){
        int len = res.size();
        for(int k = len - 1; k >= 0; k--){
            res.push_back(res[k] | 1 << i);
        }
    }
    
    return res;
}

void printMatrix1D(vector<int> &nums){
    for (int i = 0; i < nums.size(); i++) {
        cout << bitset<3> (nums[i]) << endl;
    }
}

int main(){
    vector<int> res = grayCode(3);
    printMatrix1D(res);
    return 0;
}
