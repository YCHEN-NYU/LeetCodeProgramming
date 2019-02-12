#include <iostream>
#include <string>
#include <vector>
using namespace std;

// helper function using backtracking for generate permutation of number lists
void helper(vector<int> &nums, int begin, vector<vector<int>> &res){
    if(begin >= nums.size()){
        res.push_back(nums);
        return;
    }
    
    for(int i = begin; i < nums.size(); i++){
        cout << "i = " << i << endl;
        swap(nums[begin], nums[i]); // twist
        helper(nums, begin + 1, res); // recursive call of helper
        swap(nums[begin], nums[i]); // reset
    }
}

// return the permutation of vector (all unique characters)
vector<vector<int>> permutate(vector<int> &nums){
    vector<vector<int>> res;
    helper(nums, 0, res);
    return res;
}

void print2DVector(vector<vector<int>> &vector2D){
    int ROWS = vector2D.size(), COLUMNS = vector2D[0].size();
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            cout << vector2D[row][col];
            if(col < COLUMNS - 1)  cout << ", ";
        }   cout << endl;
    }   cout << endl;
}

int main(){
    vector<int> nums = {1, 2};
    vector<vector<int>> res = permutate(nums);
    print2DVector(res);
    return 0;
}
