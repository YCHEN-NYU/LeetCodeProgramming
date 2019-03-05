/*
 166. Fraction to Recurring Decimal
 Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
 If the fractional part is repeating, enclose the repeating part in parentheses.
 
 Example 1:
 Input: numerator = 1, denominator = 2
 Output: "0.5"
 
 Example 2:
 Input: numerator = 2, denominator = 1
 Output: "2"
 
 Example 3:
 Input: numerator = 2, denominator = 3
 Output: "0.(6)"
 */

#include <iostream>
#include <cmath>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

// zero, negative, overflow
// integer part
// "." decimal part
// hashtable <int, index> to track if the remainder repeats itself
string fractionToDecimal(int numerator, int denominator) {
    if(numerator == 0)  return "0";
    string res = ((numerator > 0) ^ (denominator > 0)? "-" : "");
    
    long num = abs(long(numerator)), den = abs(long(denominator));
    
    // get the integer part
    if(num != 0){
        res += to_string(num/den);
        num %= den;
    }
    if(num == 0)    return res;
    
    // get the decimal part, <remainder, index>
    unordered_map<long, int> indexMap;
    int index = res.size() - 1;
    
    // add "."
    res += ".";
    index++;
    while(num != 0){
        num *= 10;
        if(indexMap.find(num) == indexMap.end()){
            indexMap[num] = index;
            res += to_string(num/den);
            num %= den;
            index++;
        }
        else{
            // find repetitive of remainder
            res.insert(res.begin() + indexMap[num] + 1, '(');
            res.insert(res.end(), ')');
            break;
        }
    }
    return res;
}

int main(){
    int numerator = -1, denominator = 7;
    string res = fractionToDecimal(numerator, denominator);
    
    cout << numerator << "/" << denominator << " = " << res << endl;
}
