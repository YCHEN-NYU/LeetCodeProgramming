/*
 Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 Note: The solution set must not contain duplicate subsets.
 */

#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int> &nums, vector<int> &temp, int begin, vector<vector<int>> &res){
    res.push_back(temp);
    
    for(int i = begin; i < nums.size(); i++){
        if(i > begin && nums[i] == nums[i-1]) continue;
        temp.push_back(nums[i]);
        helper(nums, temp, i+1, res);
        temp.erase(temp.end() - 1);
    }
}

vector<vector<int>> subsetsII(vector<int> &nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> temp;
    helper(nums, temp, 0, res);
    return res;
}

vector<vector<int>> subsetsII_Iterative(vector<int> &nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> res = {{}};
    int begin = 0, len = 0;
    for (int i = 0; i < nums.size(); i++) {
        if(i > 0 && nums[i] == nums[i - 1])
            begin = len;
        else
            begin = 0;
        
        len = res.size();
        for (int j = begin; j < len; j++) {
            vector<int> temp = res[j];
            temp.push_back(nums[i]);
            res.push_back(temp);
        }
    }
    
    return res;
}

void printVector2D(vector<vector<int>> &vector2D){
    int ROWS = vector2D.size();
    cout << "size of subset = " << ROWS << endl;
    cout << "Output = " << "[";
    for (int row = 0; row < ROWS; row++) {
        int COLUMNS = vector2D[row].size();
        cout << "[";
        for (int col = 0; col < COLUMNS; col++) {
            cout << vector2D[row][col];
            if(col != COLUMNS - 1) cout << ",";
        }
        if(row != ROWS - 1) cout << "], ";
    }   cout << "]" << endl;
}

int main(){
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> res = subsetsII_Iterative(nums);
    printVector2D(res);
    return 0;
}


/*
 nums = [1, 2, 2]
 
 res = [[]]
 [[]]
 [[], [1]]
 
 
 */
