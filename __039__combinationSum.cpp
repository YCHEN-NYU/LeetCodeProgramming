/*
 39. Combination Sum
 Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 The same repeated number may be chosen from candidates unlimited number of times.
 
 Note:
 All numbers (including target) will be positive integers.
 The solution set must not contain duplicate combinations.
 
 Example 1:
 Input: candidates = [2,3,6,7], target = 7,
 A solution set is:
 [
 [7],
 [2,2,3]
 ]
 
 Example 2:
 Input: candidates = [2,3,5], target = 8,
 A solution set is:
 [
 [2,2,2,2],
 [2,3,3],
 [3,5]
 ]
 */

#include <iostream>
#include <vector>
using namespace std;

// depth-first search method to find all the combination sum, store then in the 2D vector
void helper(vector<int> &candidates, int target, int start, vector<int> &tmp, vector<vector<int>> &res){
    if(target == 0){
        res.push_back(tmp);
        return;
    }
    else{
        if(target > 0){
            for(int i = start; i < candidates.size(); i++){
                if(target >= candidates[i]){
                    tmp.push_back(candidates[i]);
                    helper(candidates, target - candidates[i], i, tmp, res);
                    tmp.pop_back();
                }
            }
        }
    }
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> tmp;
    helper(candidates, target, 0, tmp, res);
    return res;
}


void printVector2D(vector<vector<int>> &Vector2D){
    int ROWS = Vector2D.size(), COLUMNS = Vector2D[0].size();
    cout << "[" << endl;
    for (int row = 0; row < ROWS; row++) {
        cout << "[";
        for (int col = 0; col < Vector2D[row].size(); col++) {
            cout << Vector2D[row][col];
            if(col != Vector2D[row].size() - 1)
                cout << ", ";
            else
                cout << "], " << endl;
        }
    }   cout << "]" << endl;
}

int main(){
    vector<vector<int>> numsList = {{2, 3, 6, 7}, {2, 3, 5}};
    int target = 8;
    for (auto nums : numsList) {
        cout << "target = " << target << endl;
        vector<vector<int>> res = combinationSum(nums, target);
        printVector2D(res);
        cout << endl;
    }
}
