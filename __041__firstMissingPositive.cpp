/*
 41. First Missing Positive
 Given an unsorted integer array, find the smallest missing positive integer.
 
 Example 1:
  Input: [1,2,0]
 Output: 3
 
 Example 2:
 Input: [3,4,-1,1]
 Output: 2
 
 Example 3:
 Input: [7,8,9,11,12]
 Output: 1
 
 Note: Your algorithm should run in O(n) time and uses constant extra space.
 */

#include <iostream>
#include <vector>
using namespace std;
/*
 Put each number in its right place.
 For example:
 When we find 5, then swap it with A[4].
 At last, the first place where its number is not right, return the place + 1.
 */
int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        // swap until it's in the right position
        while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            swap(nums[i], nums[nums[i] - 1]);
    }
    
    for (int j = 0; j < n; j++) {
        if(nums[j] != j + 1)
            return j + 1;
    }
    
    return n + 1;
}

void printVector1D(vector<int> &vector1D){
    cout << "[";
    for (int i = 0; i < vector1D.size(); i++) {
        cout << vector1D[i];
        if(i != vector1D.size() - 1)    cout << ", ";
    }   cout << "]" << endl;
}

int main(){
    vector<vector<int>> numList = {{1, 2, 0}, {3, 4, -1, 1}, {7, 8, 9, 11, 12}};
    for (auto nums : numList) {
        printVector1D(nums);
        int ans = firstMissingPositive(nums);
        cout << ans << endl;
    }
}
