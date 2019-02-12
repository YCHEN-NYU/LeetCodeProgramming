/*
题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;


vector<int> factorize(int num){
	vector<int> factorList;

	if(num < 1) {
		cerr << "Invalid Input!" << endl;
		return factorList;
	}
	
	if(num == 1){
		factorList.push_back(1);
		return factorList;
	}

	for(int i = 2; i*i <= num; i++){
		while(num % i == 0){
			factorList.push_back(i);
			num /= i;
		}
	}

	if(num != 1)	factorList.push_back(num);

	return factorList;
}



int main() {
	int num;
	cout << "num = ";

	if(!(cin >> num))
		cout << "Invalid input" << endl;
	else {
		vector<int> factorList = factorize(num);
		cout << num << " = ";
		for(int i = 0; i < factorList.size() - 1; i++){
			cout << factorList[i] << "*";
		}	cout << factorList[factorList.size() - 1] << endl;
	}

	return 0;
}
