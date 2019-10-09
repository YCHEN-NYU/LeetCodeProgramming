/*
 31. Next Permutation
 Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 The replacement must be in-place and use only constant extra memory.
 Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 
 1,2,3 → 1,3,2
 3,2,1 → 1,2,3
 1,1,5 → 1,5,1
 */

#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
    
    int n = nums.size();
    // scan from the back to find the first element nums[i - 1] < nums[i]
    int i = n - 1;
    for(; i > 0; i--){
        if(nums[i - 1] < nums[i]) break;
    }
    
    // find number from index = [i, n - 1] that's bigger than nums[i - 1]
    if(i != 0){
        for(int j = n - 1; j >= i; j--){
            // swap the two number
            if(nums[j] > nums[i - 1]){
                swap(nums[j], nums[i - 1]);
                break;
            }
        }
        
        // sort index = [i, n - 1] by increasing order
        sort(nums.begin() + i, nums.end());
    }
    else
        sort(nums.begin(), nums.end());
}

void printList(vector<int> & nums){
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if(i != nums.size() - 1)    cout << ", ";
    }   cout << "]";
}

int main(){
    vector<vector<int>> numList = {{1, 2, 3}, {3, 2, 1}, {1, 1, 5}};
    for (int i = 0; i < numList.size(); i++) {
        printList(numList[i]); cout << "->";
        nextPermutation(numList[i]);
        printList(numList[i]); cout << endl;
    }
}
