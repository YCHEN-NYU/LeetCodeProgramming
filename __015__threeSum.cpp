/*
 15. 3Sum
 Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 
 Note:
 
 The solution set must not contain duplicate triplets.
 
 Example:
 Given array nums = [-1, 0, 1, 2, -1, -4],
 
 A solution set is:
 [
 [-1, 0, 1],
 [-1, -1, 2]
 ]
 */

#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if(nums.size() <= 2)  return res;
    sort(nums.begin(), nums.end());
    
    int i = 0, iLeft, iRight, n = nums.size();
    
    while(i < n){
        iLeft = i + 1;
        iRight = n - 1;
        
        while(iLeft < iRight){
            if(nums[i] + nums[iLeft] + nums[iRight] == 0){
                vector<int> tmp;
                res.push_back({nums[i], nums[iLeft], nums[iRight]});
                iLeft++;
                iRight--;
                while(iLeft < iRight && nums[iLeft] == nums[iLeft - 1]) iLeft++;
                while(iLeft < iRight && nums[iRight] == nums[iRight + 1]) iRight--;
            }
            else{
                if(nums[i] + nums[iLeft] + nums[iRight] < 0){
                    iLeft++;
                    while(iLeft < iRight && nums[iLeft] == nums[iLeft - 1]) iLeft++;
                }
                else{
                    iRight--;
                    while(iLeft < iRight && nums[iRight] == nums[iRight + 1]) iRight--;
                }
            }
        }
        i++;
        while(i < n && nums[i] == nums[i-1])  i++;
    }
    
    return res;
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums);
    for (int row = 0; row < res.size(); row++) {
        for (int col = 0; col < res[row].size(); col++) {
            cout << res[row][col];
            if(col != res[row].size() - 1)  cout << "+";
        }   cout << " = 0" << endl;
    }
    
    return 0;
}
