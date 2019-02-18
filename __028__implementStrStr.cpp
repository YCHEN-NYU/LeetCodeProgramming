/*
 28. Implement strStr()
 Implement strStr().
  Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 
 Example 1:
 Input: haystack = "hello", needle = "ll"
 Output: 2
 
 Example 2:
Input: haystack = "aaaaa", needle = "bba"
 Output: -1
 */

#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle){
    int N = haystack.size(), n = needle.size();
    if(n == 0)  return 0;
    
    for (int i = 0; i < N; i++)
        if(haystack.substr(i, n) == needle) return i;
    
    return -1;
}


int main(){
    
}
