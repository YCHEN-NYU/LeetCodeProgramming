/*
题目：求 s=a+aa+aaa+aaaa+aa...a 的值，其中 a 是一个数字。例如
*/

#include <iostream>
using namespace std;

// 2 + 22 + 222 + 2222 + 22222
int repeat_sum(int a, int num){

	int sum = 0;
	int term = a;
	for(int i = 0; i < num; i++){
		sum += term;
		cout << term << ", ";
		
		term = term*10 + a;
	}	cout << endl;
	return sum;
}

int main() {
	int a;
	int num;

	cout << repeat_sum(1, 3) << endl;

}