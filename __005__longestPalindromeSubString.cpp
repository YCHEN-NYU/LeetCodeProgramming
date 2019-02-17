/*
 5. Longest Palindromic Substring
 Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 
 Example 1:
 Input: "babad"
 Output: "bab"
 Note: "aba" is also a valid answer.
 Example 2:
 
 Input: "cbbd"
 Output: "bb"
 */
#include <iostream>
#include <vector>
using namespace std;

int leftIndex = 0, rightIndex = 0;

// extend the left index and right index for palindrome substring
void extendPalindrome(string &s, int j, int k){
    // ensure indices are valid, extend towards both directions
    while(j >= 0 && k < s.size() && s[j]==s[k]){
        j--;
        k++;
    }
    // use rightIndex and leftIndex to store the longest positions
    if(k - j - 1 > rightIndex - leftIndex + 1){
        leftIndex = j + 1;
        rightIndex = k - 1;
    }
}


string longestPalindrome(string s) {
    if(s.size() <= 1) return s;
    
    for(int i = 0; i < s.size() - 1; i++){
        extendPalindrome(s, i, i); // odd extend
        extendPalindrome(s, i, i + 1); // even extend
    }
    // return the substring defined by the left and right indices
    return s.substr(leftIndex, rightIndex - leftIndex + 1);
}

int main(){
    vector<string> strList = {"aa", "babad","cbbd"};
    for (int i = 0; i < strList.size(); i++)
        cout << longestPalindrome(strList[i]) << endl;
    
    return 0;
}
