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


/* Divide and Conquer
The Divide-and-Conquer algorithm breaks nums into two halves and find the maximum subarray sum in them recursively. Well, the most tricky part is to handle the case that the maximum subarray spans the two halves. For this case, we use a linear algorithm: starting from the middle element and move to both ends (left and right ends), record the maximum sum we have seen. In this case, the maximum sum is finally equal to the middle element plus the maximum sum of moving leftwards and the maximum sum of moving rightwards.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
private:
    int maxSubArray(vector<int>& nums, int l, int r) {
        if (l > r) {
            return INT_MIN;
        }
        int m = l + (r - l) / 2, ml = 0, mr = 0;
        int lmax = maxSubArray(nums, l, m - 1);
        int rmax = maxSubArray(nums, m + 1, r);
        for (int i = m - 1, sum = 0; i >= l; i--) {
            sum += nums[i];
            ml = max(sum, ml);
        }
        for (int i = m + 1, sum = 0; i <= r; i++) {
            sum += nums[i];
            mr = max(sum, mr);
        }
        return max(max(lmax, rmax), ml + mr + nums[m]);
    }
};


int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
    return 0;
}
