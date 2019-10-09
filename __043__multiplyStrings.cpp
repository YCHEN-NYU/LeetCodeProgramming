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

string multiply(string num1, string num2) {
    int n = num1.size(), m = num2.size();
    // set up a container to store the data
    string product(n + m, '0');
    
    for(int i = n - 1; i >= 0; i--){
        int carry = 0; // reset carry
        for(int j = m - 1; j >= 0; j--){
            // add previous position [i + j + 1], current product and carry
            int sum = (product[i + j + 1] - '0') + (num1[i] - '0')*(num2[j] - '0') + carry;
            product[i + j + 1] = sum % 10 + '0';
            carry = sum/10;
        }
        product[i] += carry; // add the carry to product[i] -> highest digit of the string
    }
    
    // remove any leading zeros from the product
    int k = 0;
    for(; k < product.size(); k++){
        if(product[k] != '0')   break;
    }
    // k is the position of the first non-zero character, return the substring
    return product.substr(k) ;
}



int main(){
    string num1 = "123", num2 = "456";
    cout << num1 << "x" << num2 << "=" << multiplyStrings(num1, num2) << endl;
    cout << num1 << "x" << num2 << "=" << stoi(num1)*stoi(num2) << endl;
}
