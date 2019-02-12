/*
 1.9 string rotateion. check if a string s2 is a rotation of s1.
 like waterbottle <-> erbottlewat
 isSubstr(s1 + s1, s2)
 */
#include <iostream>
#include <string>
using namespace std;


bool isSubstring(string s1, string s2){
    return s1.find(s2) != std::string::npos;
}

// check if s2 is a rotation of s1
bool isValidStringRotation(string s1, string s2){
    return isSubstring(s1 + s1, s2);
}

int main(){
    string s1 = "waterbottle", s2 = "erbottlewat";
    cout << boolalpha << s2 << " <-> " << s1
         << ": " << isValidStringRotation(s1, s2) << endl;
}

