/*
 81. Search in Rotated Sorted Array II
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 
 You are given a target value to search. If found in the array return true, otherwise return false.
 
 Example 1:
 
 Input: nums = [2,5,6,0,0,1,2], target = 0
 Output: true
 Example 2:
 
 Input: nums = [2,5,6,0,0,1,2], target = 3
 Output: false
 Follow up:
 
 This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
 Would this affect the run-time complexity? How and why?
 */

#include <iostream>
#include <vector>
#include "printMatrix1D.h"
using namespace std;

bool search(vector<int>& nums, int target) {
    int left = 0, right =  nums.size()-1, mid;
    
    while(left<=right)
    {
        mid = (left + right)/2;
        if(nums[mid] == target) return true;
        
        // the only difference from the first one, trickly case, just updat left and right
        if(nums[left] == nums[mid] && nums[right] == nums[mid]){
            left++;
            right--;
        }
        else{
            if(nums[left] <= nums[mid]) // lhs IN-ORDER
            {
                // check if the target is on the lhs
                if(nums[left] <= target && target < nums[mid])
                    right = mid-1;
                else
                    left = mid + 1;
            }
            else    // rhs IN-ORDER
            {
                // check if the target is on the rhs
                if(nums[mid] < target && target <= nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
    }
    return false;
}

int main(){
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 3;
    if(search(nums, target))
        cout << "Target " << target << " is found." << endl;
    else
        cout << "Target " << target << " is NOT found." << endl;
}
