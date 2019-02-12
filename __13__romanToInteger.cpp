#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int romanToInt(string s) {
    if(s.size() == 0)   return 0;
    unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int num = roman[s[s.size() - 1]];
    
    for(int i = s.size() - 1; i > 0; i--){
        if(roman[s[i - 1]] >= roman[s[i]])
            num += roman[s[i - 1]];
        else
            num -= roman[s[i - 1]];
    }
    return num;
}

int main(){
    vector<string> strList = {"III", "IV", "IX", "LVIII", "MCMXCIV"};
    for (int i = 0; i < strList.size(); i++) {
        cout << strList[i] << " = " << romanToInt(strList[i]) << endl;
    }
    return 0;
}
