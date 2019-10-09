/*
18. 4Sum
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) return res;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            //skip duplicate for the first number
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n; j++){
                // skip duplicate for the second number 
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                // use two pointers iLeft, iRight
                int iLeft = j + 1, iRight = n - 1;
                // check validity of the two pointers
                while(iLeft < iRight){
                    // sum up all elements nums[i], nums[j], nums[iLeft], nums[iRight]
                    int sum = nums[i] + nums[j] + nums[iLeft] + nums[iRight];
                    
                    if(sum == target){
                        res.push_back(vector<int>({nums[i], nums[j], nums[iLeft], nums[iRight]}));
                        // skip duplicate for iLeft
                        iLeft++;
                        while(iLeft < iRight && nums[iLeft] == nums[iLeft - 1]) iLeft++;
                        // skip duplicate for iRight
                        iRight--;
                        while(iLeft < iRight && nums[iRight] == nums[iRight + 1]) iRight--;
                    }
                    else{
                        if(sum < target){
                            // move iLeft pointer, skip duplicate
                            iLeft++;
                            while(iLeft < iRight && nums[iLeft] == nums[iLeft - 1]) iLeft++;
                        }
                        else{
                            // sum > target, move iRight pointer, skip duplicate
                            iRight--;
                            while(iLeft < iRight && nums[iRight] == nums[iRight + 1]) iRight--;
                        }
                    }
                }
            }
        }
        
        return res;
    }

// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     vector<vector<int>> res;
//     if(nums.size() < 4) return res;
    
//     sort(nums.begin(), nums.end());
    
//     for(int i = 0; i < nums.size() - 3; i++){
//         if(i > 0 && nums[i] == nums[i - 1]) continue;
//         for(int j = i + 1; j < nums.size() - 2; j++){
            
//             if(j > i + 1 && nums[j] == nums[j - 1]) continue;
//             int iLeft = j + 1, iRight = nums.size() - 1;
            
//             while(iLeft < iRight){
//                 int sum = nums[i] + nums[j] + nums[iLeft] + nums[iRight];
                
//                 if(sum == target){
//                     vector<int> out {nums[i], nums[j], nums[iLeft], nums[iRight]};
//                     res.push_back(out);
//                     iLeft++;
//                     while(iLeft < iRight && nums[iLeft] == nums[iLeft - 1]) iLeft++;
//                     iRight--;
//                     while(iLeft < iRight && nums[iRight] == nums[iRight + 1]) iRight++;
//                 }
//                 else if(sum < target)  iLeft++;
//                 else iRight--;
//             }
            
//         }
//     }
    
//     return vector<vector<int>> (res.begin(), res.end());
// }

int main(){
    
}
