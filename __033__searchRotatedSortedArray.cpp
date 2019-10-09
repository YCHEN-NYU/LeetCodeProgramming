/*
 33. Search in Rotated Sorted Array
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 You may assume no duplicate exists in the array.
 Your algorithm's runtime complexity must be in the order of O(log n).
 
 Example 1:
 Input: nums = [4,5,6,7,0,1,2], target = 0
 Output: 4
 
 Example 2:
 Input: nums = [4,5,6,7,0,1,2], target = 3
 Output: -1
 */
#include <iostream>
#include <vector>
using namespace std;


int search(vector<int>& nums, int target) {
    if(nums.size() == 0)    return -1;
    int minIndex = find_min_index(nums);
    cout << "minIndex = " << minIndex << endl;
    int leftIndex = binary_search(nums, target, 0, minIndex - 1);
    cout << "leftIndex = " << leftIndex << endl;
    int rightIndex = binary_search(nums, target, minIndex, nums.size() - 1);
    cout << "rightIndex = " << rightIndex << endl;
    if(leftIndex != -1) return leftIndex;
    else{
        if(rightIndex != -1)
            return rightIndex;
        else
            return -1;
    }
}

int search(vector<int>& nums, int target) {
    if(nums.size() == 0) return -1;
    
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(target == nums[mid]) return mid;// found nums[mid] == target
        else{
            // left part is sorted
            if(nums[low] <= nums[mid]){
                // if target falls in the left part
                if(target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1; // target falls in the right part
            }
            else{ // right part is sorted
                // if target is in the right part
                if(target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1; // target is in the left part
            }
        }
    }
    return -1;
}

int binary_search(vector<int> &nums, int target, int low, int high){
    while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] == target)
            return mid;
        else{
            if(target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    
    return -1;
}

int main(){
    
}
