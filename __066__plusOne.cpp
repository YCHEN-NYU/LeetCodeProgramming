/*
 66. Plus One
 Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
 You may assume the integer does not contain any leading zero, except the number 0 itself.
 
 Example 1:
 Input: [1,2,3]
 Output: [1,2,4]
 Explanation: The array represents the integer 123.
 
 Example 2:
 Input: [4,3,2,1]
 Output: [4,3,2,2]
 Explanation: The array represents the integer 4321.
 */


#include <iostream>
#include <vector>
using namespace std;


void plusOne(vector<int>& digits) {
    int carry = 1;
    for(int i = digits.size() - 1; i >= 0; i--)
    {
        int sum = digits[i] + carry;
        digits[i] = sum%10;
        carry = sum/10;
    }
    if(carry != 0)  digits.insert(digits.begin(), carry);
}


void printList(vector<int> &nums){
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) {
            cout << ", ";
                }
        else
            cout << endl;
    }
}
int main(){
    vector<vector<int>> numList = {{1, 2, 3}, {9}, {9, 9}, {8, 9, 9}};
    for (int i = 0; i < numList.size(); i++) {
        printList(numList[i]);
        plusOne(numList[i]);
        printList(numList[i]);
    }
}

