/*
 1.3 URLify.cpp
 created by yiyi on 9/9/18, modified on 12/02/18
 write a method to replace all spaces in a string with '%20'.
 assume the string has sufficient space at the end to hold additional characters
 you are given the true length of the string.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// count spaces in a string, except at the end of the string
// "abc cba  d    ", count_spaces = 3
int get_effective_spaces(string s){
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ') count++;
    }
    
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] != ' ') break;
        else {
            count--;
        }
    }
    return count;
}

// get the "true" length of a string, excluding any trailing spaces
// return [true_length,
vector<int> get_true_length(string s){
    vector<int> res;
    res.push_back(0);
    res.push_back(0);
    
    int spaces = 0;
    for (int i = s.size() - 1; i >= 0; i--){
        if(s[i] != ' '){
            res[0] = i + 1; break;
        }
    }
    
    for (int j = res[0] - 1; j >= 0; j--)
        if(s[j] == ' ') spaces++;
    
    res[1] = spaces;
    return res;
}

// replace spaces in a string with "%20"


int main() {
    
    string s = "iwi 71  o       ";
    vector<int> res = get_true_length(s);
    int true_length = res[0];
    int effective_spaces = res[1];
    
    cout << "true_length = " << true_length << endl;
    cout << "effective_spaces = " << effective_spaces << endl;
    
    int j = true_length - 1 + 2*effective_spaces;
    for(int i = true_length - 1; i >= 0; i--){
        if(s[i] == ' '){
            s[j] = '0';
            s[j - 1] = '2';
            s[j - 2] = '%';
            j -= 3;
        }
        else{
            s[j] = s[i];
            j--;
        }
    }
    cout << "s = " << s << endl;
}
