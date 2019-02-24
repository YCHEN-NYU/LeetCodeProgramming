/*
125. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.
Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

bool isPalindrome(string s) {
    int iLeft = 0, iRight = s.size() - 1;
    while(iLeft < iRight){
        if(!isalnum(s[iLeft])){
            iLeft++;
            continue;
        }
        
        if(!isalnum(s[iRight])){
            iRight--;
            continue;
        }
        
        if(isalnum(s[iLeft]) && isalnum(s[iRight])){
            if(tolower(s[iLeft]) != tolower(s[iRight]))
                return false;
        }
        iLeft++;
        iRight--;
    }
    return true;
}
