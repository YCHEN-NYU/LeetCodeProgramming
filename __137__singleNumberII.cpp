/*
 137. Single Number II
 Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
 
 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 
 Example 1:
 
 Input: [2,2,3,2]
 Output: 3
 Example 2:
 
 Input: [0,1,0,1,0,1,99]
 Output: 99
 */
#include <iostream>
#include <vector>
#include "printMatrix1D.h"
using namespace std;

int singleNumberII(vector<int> &nums){
    int ones = 0, twos = 0;
    for(int i = 0; i < nums.size(); i++){
        ones = (ones ^ nums[i]) & (~twos);
        twos = (twos ^ nums[i]) & (~ones);
    }
    return ones;
}

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> count;
    for(auto num : nums){
        if(count.find(num) == count.end()){
            count[num] = 1;
        }
        else{
            count[num]++;
        }
    }
    
    for(auto cnt : count){
        if(cnt.second == 1) return cnt.first;
    }
    return 0;
}

int main(){
    vector<vector<int>> numList = {{2, 2, 3, 2}, {0, 1, 0, 1, 0, 1, 99}};
    for(auto num : numList){
        cout << "list = "; printMatrix1D(num);
        cout << "single number = " << singleNumberII(num) << endl;
    }
    
}
