/*
 46. Permutations
 Given a collection of distinct integers, return all possible permutations.
 Example:
 
 Input: [1,2,3]
 Output:
 [
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
 ] */

#include <iostream>
#include <vector>
using namespace std;

// Recursive Method
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    dfs(nums, tmp, res);
    return res;
}

void dfs(vector<int> &nums, vector<int> &tmp, vector<vector<int>> &res){
    // if tmp.size() equals the length of nums, append tmp to res, return;
    if(tmp.size() == nums.size()){
        res.push_back(tmp);
        return;
    }
    
    // recursively add elements from nums to tmp, skip if nums[i] exists in tmp
    for(int i = 0; i < nums.size(); i++){
        // nums[i] is in tmp, skip
        // cout << "nums[i] = " << nums[i] << endl;
        vector<int>::iterator it = find(tmp.begin(), tmp.end(), nums[i]);
        if(it != tmp.end()) continue;
        else{
            tmp.push_back(nums[i]);
            dfs(nums, tmp, res);
            tmp.pop_back(); // reset
        }
        
    }
}

/* // Iterative method
vector<vector<int>> permute(vector<int> &nums){
    //sort(nums.begin(), nums.end());
    vector<vector<int>> subsets = {};
    subsets.push_back(vector<int> ({nums[0]}));
    
    for(int i = 1; i < nums.size(); i++){
        vector<vector<int>> tempSubsets = {};
        
        for(int insertPos = 0; insertPos <= i; insertPos++){
            
            for(int setIndex = 0; setIndex < subsets.size(); setIndex++){
                vector<int> tempList = subsets[setIndex];
                tempList.insert(tempList.begin() + insertPos, nums[i]);
                tempSubsets.push_back(tempList);
            }
        }
        subsets = tempSubsets;
    }
    
    return subsets;
}

*/


// Recursive Method
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    helper(nums, 0, res);
    return res;
}

void helper(vector<int> &nums, int startIndex, vector<vector<int>> &res){
    if(startIndex >= nums.size()){
        res.push_back(nums);
        return ;
    }
    
    for(int i = startIndex; i < nums.size(); i++){
        swap(nums[startIndex], nums[i]);
        helper(nums, startIndex + 1, res);
        swap(nums[startIndex], nums[i]);
    }
}

void print2DVector(vector<vector<int>> &vector2D){
    int ROWS = vector2D.size();
    cout << "size of permutation = " << ROWS << endl;
    for (int row = 0; row < ROWS; row++) {
        int COLUMNS = vector2D[row].size();
        for (int col = 0; col < COLUMNS; col++) {
            cout << vector2D[row][col];
            if(col < COLUMNS - 1)  cout << ", ";
        }   cout << endl;
    }   cout << endl;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> res = permute(nums);
    print2DVector(res);
    return 0;
}




