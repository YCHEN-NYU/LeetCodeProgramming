/*
 14. Longest Common Prefix
 Write a function to find the longest common prefix string amongst an array of strings.
 If there is no common prefix, return an empty string "".
 
 Example 1:
 Input: ["flower","flow","flight"]
 Output: "fl"
 
 Example 2:
 Input: ["dog","racecar","car"]
 Output: ""
 Explanation: There is no common prefix among the input strings.
 Note:
 
 All given inputs are in lowercase letters a-z.
 */

#include <iostream>
#include <vector>
using namespace std;

string commonPrefix(string s1, string s2){
    string result = "";
    int i = 0;
    while(i < s1.size() && i < s2.size()){
        if(s1[i] == s2[i]){
            result = result + s1[i];
            i++;
        }
        else
            break;
    }
    return result;
}

string longestCommonPrefix(vector<string>& strs) {
    
    string res;
    for(int i = 0; i < strs.size(); i++){
        if(i == 0) res = strs[0];
        res = commonPrefix(res, strs[i]);
        if(res == "") break;
    }
    return res;
}


/*
 string longestCommonPrefix(vector<string>& strs) {
     string prefix = "";
     for(int idx=0; strs.size()>0; prefix+=strs[0][idx], idx++)
     for(int i=0; i<strs.size(); i++)
     if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[i-1][idx]))
     return prefix;
     return prefix;
 }
 */

int main(){
    vector<vector<string>> strList = {{"flower","flow","flight"}, {"dog","racecar","car"}, {"aa", "a"}};
    for (auto str : strList) {
        cout << longestCommonPrefix(str) << endl;
    }
    
}
