/*
 53. Maximum Subarray
 Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 
 Example:
  Input: [-2,1,-3,4,-1,2,1,-5,4],
 Output: 6
 Explanation: [4,-1,2,1] has the largest sum = 6.
 */
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    if(nums.size() == 0)    return 0;
    if(nums.size() == 1)    return nums[0];
    int res = nums[0], sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        cout << "sum = " << sum << endl;
        res = max(res, sum);
        sum = max(sum, 0);// add sum?
    }
    return res;
}


int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
    return 0;
}
