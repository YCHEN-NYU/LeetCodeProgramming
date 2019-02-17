/*
 17. Letter Combinations of a Phone Number
 Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
  A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 Example:
 Input: "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Note:
 
 Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

#include <iostream>
#include <vector>
using namespace std;

vector<string> letterCombinations(string digits) {
    vector<string> res;
    res.push_back("");
    vector<string> keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    for(int i = 0; i < digits.size(); i++){
        if(digits[i] < '0' || digits[i] > '9')  break;
        
        vector<string> tmp;
        string key = keys[digits[i] - '0'];
        for(int j = 0; j < res.size(); j++)
            for(int k = 0; k < key.size(); k++)
                tmp.push_back(res[j] + key[k]);
        
        res = tmp;
    }
    return res;
}

int main(){
    vector<string> strList = {"", "1", "2", "12", "23", "123"};
    vector<string> s = letterCombinations("23");
    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
        if(i != s.size() - 1)   cout << ",";
    }   cout << endl;
    return 0;
}
