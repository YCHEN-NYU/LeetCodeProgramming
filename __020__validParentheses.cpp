/*
 20. Valid Parentheses
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 
 An input string is valid if:
 
 Open brackets must be closed by the same type of brackets.
 Open brackets must be closed in the correct order.
 Note that an empty string is also considered valid.
 
 Example 1:
 Input: "()"
 Output: true
 
 Example 2:
 Input: "()[]{}"
 Output: true
 
 Example 3:
 Input: "(]"
 Output: false
 
 Example 4:
 Input: "([)]"
 Output: false
 
 Example 5:
 Input: "{[]}"
 Output: true
 */

#include <iostream>
#include <stack>
#include <iomanip>
#include <vector>
using namespace std;

bool isValid(string s) {
    if(s.size() == 0) return true;
    stack<char> stk;
    for(char c : s){
        switch(c){
            case '(': stk.push(c); break;
            case '[': stk.push(c); break;
            case '{': stk.push(c); break;
            case ')': {
                if(!stk.empty() && stk.top() == '(') stk.pop();
                else return false;
                break;
            }
            case ']': {
                if(!stk.empty() && stk.top() == '[') stk.pop();
                else return false;
                break;
            }
            case '}': {
                if(!stk.empty() && stk.top() == '{') stk.pop();
                else return false;
                break;
            }
            default:
                return false;
                break;
    }
}
return stk.empty();
}


// bool isValid(string s){
//     if(s.size() == 0)   return true;
    
//     stack<char> stk;
    
//     for (int i = 0; i < s.size(); i++) {
//         switch (s[i]) {
//             case '(':
//                 stk.push(s[i]);
//                 break;
//             case '[':
//                 stk.push(s[i]);
//                 break;
//             case '{':
//                 stk.push(s[i]);
//                 break;
            
//             case ')':
//                 if(!stk.empty() && stk.top() == '(') stk.pop();
//                 else return false;
//                 break;
//             case ']':
//                 if(!stk.empty() && stk.top() == '[') stk.pop();
//                 else return false;
//                 break;
//             case '}':
//                 if(!stk.empty() && stk.top() == '{') stk.pop();
//                 else return false;
//                 break;
//             default:
//                 break;
//     }
// }

    return stk.empty();
}

int main(){
    vector<string> strList = {"()", "()[]{}", "(]", "([)]", "{[]}"};
    for (int i = 0; i < strList.size(); i++) {
        cout << strList[i] << " valid? " << boolalpha << isValid(strList[i]) << endl;
    }
}
