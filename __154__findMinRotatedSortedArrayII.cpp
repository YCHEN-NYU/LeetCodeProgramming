/*
 154. Find Minimum in Rotated Sorted Array II
 Hard
 
 388
 
 124
 
 Favorite
 
 Share
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 
 (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 
 Find the minimum element.
 
 The array may contain duplicates.
 
 Example 1:
 
 Input: [1,3,5]
 Output: 1
 Example 2:
 
 Input: [2,2,2,0,1]
 Output: 0
 Note:
 
 This is a follow up problem to Find Minimum in Rotated Sorted Array.
 Would allow duplicates affect the run-time complexity? How and why?
 */
#include <iostream>
#include <vector>
#include "printMatrix1D.h"
using namespace std;

int findMinII(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    
    while(low < high){
        if(nums[low] <= nums[high])
            return nums[low];
        
        int mid = (low + high)/2;
        if(nums[low] <= nums[mid]){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }
    return nums[low];
}

int main(){
    vector<vector<int>> numList = {{0, 1}, {0, 1, 2}, {3, 1, 2}, {3, 4, 5, 1, 2}};
    for(auto num : numList){
        printMatrix1D(num);
        cout << findMin(num) << endl;
    }
}

