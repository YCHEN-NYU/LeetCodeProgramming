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
    // check from the end to i, find the first num that's smaller than all the numbers in the back, swap
    int maxIndex;
    bool flag = false;
    for(int i = nums.size() - 2; i >= 0; i--){
        int maxIndex = i;
        
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[i] < nums[j]){
                if(j == i + 1)
                    maxIndex = j;
                else
                    maxIndex = (nums[maxIndex] < nums[j]? maxIndex : j);
            }
        }
        
        if(maxIndex != i){
            int temp = nums[i];
            nums[i] = nums[maxIndex];
            nums[maxIndex] = temp;
            sort(nums.begin() + i + 1, nums.end());
            flag = true;
            break;
        }
    }
    if(!flag) sort(nums.begin(), nums.end());
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
