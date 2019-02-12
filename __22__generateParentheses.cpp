//
//  __22__generateParentheses.cpp
//  
//
//  Created by yiyi on 1/30/19.
//

#include "__22__generateParentheses.hpp"
using namespace std;


/*
 Iterative method
 */
class Solution{
public:
    vector<string> generateParentheses(int n){
        vector<string> res;
        helper(res, "", n, 0);
        return res;
    }
    
    void helper(vector<string> &v, string str, int n, int m){
        if(n == 0 && m == 0){
            v.push_back(str);
            return ;
        }
        
        if(m > 0) helper(v, str + ")", n, m - 1);
        if(n > 0) helper(v, str + "(", n - 1, m + 1);
    }
    
    void printVector(vector<string> &strVector){
        for (int i = 0; i < strVector.size(); i++) {
            cout << strVector[i] << "\t";
        }   cout << endl;
    }
};



int main(){
    Solution test;
    vector<string> strVector;
    for (int i = 0; i < 4; i++) {
        strVector = test.generateParentheses(i);
        test.printVector(strVector);
    }
}
