/*
 1.5 One Edit Away
 There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit or zero edits away.
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
using namespace std;

/* abc: (0 edit) abc, (1 remove) ab, (1 replace) abx, (1 insert) abcx
 (1) ZERO EDIT          pale, pale -> true
 (2) ONE INSERT         pale, ple -> true    pales, pale -> true
 (3) ONE REPLACE        pale, bale -> true
 (4) TWO EDIT           pale, bake -> false
 */
bool oneEditReplace(string s1, string s2);
bool oneEditInsert(string s1, string s2);

bool isOneEditAway(string s1, string s2){
    if(s1.size() == s2.size())
        return oneEditReplace(s1, s2);
    else{
        if(s1.size() + 1 == s2.size())
            return oneEditInsert(s1, s2);
        else if(s2.size() + 1 == s1.size())
            return oneEditInsert(s2, s1);
    }
    return false;
}

// replace one character
bool oneEditReplace(string s1, string s2){
    bool foundDifference = false;
    for (int i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i]){
            if(foundDifference) return false;
        foundDifference = true;
        }
    }
    return true;
}

// s1.size() + 1 == s2.size()
bool oneEditInsert(string s1, string s2){
    int index1 = 0, index2 = 0;
    while (index1 < s1.size() && index2 < s2.size()) {
        if(s1[index1] != s2[index2]){
            if(index1 != index2)    return false;
            index2++;
        } else{
            index1++;
            index2++;
        }
    }
    return true;
}

int main() {
    vector<string> s1 = {"pale", "pales", "pale", "pale"}, s2 = {"ple", "pale", "bale", "bake"};
    for(int i = 0; i < s1.size(); i++){
        cout << s1[i] << " <-> " << s2[i] << " : ";
        cout << boolalpha << isOneEditAway(s1[i], s2[i]) << endl;
    }
}
