/*
 1.6 String Compression: Implement a method to perform string compression using the counts of repeated characters. For example, the string aabcccccaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, you method should return the original string. You can assume the string has only uppercase and lowercase letter (a-z).
 aabcccccaa
 */

#include <iostream>
using namespace std;

int main() {
    string S = "aabcccccaa";
    string res = "";
    int startIndex = 0;
    int i = 0;
    // compress string
    while(i < S.size()){
        if(S[i] != S[startIndex]){
            res.push_back(S[startIndex]);
            res.push_back((i - startIndex) + '0');
            startIndex = i;
        }
        i++;
    }
    // handle the tail of the string
    if(startIndex <= S.size() - 1){
        res.push_back(S[startIndex]);
        res.push_back((S.size() - startIndex) + '0');
    }
    
    // choose the valid output by comparing the size
    if(res.size() < S.size()) cout << res << endl;
    else cout << S << endl;
}
