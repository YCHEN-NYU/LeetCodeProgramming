/*
 153. Find Minimum in Rotated Sorted Array
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 
 (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 
 Find the minimum element.
 
 You may assume no duplicate exists in the array.
 
 Example 1:
 
 Input: [3,4,5,1,2]
 Output: 1
 Example 2:
 
 Input: [4,5,6,7,0,1,2]
 Output: 0
 */
#include <iostream>
#include <vector>
#include "printMatrix1D.h"
using namespace std;

int findMin(vector<int>& nums) {
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
