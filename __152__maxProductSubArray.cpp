/*
 152. Maximum Product Subarray
 Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
 
 Example 1:
 
 Input: [2,3,-2,4]
 Output: 6
 Explanation: [2,3] has the largest product 6.
 Example 2:
 
 Input: [-2,0,-1]
 Output: 0
 Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */
#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int frontProduct = 1, backProduct = 1;
    int ans = INT_MIN;
    
    for(int i = 0; i < nums.size(); i++){
        frontProduct *= nums[i];
        backProduct *= nums[nums.size() - i - 1];
        ans = max(ans, max(frontProduct, backProduct));
        frontProduct = (frontProduct == 0? 1 : frontProduct);
        backProduct = (backProduct == 0? 1 : backProduct);
    }
    return ans;
}

int main(){
    vector<int> nums = {2,3,-2,4};
    cout << "max product = " << maxProduct(nums) << endl;
}

/*
 inline int maximum(const int& a,const int& b,const int& c) {
 return a>b?(a>c?a:c):(b>c?b:c);
 }
 
 inline int minimum(const int& a,const int& b,const int& c) {
 return a<b?(a<c?a:c):(b<c?b:c);
 }
 int maxProduct(vector<int>& nums) {
 //Making two dp arrays to store the maximum postive product and minimum negative product at each point
 int size = nums.size();
 int pos[size],neg[size];
 
 //Initialize to first term
 pos[0] = nums[0];
 neg[0] = nums[0];
 int ans = nums[0];
 
 //The positive array tries toget the max product while the negative array tries to get the least
 for(int i=1; i<size; i++)
 {
 pos[i] = maximum(nums[i], pos[i-1]*nums[i],neg[i-1]*nums[i]);
 neg[i] = minimum(nums[i], pos[i-1]*nums[i],neg[i-1]*nums[i]);
 
 ans = max(ans, pos[i]);
 }
 
 return ans;
 }
 };
 */
