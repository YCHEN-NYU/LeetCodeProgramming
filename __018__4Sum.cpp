
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if(nums.size() < 4) return res;
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < nums.size() - 3; i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        for(int j = i + 1; j < nums.size() - 2; j++){
            
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;
            int iLeft = j + 1, iRight = nums.size() - 1;
            
            while(iLeft < iRight){
                int sum = nums[i] + nums[j] + nums[iLeft] + nums[iRight];
                
                if(sum == target){
                    vector<int> out {nums[i], nums[j], nums[iLeft], nums[iRight]};
                    res.push_back(out);
                    iLeft++;
                    while(iLeft < iRight && nums[iLeft] == nums[iLeft - 1]) iLeft++;
                    iRight--;
                    while(iLeft < iRight && nums[iRight] == nums[iRight + 1]) iRight++;
                }
                else if(sum < target)  iLeft++;
                else iRight--;
            }
            
        }
    }
    
    return vector<vector<int>> (res.begin(), res.end());
}


int main(){
    
}
