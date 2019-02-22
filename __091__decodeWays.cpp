/*
 91. Decode Ways
 A message containing letters from A-Z is being encoded to numbers using the following mapping:
 
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given a non-empty string containing only digits, determine the total number of ways to decode it.
 
 Example 1:
 Input: "12"
 Output: 2
 Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 
 Example 2:
 Input: "226"
 Output: 3
 Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int numDecodings(string s){
    if(s.size() == 0)  return 0;
    
    int n = s.size();
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = (s[0] != '0'? 1 : 0);
    
    for(int i = 2; i <= n; i++){
        int first = stoi(s.substr(i - 1, 1));
        if(first >= 1 && first <= 9)
            dp[i] += dp[i - 1];

        int second = stoi(s.substr(i - 2, 2));
        if(second >= 10 && second <= 26)
            dp[i] += dp[i - 2];
    }
    return dp[n];
}

int main(){
    vector<string> strList = {"", "0", "1", "10", "12", "122", "226", "227"};
    for(auto str : strList){
        cout << "str = " << "\"" << str << "\"" << endl;
        cout << "# of decodings = " << numDecodings(str) << endl;
    }
    return 0;
}
