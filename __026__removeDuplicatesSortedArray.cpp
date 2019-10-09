/*
 26. Remove Duplicates from Sorted Array
 Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 Example 1:
 Given nums = [1,1,2],
 Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 
 It doesn't matter what you leave beyond the returned length.
 Example 2:
 
 Given nums = [0,0,1,1,1,2,2,3,3,4],
 
 Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
 
 It doesn't matter what values are set beyond the returned length.
 */
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> & nums){
    int n = nums.size();
    if(n <= 1) return n;
    int index = 0;
    for(int i = 0; i < n; i++){
        if(nums[index] == nums[i])
            continue;
        else
            nums[++index] = nums[i];
    }
    return index + 1;
}

void printList(vector<int> & nums){
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if(i != nums.size() - 1)    cout << ", ";
    }   cout << "]" << endl;
}

int main(){
    vector<vector<int>> numList = {{}, {1}, {1, 1, 2}, {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}};
    for (int i = 0; i < numList.size(); i++) {
        vector<int> nums = removeDuplicates(numList[i]);
        printList(nums);
    }
    return 0;
}
