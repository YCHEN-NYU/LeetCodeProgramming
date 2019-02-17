/*
 6. ZigZag Conversion
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 
 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 
 Write the code that will take a string and make this conversion given a number of rows:
 
 string convert(string s, int numRows);
 Example 1:
 
 Input: s = "PAYPALISHIRING", numRows = 3
 Output: "PAHNAPLSIIGYIR"
 Example 2:
 
 Input: s = "PAYPALISHIRING", numRows = 4
 Output: "PINALSIGYAHRPI"
 Explanation:
 
 P     I    N
 A   L S  I G
 Y A   H R
 P     I
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string zigzagCovert(string s, int n){
    if(n <= 1) return s;
    string row[n]; // string array
    
    for(int i = 0; i < s.size(); i++){
        int index = i%(2*n - 2);
        if(index < n)   row[index] += s[i];
        else    row[n - 1 - (index - (n - 1))] += s[i];
    }
    
    string res = "";
    for(int i = 0; i < n; i++)
        res += row[i];
    return res;
}

int main(){
    string s = "PAYPALISHIRING";
    vector<int> rowList = {0, 1, 2, 3, 4};
    for (int i = 0; i < rowList.size(); i++) {
        cout << zigzagCovert(s, rowList[i]) << endl;
    }
    
}
