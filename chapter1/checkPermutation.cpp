/*
 1.2 Check Permutation.
 Give two strings, write a method to decide if one is a permutation of the other.
 */

#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

// use hashtable
bool isPermutation(string s1, string s2){
    
    if(s1.size() != s2.size()) return false;
    
    map<char, int> char_count;
    for(int i = 0; i < s1.size(); i++){
        if(char_count.find(s1[i]) == char_count.end())
            char_count[s1[i]] = 1;
        else
            char_count[s1[i]]++;
        
//        if(char_count.find(s2[i]) == char_count.end())
//            char_count[s2[i]] = -1;
//        else
//            char_count[s2[i]]--;
    }
    
//    for(auto it = char_count.begin(); it != char_count.end(); it++)
//        if(it->second != 0) return false;
    for (int i = 0; i < s2.size(); i++) {
        char_count[s2[i]]--;
        if(char_count[s2[i]] < 0)
            return false;
    }
    
    return true;
}

// sort and compare
bool isPermutationSorting(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return (s1 == s2);
}


int main() {
    string s1 = "hello", s2 = "olleh";
//    cout << "s1 = "; cin >> s1;
//    cout << "s2 = "; cin >> s2;
    cout << "\"" << s1 << " is a permutation of " << s2 << "\" ? " << boolalpha << isPermutation(s1, s2) << endl;
    
    cout << "\"" << s1 << " is a permutation of " << s2 << "\" ? " << boolalpha << isPermutationSorting(s1, s2) << endl;
    
}
