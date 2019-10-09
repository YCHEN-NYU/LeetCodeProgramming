/*
 16. 3Sum Closest
 Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 
 Example:
 Given array nums = [-1, 2, 1, -4], and target = 1.
 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
#include <iostream>
#include <vector>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int res = nums[0] + nums[1] + nums[nums.size() - 1];
    for(int i = 0; i < nums.size(); i++){
        int iLeft = i + 1, iRight = nums.size() - 1;
        
        while(iLeft < iRight){
            int sum = nums[i] + nums[iLeft] + nums[iRight];
            
            if(sum > target)
                iRight--;
            else
                iLeft++;
            
            if(abs(sum - target) < abs(res - target))
                res = sum;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << threeSumClosest(nums, target) << endl;
}
