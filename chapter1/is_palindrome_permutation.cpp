/*
 1.4 check if a string is palindrome permutation
 */

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;

bool isPalindromePermutation(string s){
    map<char, int> char_count;
    
    for (int i = 0; i < s.size(); i++) {
        if(!isalpha(s[i])) continue;
        if(isupper(s[i])) s[i] = tolower(s[i]);
        
        if(char_count.find(s[i]) == char_count.end())
            char_count[s[i]] = 1;
        else
            ++char_count[s[i]];
    }
    
    int number_unpaired_char = 0;
    for(auto it = char_count.begin(); it != char_count.end(); it++){
        if(it->second % 2 != 0) ++number_unpaired_char;
    }
    
    return (number_unpaired_char <= 1);
}


int main(){
    string input_string = "Tact Coa";
    cout << boolalpha << isPalindromePermutation(input_string) << endl;
}
