/*
题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数.
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;


void count_characters(string s, map<string, int> &charMap){
	charMap["alphabet"] = 0;
	charMap["space"] = 0;
	charMap["digit"] = 0;
	charMap["others"] = 0;

	for(int i = 0; i < s.size(); i++){
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			charMap["alphabet"]++;
		
		else{
			if(s[i] == ' ')
				charMap["space"]++;
			
			else{
				if(s[i] >= '0' && s[i] <= '9')
					charMap["digit"]++;
				
				else
					charMap["others"]++;
			}
		} 
			
	}

}


int main() {
	string s;
	std::getline(cin, s);

	map<string, int> charMap;

	count_characters(s, charMap);

	for(auto it = charMap.begin(); it != charMap.end(); it++)
		cout << it->first << ": " << it->second << endl;

	return 0;

}