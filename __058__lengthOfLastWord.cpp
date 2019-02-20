/*
 58. Length of Last Word
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 
 If the last word does not exist, return 0.
 
 Note: A word is defined as a character sequence consists of non-space characters only.
 
 Example:
 
 Input: "Hello World"
 Output: 5
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    int len = 0;
    int iLeft = 0, iRight = s.size() - 1;
    // from the back, look for the first non-space character
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] != ' ') {
            iRight = i;
            break;
        }
    }
    
    for(int j = iRight; j >= 0; j--){
        // look for space character
        if(s[j] == ' ') {
            iLeft = j;
            len = iRight - iLeft;
            break;
        }
        // len++, but keep looking for space character
        else {
            len++;
        }
    }
    
    return len;
}

int main(){
    
}
