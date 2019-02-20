/*
 40. Combination Sum II
 Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 Each number in candidates may only be used once in the combination.
 
 Note:
 All numbers (including target) will be positive integers.
 The solution set must not contain duplicate combinations.
 Example 1:
 Input: candidates = [10,1,2,7,6,1,5], target = 8,
 A solution set is:
 [[1, 7], [1, 2, 5], [2, 6], [1, 1, 6]]
 
 Example 2:
 Input: candidates = [2,5,2,1,2], target = 5,
 A solution set is:
 [[1,2,2],[5]]
 */

#include <iostream>
#include <vector>
using namespace std;


void helper(vector<int> &candidates, int target, int begin, vector<int> tempList, vector<vector<int>> &res){
    if(target == 0){
        res.push_back(tempList);
        return;
    }
    else{
        if(target > 0){
            for (int i = begin; i < candidates.size(); i++) {
                if(i > begin && candidates[i] == candidates[i - 1]) continue;
                tempList.push_back(candidates[i]);
                helper(candidates, target - candidates[i], i + 1, tempList, res);
                tempList.erase(tempList.end() - 1);
            }
        }
        else
            return;
    }
}

vector<vector<int>> combinationSumII(vector<int> &candidates, int target){
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> tempList;
    helper(candidates, target, 0, tempList, res);
    return res;
}


void printVector2D(vector<vector<int>> &vector2D){
    int ROWS = vector2D.size();
    for (int row = 0; row < ROWS; row++) {
        int COLUMNS = vector2D[row].size();
        for (int col = 0; col < COLUMNS; col++) {
            cout << vector2D[row][col];
            if(col != COLUMNS - 1) cout << ", ";
        }   cout << endl;
    }
    return;
}

int main(){
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    vector<vector<int>> res = combinationSumII(candidates, target);
    printVector2D(res);
    
}
