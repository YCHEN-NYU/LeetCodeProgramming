#include <iostream>
#include <vector>
#include "printMatrix2D.h"
using namespace std;

void helper(vector<int> &nums, int start, vector<int> &tmp, vector<vector<int>> &res){
    res.push_back(tmp);
    
    for(int i = start; i < nums.size(); i++){
        tmp.push_back(nums[i]);
        helper(nums, i + 1, tmp, res);
        tmp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    helper(nums, 0, tmp, res);
    return res;
}

vector<vector<int>> subsetIterative(vector<int> &nums){
    vector<vector<int>> res = {{}};
    
    for (int i = 0; i < nums.size(); i++) {
        int len = res.size();
        for(int j = 0; j < len; j++){
            vector<int> temp = res[j];
            temp.push_back(nums[i]);
            res.push_back(temp);
        }
    }
    return res;
}




int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsets(nums);
    printMatrix2D(res);
}
