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

class Solution {
public:
	int lengthOfLongestSubstring(string s){
		unordered_map<char, int> indexMap;
		int maxLen = 0;
		int prevIndex = 0;

		for(int i = 0; i < s.size(); i++){
			// find the nearest repeated index
			if(indexMap.find(s[i]) != indexMap.end())
				prevIndex = max(prevIndex, indexMap[s[i]] + 1);

			indexMap[s[i]] = i;
			maxLen = max(maxLen, i - prevIndex + 1);

		}

		return maxLen;
	}
};


int main() {
	vector<string> strArr = {"abcabcbb", "bbbbb", "pwwkew", "abc", "b", "wke"};
	Solution testCase;


	for(int i = 0; i < strArr.size(); i++){
		cout << strArr[i] << ", ";
		cout << "maxLen = " 
			<< testCase.lengthOfLongestSubstring(strArr[i]) << endl;
	}
	
	return 0;
}


/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char, int> table;
      int maxLen = 0;
      int prevIndex = 0;
      for(int i = 0; i < s.size(); i++){
        // s[i] is in the <char, index> hash map
        if(table.find(s[i]) != table.end())
          prevIndex = max(prevIndex, table[s[i]] + 1);
        
        table[s[i]] = i;
        maxLen = max(maxLen, i - prevIndex + 1);
      }
      return maxLen;
    }
};
*/