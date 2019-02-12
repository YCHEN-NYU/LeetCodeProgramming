#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string &s, int low, int high){
    while(low < high){
        if(s[low] != s[high])   return false;
        else{
            low++;
            high--;
        }
    }
    
    return true;
}

void helper(string &s, int begin, vector<string> &tempList, vector<vector<string>> &res){
    if(begin == s.size()){
        res.push_back(tempList);
        return;
    }
    else{
        for (int i = begin; i < s.size(); i++) {
            
            if(isPalindrome(s, begin, i)){
                tempList.push_back(s.substr(begin, i - begin + 1));
                helper(s, i + 1, tempList, res);
                tempList.erase(tempList.end() - 1);
            }
        }
    }
}

vector<vector<string>> palindromePartition(string &s){
    vector<vector<string>> res;
    vector<string> tempList;
    helper(s, 0, tempList, res);
    return res;
}




int main(){
    string s = "aab";
    vector<vector<string>> stringList = palindromePartition(s);
    cout << "[";
    for (int i = 0; i < stringList.size(); i++) {
        cout << "[";
        for (int j = 0; j < stringList[i].size(); j++) {
            cout << "\"" << stringList[i][j] << "\"";
            if(j != stringList[i].size() - 1)   cout << ", ";
        }
        cout << "]";
        if(i != stringList.size() - 1)  cout << ", ";
    }
    cout << "]" << endl;
}
