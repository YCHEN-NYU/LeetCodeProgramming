/*
 9. Palindrome Number
 Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 
 Example 1:
 Input: 121
 Output: true
 
 Example 2:
 Input: -121
 Output: false
 Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 
 Example 3:
 Input: 10
 Output: false
 Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 
 Follow up:
 Coud you solve it without converting the integer to a string?
 */
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0) return false;
    else{
        vector<int> num;
        while(x != 0){
            num.push_back(x%10);
            x /= 10;
        }
        
        for(int i = 0; i < num.size(); i++){
            if(num[i] != num[num.size() - 1 - i])
                return false;
        }
        return true;
    }
}


int main(){
    vector<int> numList = {121, -121, 989, 10};
    for (int i = 0; i < numList.size(); i++) {
        cout << numList[i] << " is palindrome? " << boolalpha << isPalindrome(numList[i]) << endl;
    }
}
