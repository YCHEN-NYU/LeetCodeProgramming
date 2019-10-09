/*
 22. Generate Parentheses
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 
 For example, given n = 3, a solution set is:
 [
 "((()))",
 "(()())",
 "(())()",
 "()(())",
 "()()()"
 ]
 */
#include <iostream>
#include <vector>
using namespace std;

// DFS
void helper(vector<string> &res, string tmp, int leftBracket, int rightBracket){
    if(leftBracket == 0 && rightBracket == 0){
        res.push_back(tmp);
        return;
    }
    if(rightBracket > 0) helper(res, tmp + ")", leftBracket, rightBracket - 1);
    if(leftBracket > 0) helper(res, tmp + "(", leftBracket - 1, rightBracket + 1);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string tmp = "";
    helper(res, tmp, n, 0);
    return res;
}

int main(){
    vector<string> s = generateParenthesis(3);
    
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }
}
