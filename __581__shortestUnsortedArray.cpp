/*
581. Shortest Unsorted Continuous Subarray
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/
#include <iostream>
#include <vector>
#include "printMatrix1D.h"
using namespace std;

// int findUnsortedSubarray(vector<int>& nums) {
// 	vector<int> sortedNums(nums);
//   sort(sortedNums.begin(), sortedNums.end());
//   int i = 0;
//   while(i < nums.size() && sortedNums[i] == nums[i])
//     i++;
  
//   int j = nums.size() - 1;
//   while(j > i && sortedNums[j] == nums[j])
//   	j--;
//   return j - i + 1;
// }

int findUnsortedSubarray(vector<int> &nums){
  int n = nums.size();
  vector<int> rhs(n, INT_MAX), lhs(n, INT_MIN);
  // from right to left, find min so far
  rhs[n - 1] = min(nums[n - 1], rhs[n - 1]);
  for(int i = n - 2; i >= 0; i--){
    rhs[i] = min(nums[i], rhs[i + 1]);
  }

  // from left to right, find max so far
  lhs[0] = max(nums[0], lhs[0]);
  for(int j = 1; j < n; j++){
    lhs[j] = max(nums[j], lhs[j - 1]);
  }

  int i = 0, j = n - 1;
  while(i < n && nums[i] <= rhs[i]) i++;
  // cout << "i = " << i << endl;
  while(j > i && nums[j] >= lhs[j]) j--;
  // cout << "j = " << j << endl;
  return j - i + 1;
}

int main(){
	vector<vector<int>> numsList = {{1, 2, 3, 4}, {1, 3, 2, 4}, {2, 6, 4, 8, 10, 9, 15}, {1, 3, 2, 2, 2}};
  for(auto nums : numsList){
    printMatrix1D(nums);
    cout << "length = " << findUnsortedSubarray(nums) << endl;
  }
	
	return 0;
}


