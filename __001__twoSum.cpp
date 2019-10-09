/* 1. Two Sum
 *  Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *  You may assume that each input would have exactly one solution, and you may not use the same element twice.
 
 *  Example:
 *  Given nums = [2, 7, 11, 15], target = 9,
 *  Because nums[0] + nums[1] = 2 + 7 = 9,
 *  return [0, 1].
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
    vector<int> res;
    unordered_map<int, int> valIndex;
    
    for(int i = 0; i < nums.size(); i++){
        if(valIndex.find(nums[i]) == valIndex.end()){
            valIndex[target - nums[i]] = i;
        }
        else{
            res.push_back(valIndex[nums[i]]);
            res.push_back(i);
            break;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target;
    cout << "target = ";
    cin >> target;
    vector<int> res = twoSum(nums, target);
    
    if(res.size() == 0)
        cout << "target " << target << " not found." << endl;
    else
        cout << res[0] << ", " << res[1] << endl;
    
}
