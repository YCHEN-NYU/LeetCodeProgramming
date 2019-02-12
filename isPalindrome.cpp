#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

bool isPalindrome(string &s){
    int low = 0, high = s.size() - 1;
    while(low < high){
        if(s[low] != s[high])   return false;
        else{
            low++;
            high--;
        }
    }
    return true;
}



int main(){
    vector<string> stringList = {"", "a", "aa", "ab", "aba"};
    for (int i = 0; i < stringList.size(); i++) {
        cout << boolalpha << isPalindrome(stringList[i]) << endl;
    }
    
}
