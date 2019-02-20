/*
415. Add Strings
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
Seen this question in a real interview before?  YesNo
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
      int i = num1.size() - 1, j = num2.size() - 1;
      cout << "i = " << i << endl;
      cout << "j = " << j << endl;
      int carry = 0, sum =0;
      string res;
      while(i >= 0 || j >= 0 || carry != 0){
        sum = (i >= 0 ? int(num1[i] - '0') : 0) + (j >= 0? int(num2[j] - '0') : 0) + carry;
        res.insert(res.begin(), char(sum % 10 + '0'));
        carry = sum / 10;
        i--;
        j--;
      }
      return res;
    }
};