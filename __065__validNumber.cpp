/*
 65. Valid Number
 Validate if a given string can be interpreted as a decimal number.
 
 Some examples:
 "0" => true
 " 0.1 " => true
 "abc" => false
 "1 a" => false
 "2e10" => true
 " -90e3   " => true
 " 1e" => false
 "e3" => false
 " 6e-1" => true
 " 99e2.5 " => false
 "53.5e93" => true
 " --6 " => false
 "-+3" => false
 "95a54e53" => false
 
 Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:
 
 Numbers 0-9
 Exponent - "e"
 Positive/negative sign - "+"/"-"
 Decimal point - "."
 Of course, the context of these characters also matters in the input.
 
 Update (2015-02-10):
 The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
 */
#include <iostream>
#include <vector>
using namespace std;


bool isNumber(string str) {
    int state=0, flag=0; // flag to judge the special case "."
    while(str[0]==' ')  str.erase(0,1);//delete the  prefix whitespace
    while(str[str.length()-1]==' ') str.erase(str.length()-1, 1);//delete the suffix whitespace
    for(int i=0; i<str.length(); i++){
        if('0'<=str[i] && str[i]<='9'){
            flag=1;
            if(state<=2) state=2;
            else state=(state<=5)?5:7;
        }
        else if('+'==str[i] || '-'==str[i]){
            if(state==0 || state==3) state++;
            else return false;
        }
        else if('.'==str[i]){
            if(state<=2) state=6;
            else return false;
        }
        else if('e'==str[i]){
            if(flag&&(state==2 || state==6 || state==7)) state=3;
            else return false;
        }
        else return false;
    }
    return (state==2 || state==5 || (flag&&state==6) || state==7);
}


int main(){
    
}
