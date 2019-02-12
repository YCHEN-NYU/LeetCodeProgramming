/*
 485. Max Consecutive Ones
 Given a binary array, find the maximum number of consecutive 1s in this array.
 
 Example 1:
 Input: [1,1,0,1,1,1]
 Output: 3
 Explanation: The first two digits or the last three digits are consecutive 1s.
 The maximum number of consecutive 1s is 3.
 */

#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> & nums){
    int maxLen = 0, iLeft = -1;
    
    for (int i = 0; i < nums.size(); i++) {
        if(nums[i] != 1)    iLeft = i;
        maxLen = max(maxLen, i - iLeft);
    }
    return maxLen;
}

void printVec(vector<int> & nums){
    cout << "nums = {";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if(i != nums.size() - 1)    cout << ", ";
    }   cout << "}" << ", ";
}

int main(){
    vector<vector<int>> numsList = {{0}, {1}, {1, 1}, {0, 1}, {0, 0}, {1, 1, 0, 1, 1, 1}};
    for (int i = 0; i < numsList.size(); i++) {
        printVec(numsList[i]);
        cout << "# of max consecutive ones = " << findMaxConsecutiveOnes(numsList[i]) << endl;
    }
    
    return 0;
}
