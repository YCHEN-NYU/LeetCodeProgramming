#include <iostream>
#include <vector>

using namespace std;


int binary_search(vector<int> &nums, int target){
    if(nums.size() == 0) return -1;
    
    int iLeft = 0, iRight = nums.size() - 1;
    int mid;
    while(iLeft <= iRight){
        mid = (iLeft + iRight)/2;
        if(nums[mid] == target){
            return mid;
        }
        else{
            if(target < nums[mid]){
                iRight = mid - 1;
            }
            else{
                iLeft = mid + 1;
            }
        }
    }
    
    return -1;
}


// return the left and right boundary indices of the target in a vector
vector<int> binary_search_non_unique(vector<int> &nums, int target){
    vector<int> res(2, -1);
//    if(nums.size() == 0)    return res;
    
    int iLeft = 0, iRight = nums.size() - 1;
    // find the left index of the target
    while(iLeft < iRight){
        int mid = (iLeft + iRight)/2;
        if(target < nums[mid]){
            iRight = mid - 1;
        }
        else{
            if(target == mid){
                iRight = mid;
            }
            else{
                iLeft = mid + 1;
            }
        }
    }
    if(nums[iLeft] != target)   return res;
    else    res[0] = iLeft;
    
    // find the right index of the target
    // reset the right index and search again, no need to reset the left index
    iRight = nums.size() - 1;
    while(iLeft < iRight){
        int mid = (iLeft + iRight)/2 + 1;
        if(target < nums[mid]){
            iRight = mid - 1;
        }
        else{
            if(target > nums[mid]){
                iLeft = mid + 1;
            }
            else{
                iLeft = mid;
            }
        }
    }
    res[1] = iRight;
    return res;
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
//    cout << "target = " << target << endl;
//    cin >> target;
    
//    int targetIndex = binary_search(nums,target);
//    if(targetIndex == -1)
//        cout << "Target not found" << endl;
//    else
//        cout << "Target index = " << targetIndex << endl;
    
    
    vector<int> res = binary_search_non_unique(nums, target);
    cout << res[0] << ", " << res[1] << endl;
    
    return 0;
}
