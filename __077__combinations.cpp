/*
 77. Combinations
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 
 Example:
 Input: n = 4, k = 2
 Output:
 [
 [2,4],
 [3,4],
 [2,3],
 [1,2],
 [1,3],
 [1,4],
 ]
 */
#include <iostream>
#include <vector>
#include "printMatrix2D.h"
using namespace std;

void helper(int n, int k, int start, vector<int> &tmp, vector<vector<int>> &res){
    if(tmp.size() == k)
        res.push_back(tmp);
    else{
        for(int i = start; i <= n; i++){
            tmp.push_back(i);
            helper(n, k, i + 1, tmp, res);
            tmp.pop_back();
        }
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> tmp;
    helper(n, k, 1, tmp, res);
    return res;
}


int main(){
    vector<vector<int>> res = combine(4, 2);
    printMatrix2D(res);
}
