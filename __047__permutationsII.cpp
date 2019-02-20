/*
 47. Permutations II
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 Example:
 Input: [1,1,2]
 Output:
 [
 [1,1,2],
 [1,2,1],
 [2,1,1]
 ]
 */
#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int> nums, int begin, vector<vector<int>> &res) {
    if (begin == nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int i = begin; i < nums.size(); ++i) {
        if (i != begin && nums[i] == nums[begin]) continue;
        swap(nums[begin], nums[i]);
        helper(nums, begin + 1, res);
    }
    
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    helper(nums, 0, res);
    return res;
}


void printVector2D(vector<vector<int>> &vector2D){
    if(vector2D.size() == 0) return;
    int ROWS = vector2D.size();
//    cout << "ROWS = " << ROWS << endl;
    for (int row = 0; row < ROWS; row++) {
        int COLUMNS = vector2D[0].size();
//        cout << "COLUMNS = " << COLUMNS << endl;
        for (int col = 0; col < COLUMNS; col++) {
            cout << vector2D[row][col];
            if(col != COLUMNS - 1) cout << ", ";
        }   cout << endl;
    }
}

int main(){
    vector<int> nums = {1,2,2};
    vector<vector<int>> permutations = permuteUnique(nums);
    printVector2D(permutations);
}


