/*
 209. Minimum Size Subarray Sum
 Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 
 Example:
 Input: s = 7, nums = [2,3,1,2,4,3]
 Output: 2
 Explanation: the subarray [4,3] has the minimal length under the problem constraint.
 Follow up:
 If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(vector<int> &nums, int s){
    if(nums.size() == 0)    return 0;
    int minLen = INT_MAX;
    int iLeft = 0, iRight = 0, sum = 0, n = nums.size();
    
    while(iRight < n){
        sum += nums[iRight];
        iRight++;
        while(sum >= s){
            minLen = min(minLen, iRight - iLeft);
            sum -= nums[iLeft];
            iLeft++;
        }
    }
    if(minLen == INT_MAX)
        return 0;
    else
        return minLen;
}


int main(){
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int s = 7;
    cout << "minLen = " << minSubArrayLen(nums, s) << endl;
    return 0;
}
