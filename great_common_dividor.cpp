/* 
题目：输入两个正整数m和n，求其最大公约数和最小公倍数。
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> factorize(int num){
	vector<int> factorList;
	
	for(int i = 2; i*i <= num; i++){
		while(num % i == 0){
			factorList.push_back(i);
			num /= i;
		}
	}
	if(num != 1) factorList.push_back(num);
	
	return factorList;
}

int gcd_recursive(int a, int b){
	if(b == 0)
		return a;
	return gcd_recursive(b, a % b);
}


int gcd_iterative(int a, int b){
	while(b != 0){
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int gcd_factorize(int a, int b){
	int gcd = 1;
	vector<int> factorList = factorize(a);
	for(int i = 0; i < factorList.size(); i++){
		if(b % factorList[i] == 0){
			gcd *= factorList[i];
			b /= factorList[i];
		}
	}
	return gcd;
}


int main() {
	int a = 9, b = 6;
	cout << "Greatest common dividor: " << endl;
	cout << gcd_recursive(a, b) << endl;
	cout << gcd_iterative(a, b) << endl;
	cout << gcd_factorize(a, b) << endl;

	cout << "Least common multiple: " << endl;
	cout << a*b / gcd_recursive(a, b) << endl;
	cout << a*b / gcd_iterative(a, b) << endl;
	cout << a*b / gcd_factorize(a, b) << endl;

	return 0;
}



