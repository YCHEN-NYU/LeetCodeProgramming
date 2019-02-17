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
