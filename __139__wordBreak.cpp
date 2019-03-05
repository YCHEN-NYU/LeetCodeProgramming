/*
 139. Word Break
 Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 
 Note:
 
 The same word in the dictionary may be reused multiple times in the segmentation.
 You may assume the dictionary does not contain duplicate words.
 Example 1:
 
 Input: s = "leetcode", wordDict = ["leet", "code"]
 Output: true
 Explanation: Return true because "leetcode" can be segmented as "leet code".
 Example 2:
 
 Input: s = "applepenapple", wordDict = ["apple", "pen"]
 Output: true
 Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 Note that you are allowed to reuse a dictionary word.
 Example 3:
 
 Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 Output: false
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n + 1, false);
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    dp[0] = true;
    
    for(int i = 1; i < n + 1; i++){
        for(int j = i - 1; j >= 0; j--){
            string word = s.substr(j, i - j);
            if(dp[j]){
                if(dict.find(word) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
            
        }
    }
    return dp[n];
}


int main(){
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    if(wordBreak(s, wordDict))  cout << "True" << endl;
    else    cout << "False" << endl;
}
