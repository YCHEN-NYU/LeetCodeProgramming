/*
 80. Remove Duplicates from Sorted Array II
 Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
 
 Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 
 Example 1:
 Given nums = [1,1,1,2,2,3],
 
 Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
 
 It doesn't matter what you leave beyond the returned length.
 Example 2:
 
 Given nums = [0,0,1,1,1,1,2,3,3],
 
 Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
 
 It doesn't matter what values are set beyond the returned length.
 */


#include <iostream>
#include <vector>
#include "printMatrix1D.h"
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int cnt = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i - 1] == nums[i]){
            cnt++;
            if(cnt > 2){
                nums.erase(nums.begin() + i);
                i--;
                cnt--;
            }
            else{
                continue;
            }
        }
        else{
            cnt = 1;
            continue;
        }
    }
    
    return nums.size();
}

int main(){
    vector<vector<int>> numList = {{1, 1, 1, 2, 2, 3}, {0, 0, 1, 1, 1, 1, 2, 3, 3}};
    for (auto num : numList) {
        printMatrix1D(num);
        removeDuplicates(num);
        printMatrix1D(num);
    }
}
