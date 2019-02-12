#include <iostream>
#include <vector>
using namespace std;

int searchInserPosition(vector<int> &nums, int target){
    if(nums.size() == 0)    return -1;
    int iLeft = 0, iRight = nums.size() - 1;
    while(iLeft <= iRight){
        int mid = (iLeft + iRight)/2;
        if(target == nums[mid]){
            return mid;
        }
        else{
            if(target < nums[mid])
                iRight = mid - 1;
            else
                iLeft = mid + 1;
        }
    }
    return iLeft;
}


int main(){
    vector<int> nums = {1, 3, 5, 6};
    vector<int> targetList = {5, 2, 7, 0};
    for(auto target : targetList){
        cout << target << "->" << searchInserPosition(nums, target) << endl;
    }
}
