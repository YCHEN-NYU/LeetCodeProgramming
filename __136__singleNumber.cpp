/*
 136. Single Number
 Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 
 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 
 Example 1:
 
 Input: [2,2,1]
 Output: 1
 Example 2:
 
 Input: [4,1,2,1,2]
 Output: 4
 */

#include <iostream>
#include <vector>
#include "printMatrix1D.h"
using namespace std;

int singleNumber(vector<int> &nums){
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        res ^= nums[i];
    }
    return res;
}

int main(){
    vector<vector<int>> numList = {{-1}, {0}, {1}, {2, 2, 1}, {4, 1, 2, 1, 2}};
    for(auto num : numList){
        cout << "list = "; printMatrix1D(num);
        cout << "single number = " << singleNumber(num) << endl;
    }
        
}
