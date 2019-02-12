/*
 49. Group Anagrams
 Given an array of strings, group anagrams together.
 Example:
 Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 Output: [["ate","eat","tea"], ["nat","tan"],["bat"]]
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
using namespace std;

bool isAnagrams(string &s1, string &s2){
    if(s1.size() == 0 && s2.size() == 0)    return true;
    if(s1.size() != s2.size())  return false;
    unordered_map<char, int> charCount;
    
    // build a hash map counting the characters in string s1
    for (int i = 0; i < s1.size(); i++) {
        if(charCount.find(s1[i]) == charCount.end())
            charCount[s1[i]] = 1;
        else
            charCount[s1[i]]++;
    }
    
    for (int j = 0; j < s2.size(); j++) {
        if(charCount.find(s2[j]) == charCount.end())
            return false;
        else{
            if(charCount[s2[j]] < 0)
                return false;
            else
                charCount[s2[j]]--;
        }
    }
    return true;
}

vector<vector<string>> groupAnagrams(vector<string> &str){
    unordered_map<string,vector<string>> strVector;
    for (int i = 0; i < str.size(); i++) {
        string s = str[i];
        string temp = s;
        sort(temp.begin(), temp.end());
        strVector[temp].push_back(s);
    }
    
    vector<vector<string>> res;
    for(auto element : strVector)
        res.push_back(element.second);
    return res;
}

void printVector2D(vector<vector<string>> &vector2D){
    int ROWS = vector2D.size();
    for (int row = 0; row < ROWS; row++) {
        int COLUMNS = vector2D[row].size();
        for (int col = 0; col < COLUMNS; col++) {
            cout << vector2D[row][col];
            if(col != COLUMNS - 1)  cout << ", ";
        }   cout << endl;
    }   cout << endl;
    return;
}



int main() {
//    string s1 = "ab", s2 = "ba";
//    cout << boolalpha << isAnagrams(s1, s2) << endl;
    vector<string> strVec = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strVec);
    printVector2D(res);
}
