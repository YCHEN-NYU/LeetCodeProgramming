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

void helper(vector<string> &v, string str, int n, int m){
    if(n == 0 && m == 0){
        v.push_back(str);
        return;
    }
    if(m > 0) helper(v, str + ")", n, m - 1);
    if(n > 0) helper(v, str + "(", n - 1, m + 1);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    helper(res, "", n, 0);
    return res;
}

int main(){
    vector<string> s = generateParenthesis(3);
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }
}
