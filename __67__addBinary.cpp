/*
 67. Add Binary
 Given two binary strings, return their sum (also a binary string).
 
 The input strings are both non-empty and contains only characters 1 or 0.
 
 Example 1:
 
 Input: a = "11", b = "1"
 Output: "100"
 Example 2:
 
 Input: a = "1010", b = "1011"
 Output: "10101"
*/

#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b){
    string res = "";
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry == 1) {
        cout << "carry = " << carry << endl;
        carry += (i >= 0? a[i] - '0' : 0);
        carry += (j >= 0? b[j] - '0' : 0);
        res = (carry % 2 == 1? "1" : "0") + res;
        carry /= 2;
        i--; j--;
    }
    
    return res;
}

int main(){
    string a = "101", b = "11";
    cout << addBinary(a, b) << endl;
}
