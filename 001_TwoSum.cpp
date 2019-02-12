/* 1. Two Sum
 *  Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *  You may assume that each input would have exactly one solution, and you may not use the same element twice.
 
 *  Example:
 *  Given nums = [2, 7, 11, 15], target = 9,
 *  Because nums[0] + nums[1] = 2 + 7 = 9,
 *  return [0, 1].
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> & nums, int target){
        vector<int> res;
        unordered_map<int, int> table;
        
        for(int i = 0; i < nums.size(); i++){
            if(table.find(nums[i]) == table.end()){
                table[target - nums[i]] = i;
            }
            else {
                res.push_back(table[nums[i]]);
                res.push_back(i);
                return res;
            }
        }
        return res;
    }
};

int main() {
    Solution test;
    vector<int> nums = {-2, 7, 11, 15};
    int target = 18;
    vector<int> res;
    res = test.twoSum(nums, target);
    
    if(!res.empty())
        cout << res[0] << ", " << res[1] << endl;
    else cout << "no solution found for target " << target << endl;
    
    return 0;
}