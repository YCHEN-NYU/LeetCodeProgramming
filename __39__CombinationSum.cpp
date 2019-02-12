/*
 39. Combination Sum
 Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 The same repeated number may be chosen from candidates unlimited number of times.
 Note: All numbers (including target) will be positive integers.
 The solution set must not contain duplicate combinations.
 
 Example 1:
 Input: candidates = [2,3,6,7], target = 7,
 A solution set is: [[7], [2,2,3]]
 Example 2:
 Input: candidates = [2,3,5], target = 8,
 A solution set is: [[2,2,2,2], [2,3,3], [3,5]]
 */

#include <iostream>
#include <vector>
using namespace std;

// helper function for recursion
void helper(vector<int> &candidates, int begin, int target, vector<int> &tempList, vector<vector<int>> &res){
    if(target > 0){
        // add candidates[i]
        for (int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
            tempList.push_back(candidates[i]);
            helper(candidates, i, target - candidates[i], tempList, res);
            tempList.pop_back();
        }
    }
    else{
        if(target == 0){
            res.push_back(tempList);
            return;
        }
        else
            return;
    }
}

// get the 2D vector results of combination sum
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> tempList;
    helper(candidates, 0, target, tempList, res);
    return res;
}

// print 2D Vector
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

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 8;
    vector<vector<int>> res;
    res = combinationSum(candidates, target);
    printVector2D(res);
    
}
