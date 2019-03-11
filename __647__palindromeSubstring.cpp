/*
 647. Palindromic Substrings
 Given a string, your task is to count how many palindromic substrings in this string.
 The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
 
 Example 1:
 Input: "abc"
 Output: 3
 Explanation: Three palindromic strings: "a", "b", "c".
 
 Example 2:
 
 Input: "aaa"
 Output: 6
 Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 */
#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
int countSubstrings(string s) {
    int n = s.size();
    for(int i = 0; i < s.size(); i++){
        extendPalindrome(s, i, i, n);
        extendPalindrome(s, i, i + 1, n);
    }
    return cnt;
}

void extendPalindrome(string s, int iStart, int iEnd, int n){
    while(iStart >= 0 && iEnd < n){
        if(s[iStart] == s[iEnd]){
            cnt++;
            iStart--;
            iEnd++;
        }
        else
            break;
    }
}


int main(){
    
}

