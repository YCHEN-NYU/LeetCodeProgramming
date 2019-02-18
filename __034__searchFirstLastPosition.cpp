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
    int iLeft = 0, iRight = nums.size() - 1;
    while(iLeft < iRight){
        int mid = (iLeft + iRight)/2;
        if(target < nums[mid]){
            iRight = mid - 1;
        }
        else{
            if(target > nums[mid]){
                iLeft = mid + 1;
            }
            else{
                iRight = mid;
            }
        }
    }
    if(target != nums[iLeft]) return res;
    else res[0] = iLeft;
    
    // search the right part
    iRight = nums.size() - 1;
    while(iLeft < iRight){
        int mid = (iLeft + iRight + 1)/2;
        if(target < nums[mid]){
            iRight = mid - 1;
        }
        else{
            if(target > nums[mid]){
                iLeft = mid + 1;
            }
            else{
                iLeft = mid;
            }
        }
    }
    
    res[1] = iRight;
    return res;
    }
