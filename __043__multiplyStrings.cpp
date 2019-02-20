/*
 43. Multiply Strings
 Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
  Example 1:
 Input: num1 = "2", num2 = "3"
 Output: "6"
 Example 2:
 Input: num1 = "123", num2 = "456"
 Output: "56088"
 Note:
 
 The length of both num1 and num2 is < 110.
 Both num1 and num2 contain only digits 0-9.
 Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 You must not use any built-in BigInteger library or convert the inputs to integer directly.
 
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string multiplyStrings(string &num1, string &num2){
    string product(num1.size() + num2.size(), '0');
    for (int i = num1.size() - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = num2.size() - 1; j >= 0; j--) {
            int temp = (product[i + j + 1] - '0') + (num1[i] - '0')*(num2[j] - '0') + carry;
            product[i + j + 1] = temp%10 + '0';
            carry = temp/10;
        }
        product[i] += carry;
    }
    
    int k = 0;
    for (; k < product.size(); k++) {
        if(product[k] != '0') break;
    }
    
    if(k < product.size())
        return product.substr(k, product.size() - k + 1);
    else
        return "0";
}



int main(){
    string num1 = "123", num2 = "456";
    cout << num1 << "x" << num2 << "=" << multiplyStrings(num1, num2) << endl;
    cout << num1 << "x" << num2 << "=" << stoi(num1)*stoi(num2) << endl;
}
