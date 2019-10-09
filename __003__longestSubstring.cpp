/*
 3. Longest Substring Without Repeating Characters
 Given a string, find the length of the longest substring without repeating characters.
 
 Example 1:
 Input: "abcabcbb"
 Output: 3
 Explanation: The answer is "abc", with the length of 3.
 
 Example 2:
 Input: "bbbbb"
 Output: 1
 Explanation: The answer is "b", with the length of 1.
 
 Example 3:
 Input: "pwwkew"
 Output: 3
 Explanation: The answer is "wke", with the length of 3.
 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s){
    if(s.size() == 0) return 0;
    int rightMostIndex = 0, maxLen = 0;
    unordered_map<char, int> charMap;
    
    for(int i = 0; i < s.size(); i++){
        // renew the rightmost non-repetitive position index
        if(charMap.find(s[i]) != charMap.end())
            rightMostIndex = max(rightMostIndex, charMap[s[i]] + 1);
        
        // renew hash table
        charMap[s[i]] = i;
        
        // calculate the current length and compare with previous maxLen
        maxLen = max(maxLen, i - rightMostIndex + 1);
    }
    return maxLen;
}


int main(){
    vector<string> strList = {"abcabcbb", "bbbbb", "pwwkew"};
    for(int i = 0; i < strList.size(); i++)
        cout << lengthOfLongestSubstring(strList[i]) << endl;
    return 0;
}
