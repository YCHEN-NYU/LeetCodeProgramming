/*
 169. Majority Element
 Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 You may assume that the array is non-empty and the majority element always exist in the array.
 
 Example 1:
 Input: [3,2,3]
 Output: 3
 
 Example 2:
 Input: [2,2,1,1,1,2,2]
 Output: 2
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int> &nums){
    unordered_map<int, int> countMap;
    for (int i = 0; i < nums.size(); i++) {
        if(countMap.find(nums[i]) != countMap.end()){
            if(++countMap[nums[i]] > nums.size()/2)
                return nums[i];
        }
        else
            countMap[nums[i]] = 1;
    }
    return 0;
}

int main(){
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "majority element = " << majorityElement(nums) << endl;
}
