/*
 34. Find First and Last Position of Element in Sorted Array
 Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 Your algorithm's runtime complexity must be in the order of O(log n).
 If the target is not found in the array, return [-1, -1].
 
 Example 1:
 Input: nums = [5,7,7,8,8,10], target = 8
 Output: [3,4]
 
 Example 2:
 Input: nums = [5,7,7,8,8,10], target = 6
 Output: [-1,-1]
 */

vector<int> searchRange(vector<int>& nums, int target) {
    
    vector<int> res(2, -1);
    if(nums.size() == 0) return res;
    
    // search the left part
    int low = 0, high = nums.size() - 1;
    while(low < high){
        int mid = low + (high - low)/2;
        
        if(target < nums[mid])
            high = mid - 1; // search left part [low, mid - 1]
        else{
            if(target > nums[mid])
                low = mid + 1; // search right part: [mid + 1, high]
            else
                high = mid; // search right part with the mid element: [mid, high]
        }
    }
    
    if(target != nums[low])
        return res; // nothing found
    else
        res[0] = low;
    
    // search the right part
    high = nums.size() - 1;
    while(low < high){
        int mid = low + (high - low + 1)/2;
        if(target < nums[mid])
            high = mid - 1;
        else{
            if(target > nums[mid])
                low = mid + 1; // search right part [mid + 1, high]
            else
                low = mid; // search right part with mid element [mid, high]
        }
    }
    
    res[1] = iRight;
    return res;
    }
