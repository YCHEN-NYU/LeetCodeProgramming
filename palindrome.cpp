/*
题目：一个5位数，判断它是不是回文数。即12321是回文数，个位与万位相同，
十位与千位相同。
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <string>
using namespace std;

// decompose a number into digits in reverse order
vector<int> decompose_digits(int number){
	vector<int> digits;

	while(number != 0){
		int digit = number%10;
		digits.push_back(digit);
		number /= 10;
	}
	return digits;
}

// isPalindrome
bool isPalindrome(vector<int> & digits){
	int N = digits.size();
	for(int i = 0; i < N/2; i++){
		if(digits[i] != digits[N - 1 - i])
			return false;
	}
	return true;
}

int main() {

	vector<int> digits = decompose_digits(1221);
	for(int i = 0; i < digits.size(); i++){
		cout << digits[i] << " ";
	}	cout << endl;

cout << boolalpha << isPalindrome(digits) << endl;


	return 0;

}