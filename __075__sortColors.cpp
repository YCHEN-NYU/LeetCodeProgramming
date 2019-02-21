/*
 75. Sort Colors
 Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 
 Note: You are not suppose to use the library's sort function for this problem.
 
 Example:
 
 Input: [2,0,2,1,1,0]
 Output: [0,0,1,1,2,2]
 Follow up:
 
 A rather straight forward solution is a two-pass algorithm using counting sort.
 First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 Could you come up with a one-pass algorithm using only constant space?
 */

#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int zero = 0, two = nums.size() - 1;
    for(int i = 0; i <= two; i++){
        while(nums[i] == 2 && i < two){
            swap(nums[i], nums[two]);
            two--;
        }
        while(nums[i] == 0 && i > zero) {
            swap(nums[i], nums[zero]);
            zero++;
        }
    }
}

// counting sort, count the number of colors, then rewrite the vector



void printVector1D(vector<int> &nums){
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if(i != nums.size() - 1)    cout << ", ";
        else    cout << "]";
    }
}
int main(){
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    printVector1D(nums);
    sortColors(nums);
    cout << " --sort--> ";
    printVector1D(nums);
    cout << endl;
}
