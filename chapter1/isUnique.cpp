/*
 1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structure?
 */

#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

// use hashtable to store the counts of each characters in the string
bool is_unique_map(string s){
    map<char, int> char_count;
    for(int i = 0; i < s.size(); i++){
        if(char_count.find(s[i]) == char_count.end())
            char_count[s[i]] = 1;
        else{
            ++char_count[s[i]];
            if(char_count[s[i]] > 1) return false;
        }
    }
    return true;
}

/* do not use any additional data structure,
   look back of the substring.
*/
bool is_unique(string s){
    if(s.size() == 0) return false;
    
    for (int i = 1; i < s.size(); i++) {
        for(int j = 0; j < i - 1; j++){
            if(s[j] == s[i]) return false;
        }
    }
    return true;
}


int main() {
    cout << boolalpha << is_unique_map("abcd") << endl;
    cout << boolalpha << is_unique("abcd") << endl;
    
    cout << boolalpha << is_unique_map("hello") << endl;
    cout << boolalpha << is_unique("hello") << endl;
}
