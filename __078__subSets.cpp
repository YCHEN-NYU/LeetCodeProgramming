#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int> &nums, vector<int> &tempList, int begin, vector<vector<int>> &res){
    cout << "tempList.size() = " << tempList.size() << endl;
    res.push_back(tempList);
    
    for (int i = begin; i < nums.size(); i++) {
        tempList.push_back(nums[i]);
        // recursive call of the helper function
        helper(nums, tempList, i + 1, res);
        // reset
        tempList.erase(tempList.end() - 1);
    }
}

vector<vector<int>> subSet(vector<int> &nums){
    cout << "nums.size() = " << nums.size() << endl;
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> tempList;
    helper(nums, tempList, 0, res);
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
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsetIterative(nums);
    printVector2D(res);
}
