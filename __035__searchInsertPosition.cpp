/*
 35. Search Insert Position
 Easy
 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 
 You may assume no duplicates in the array.
 
 Example 1:
 Input: [1,3,5,6], 5
 Output: 2
 
 Example 2:
 Input: [1,3,5,6], 2
 Output: 1
 
 Example 3:
 Input: [1,3,5,6], 7
 Output: 4
 
 Example 4:
 Input: [1,3,5,6], 0
 Output: 0
 */

#include <iostream>
#include <vector>
using namespace std;

int searchInsertPosition(vector<int> &nums, int target){
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(target == nums[mid])
            return mid; // target found, return 
        else{
            if(target < nums[mid])
                high = mid - 1; // search lhs
            else
                low = mid + 1; // search rhs
        }
    }
    return low;
}


int main(){
    vector<int> nums = {1,3,5,6};
    vector<int> targets = {5, 2, 7, 0};
    for (auto target : targets) {
        cout << target << "@" << searchInsertPosition(nums, target) << endl;
    }
    return 0;
}
